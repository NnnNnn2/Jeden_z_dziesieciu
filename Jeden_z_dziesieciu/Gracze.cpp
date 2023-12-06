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

Gracze::~Gracze()
{
	for (int i = 0; i < this->ilosc; i++)
	{
		delete this->gracze[i];
	}
	delete[] gracze;
}