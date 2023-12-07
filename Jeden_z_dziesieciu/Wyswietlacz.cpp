#include "Wyswietlacz.h"
#include <iostream>

Wyswietlacz::Wyswietlacz(Gracze* gracze)
{
	this->gracze = gracze;
}

void Wyswietlacz::WypiszGracza(Gracz* gracz, bool punkty)
{
	std::cout << gracz->GetNumer() << ". " << gracz->GetImie();
	if (punkty)
		std::cout << "\t" << gracz->GetPunkty();
	std::cout << "\t";
	for (int j = 0; j < gracz->GetSzanse(); j++)
		std::cout << (char)219 << " ";
}
void Wyswietlacz::WypiszGraczy(bool punkty)
{
	for (int i = 0; i < this->gracze->GetIlosc() / 2; i++)
	{
		WypiszGracza(this->gracze->GetGracz(i), punkty);
		std::cout << "\t\t\t\t\t";
		WypiszGracza(this->gracze->GetGracz(i+1), punkty);
	}
}
void WypiszPytanie(Pytanie* pytanie)
{

}

Wyswietlacz::~Wyswietlacz()
{

}