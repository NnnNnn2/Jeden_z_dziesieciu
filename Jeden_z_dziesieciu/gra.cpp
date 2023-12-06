#define ILOSC_PYTAN_FINALOWYCH 10
#include "Gra.h"

Gra::Gra(int iloscGraczy)
{
	this->gracze = new Gracze(iloscGraczy);
	this->pytania = new Pytania();
	this->gracze->WpiszGraczy();
	this->pytania->wczytajPytania();
}

Gra::Gra(int iloscGraczy, std::string scierzka)
{
	this->gracze = new Gracze(iloscGraczy);
	this->pytania = new Pytania();
	this->gracze->WpiszGraczy();
	this->pytania->wczytajPytania(scierzka);
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