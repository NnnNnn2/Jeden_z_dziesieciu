#define ILOSC_PYTAN_FINALOWYCH 10
#include "Gra.h"

Gra::Gra(int iloscGraczy)
{
	this->gracze = new Gracze(iloscGraczy);
	this->pytania = new Pytania();
	this->gracze->WpiszGraczy();
	this->pytania->wczytajPytania();
	this->wyswietlacz = new Wyswietlacz(gracze);
}

Gra::Gra(int iloscGraczy, std::string scierzka)
{
	this->gracze = new Gracze(iloscGraczy);
	this->pytania = new Pytania();
	this->gracze->WpiszGraczy();
	this->pytania->wczytajPytania(scierzka);
	this->wyswietlacz = new Wyswietlacz(gracze);
}

Gracze* Gra::GetGracze()
{
	return this->gracze;
}

Pytania* Gra::GetPytania()
{
	return this->pytania;
}

void Gra::Graj()
{
	this->runda = 1;
	int iloscGraczy = this->gracze->GetIlosc();
	int iloscPytan = this->pytania->GetIlosc();
	if (iloscGraczy > 0 && iloscPytan >= (iloscGraczy * 2 + ILOSC_PYTAN_FINALOWYCH))
	{

	}
}

Gra::~Gra()
{

}