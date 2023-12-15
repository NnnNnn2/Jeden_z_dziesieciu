#define PRZERWA 15
#define SZEROKOSC_OKNA 1280
#define WYSOKOSC_OKNA 720
#include "Wyswietlacz.h"
#include <iostream>

Wyswietlacz::Wyswietlacz(Gracze* gracze)
{
	this->gracze = gracze;
	this->gui = new GUI(SZEROKOSC_OKNA, WYSOKOSC_OKNA);
}

void Wyswietlacz::WypiszGracza(Gracz* gracz, bool punkty, bool aktywny)
{
	std::string imie;
	if (aktywny)
		imie = "[ " + gracz->GetImie() + " ]";
	else
		imie = gracz->GetImie();
	std::cout << gracz->GetNumer() + 1 << ". " << imie;
	for (int i = 0; i < (PRZERWA - imie.length()); i++)
		std::cout << " ";
	if (punkty)
		std::cout << "\t" << gracz->GetPunkty();
	std::cout << "\t";
	for (int j = 0; j < gracz->GetSzanse(); j++)
		std::cout << "# ";
}
void Wyswietlacz::WypiszGraczy(bool punkty, int aktywny)
{
	for (int i = 0; i < 20; i++)
		std::cout << "\n";
	for (int i = 0; i < this->gracze->GetIlosc(); i+=2)
	{
		bool czyAktywny = (i == aktywny);
		WypiszGracza(this->gracze->GetGracz(i), punkty, czyAktywny);
		std::cout << "\t\t\t\t\t";
		if (i < this->gracze->GetIlosc() - 1)
		{
			czyAktywny = (i + 1 == aktywny);
			WypiszGracza(this->gracze->GetGracz(i + 1), punkty,czyAktywny);
			std::cout << "\n";
		}
	}
}
void Wyswietlacz::WypiszPytanie(Pytanie* pytanie, bool punkty, int aktywny)
{
	system("cls");
	std::cout << pytanie->GetPytanie() << "\n\n";
	this->WypiszGraczy(punkty, aktywny);
}
void Wyswietlacz::WypiszOdpowiedz(Pytanie* pytanie, bool punkty, int aktywny)
{
	system("cls");
	std::cout << pytanie->GetPytanie() << "\n\nODPOWIED: " << pytanie->GetOdpowiedz();
	this->WypiszGraczy(punkty, aktywny);
}
void Wyswietlacz::WypiszRunde(int runda)
{
	system("cls");
	if (runda != 3)
		std::cout << "RUNDA " << runda;
	else
		std::cout << "FINA£!";
}
GUI* Wyswietlacz::GetGUI()
{
	return this->gui;
}

Wyswietlacz::~Wyswietlacz()
{

}