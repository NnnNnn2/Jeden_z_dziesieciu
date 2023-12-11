#include "Gracze.h"
#include <iostream>

Gracze::Gracze(int ilosc)
{
	this->ilosc = ilosc;
	this->gracze = new Gracz * [ilosc];
}

void Gracze::DodajGracza(int numer, std::string imie)
{
	Gracz* temp = new Gracz(numer, imie);
	this->gracze[numer] = temp;
}
Gracz* Gracze::GetGracz(int i)
{
	return this->gracze[i];
}
void Gracze::WpiszGraczy()
{
	for (int i = 0; i < ilosc; i++)
	{
		std::string imie;
		std::cout << "Podaj imie gracza nr. " << i + 1 << " : ";
		std::cin >> imie;
		this->DodajGracza(i, imie);
	}
}
void Gracze::WypiszGraczy()
{
	for (int i = 0; i < this->ilosc; i++)
	{
		gracze[i]->Wypisz();
		std::cout << std::endl;
	}
}

int Gracze::GetIlosc()
{
	return this->ilosc;
}

int Gracze::GetIloscAktywnych()
{
	int licznik = 0;
	for (int i = 0; i < this->ilosc; i++)
		if (this->gracze[i]->GetSzanse() > 0)
			licznik++;
	return licznik;
}

void Gracze::punktyZaSzanse(int mnorznik)
{
	for (int i = 0; i < this->ilosc; i++)
		if (this->gracze[i]->GetSzanse() > 0)
			this->gracze[i]->IncPunkty(this->gracze[i]->GetSzanse() * mnorznik);
}

void Gracze::Final()
{
	if (this->GetIloscAktywnych() == 3)
	{
		Gracz** temp = new Gracz * [3];
		int  j = 0;
		for (int i = 0; i < this->ilosc; i++)
		{
			if (this->gracze[i]->GetSzanse() > 0)
			{
				this->gracze[i]->IncPunkty(this->gracze[i]->GetSzanse());
				this->gracze[i]->SetNumer(j);
				this->gracze[i]->SetSzanse(3);
				temp[j] = this->gracze[i];
				j++;
			}
		}
		this->gracze = temp;
		this->ilosc = 3;
	}
}

Gracze::~Gracze()
{
	for (int i = 0; i < this->ilosc; i++)
	{
		delete this->gracze[i];
	}
	delete[] gracze;
}