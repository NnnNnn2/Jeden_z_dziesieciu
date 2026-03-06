#define ILOSC_PYTAN_FINALOWYCH 40
#include "Gra.h"
#include <conio.h>

Gra::Gra(int iloscGraczy)
{
	this->gracze = new Gracze(iloscGraczy);
	this->pytania = new Pytania();
	this->gracze->WpiszGraczy();
	this->pytania->wczytajPytania();
	this->wyswietlacz = new Wyswietlacz(gracze);
	this->ostatni = -1;
	this->naSiebie = false;
	this->zglaszanie = true;
}

Gra::Gra(int iloscGraczy, std::string scierzka)
{
	this->gracze = new Gracze(iloscGraczy);
	this->pytania = new Pytania();
	this->gracze->WpiszGraczy();
	this->pytania->wczytajPytania(scierzka);
	this->wyswietlacz = new Wyswietlacz(gracze);
	this->ostatni = -1;
	this->naSiebie = false;
	this->zglaszanie = true;
}

Gracze* Gra::GetGracze()
{
	return this->gracze;
}

Pytania* Gra::GetPytania()
{
	return this->pytania;
}

Wyswietlacz* Gra::GetWyswietlacz()
{
	return this->wyswietlacz;
}

void Gra::Graj()
{
	int iloscGraczy = this->gracze->GetIlosc();
	int iloscPytan = this->pytania->GetIlosc();
	if (iloscGraczy > 0 && iloscPytan >= (iloscGraczy * 2 + ILOSC_PYTAN_FINALOWYCH))
	{
		this->runda = 1;
		this->Runda();
	}
}

void Gra::Czekaj()
{
	char znak = 0;
	
	while (znak != ' ')
	{
		znak = _getch();
		if (znak == 'j')
			zglaszanie = !zglaszanie;
	}
	return;
}

int Gra::wyborGracza(int aktywny)
{
	char znak = 0;
	bool brakSzans = true;
	int nrGracza;
	char literyNaCyfry[9] = { 'q','w','e','r','t','y','u','i','o' };
	if (aktywny == -1)
	{
		while (brakSzans)
		{
			znak = 0;
			this->naSiebie = false;
			while (znak < '1' || znak > '0' + gracze->GetIlosc())
			{
				znak = _getch();
				if (znak == 'l')
				{
					//pomin jak nikt sie nie zglosil
					return -1;
				}
				if (znak == '0' && gracze->GetIlosc() > 9)
				{
					znak = 58;
					break;
				}
 				if (znak == 's' && this->ostatni >= 0)
				{
					znak = this->ostatni + 49;
					this->naSiebie = true;
				}

				//wybor znaku q-p
				for (int i = 0; i < 10; i++)
				{
					if (znak == 'p' && gracze->GetIlosc() > 9 && zglaszanie)
						znak = 58;
					if (znak == literyNaCyfry[i] && zglaszanie)
						znak = (char)i + 49;
				}
			}
			nrGracza = (int)znak - 49;	//odejmujemy kod znaku '0' aby z char zrobiæ int
			if (this->gracze->GetGracz(nrGracza)->GetSzanse() > 0)
				brakSzans = false;
		}
		this->ostatni = nrGracza;
	}
	else			//w pierwszej rundzie kazdy gracz ma szanse
	{
		nrGracza = aktywny;
	}
	return nrGracza;
}

void Gra::PytanieS(int mnoznik, bool punkty, int aktywny)
{
	Pytanie* pytanie = this->pytania->GetLosowe();
	this->wyswietlacz->WypiszPytanie(pytanie, punkty, -1, zglaszanie);
	//wybor gracza
	int nrGracza = this->wyborGracza(aktywny);
	if (nrGracza == -1)
		return;
	
	this->wyswietlacz->WypiszPytanie(pytanie, punkty, nrGracza, zglaszanie);
	this->Czekaj();
	this->wyswietlacz->WypiszOdpowiedz(pytanie, punkty, nrGracza, zglaszanie);

	char znak = 0;
	bool ok = false;
	//dobrze / zle
	while (!ok)
	{
		while (znak != 'z' && znak != 'd' && znak != 'k')
			znak = _getch();
		//zle
		if (znak == 'z')
		{
			gracze->GetGracz(nrGracza)->DecSzanse();
			//2 zla odpowiedz w rundzie 1
			if (runda == 1 && gracze->GetGracz(nrGracza)->GetSzanse() == 1)
				gracze->GetGracz(nrGracza)->DecSzanse();
			ok = true;
		}
		//dobrze
		if (znak == 'd')
		{
			if (this->naSiebie)
				mnoznik *= 2;
			gracze->GetGracz(nrGracza)->IncPunkty(mnoznik);
			ok = true;
		}
		//ponownie wybierz gracza
 		if (znak == 'k')
		{
			znak = 0;
			nrGracza = this->wyborGracza(aktywny);
			if (nrGracza == -1)
				return;
			this->wyswietlacz->WypiszOdpowiedz(pytanie, punkty, nrGracza, zglaszanie);
		}
	}

	this->wyswietlacz->WypiszOdpowiedz(pytanie, punkty, nrGracza, zglaszanie);
}

void Gra::Runda()
{
	//Runda Pierwsza
	if (this->runda == 1)
	{
		this->wyswietlacz->WypiszRunde(runda);
		this->Czekaj();
		this->wyswietlacz->WypiszGraczy(false, -1, zglaszanie);
		for (int j = 0; j < 2; j++)
		{
			for (int i = 0; i < this->gracze->GetIlosc(); i++)
			{
				this->Czekaj();
				this->PytanieS(0, false, i);
			}
		}
		this->runda++;
	}
	//Runda Druga
	if (this->runda == 2)
	{
		this->wyswietlacz->WypiszRunde(runda);
		this->Czekaj();
		this->wyswietlacz->WypiszGraczy(false, -1, zglaszanie);
		//czy przejsc do finalu
		while (this->gracze->GetIloscAktywnych() > 3)
		{
			this->Czekaj();
			this->PytanieS(0, false, -1);
		}
		this->runda++;
	}
	//Final
	if (this->runda == 3)
	{
		this->ostatni = -1;
		this->gracze->Final();
		this->wyswietlacz->WypiszRunde(runda);
		this->Czekaj();
		this->wyswietlacz->WypiszGraczy(true, -1, zglaszanie);
		int zadanePytania = 0;
		while (this->gracze->GetIloscAktywnych() > 0 && zadanePytania < ILOSC_PYTAN_FINALOWYCH)
		{
			this->Czekaj();
			this->PytanieS(10, true, -1);
			zadanePytania++;
		}
		this->gracze->punktyZaSzanse(10);
		this->wyswietlacz->WypiszGraczy(true, -1, zglaszanie);
		_getch();
	}
}

Gra::~Gra()
{

}