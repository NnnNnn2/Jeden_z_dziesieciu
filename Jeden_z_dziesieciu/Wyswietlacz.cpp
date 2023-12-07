#define PRZERWA 15
#include "Wyswietlacz.h"
#include <iostream>

Wyswietlacz::Wyswietlacz(Gracze* gracze)
{
	this->gracze = gracze;
}

void Wyswietlacz::WypiszGracza(Gracz* gracz, bool punkty)
{
	std::cout << gracz->GetNumer() + 1 << ". " << gracz->GetImie();
	for (int i = 0; i < (PRZERWA - gracz->GetImie().length()); i++)
		std::cout << " ";
	if (punkty)
		std::cout << "\t" << gracz->GetPunkty();
	std::cout << "\t";
	for (int j = 0; j < gracz->GetSzanse(); j++)
		std::cout << "# ";
}
void Wyswietlacz::WypiszGraczy(bool punkty)
{
	for (int i = 0; i < 20; i++)
		std::cout << "\n";
	for (int i = 0; i < this->gracze->GetIlosc(); i+=2)
	{
		WypiszGracza(this->gracze->GetGracz(i), punkty);
		std::cout << "\t\t\t\t\t";
		if (i < this->gracze->GetIlosc() - 1)
		{
			WypiszGracza(this->gracze->GetGracz(i + 1), punkty);
			std::cout << "\n";
		}
	}
}
void WypiszPytanie(Pytanie* pytanie)
{

}

Wyswietlacz::~Wyswietlacz()
{

}