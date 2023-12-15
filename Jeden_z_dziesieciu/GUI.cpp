#define KOLOR_RAMKI 0x121414FF
#define KOLOR_GRACZA 0x0236FCFF
#define KOLOR_AKTYWNEGO 0x05A9EAFF
#define KOLOR_PRZEGRANEGO 0x1638FB20
#define KOLOR_SZANSY 0xFFA404FF

#include "GUI.h"

GUI::GUI(int szerokoscOkna, int wysokoscOkna)
{
	this->okno.create(sf::VideoMode(szerokoscOkna, wysokoscOkna), "Jeden z Dziesieciu");
	this->szerokoscOkna = szerokoscOkna;
	this->wysokoscOkna = wysokoscOkna;
}

void GUI::WypiszGracza(Gracz* gracz, bool punkty, bool aktywny, int posX, int posY)
{
	/*TABLICE
	/________________
	/ || || || || ||
	/
	/ || || || || ||
	/----------------
	*/
	int szerokosc = szerokoscOkna / 8;
	int wysokosc = wysokoscOkna / 3;
	int szerSzansy = szerokosc / 7;
	int wysSzansy = 2 * wysokosc / 3;
	sf::RectangleShape tablica(sf::Vector2f((float)szerokosc, (float)wysokosc));
	tablica.setPosition(sf::Vector2f((float)posX, (float)posY));
	if (gracz->GetSzanse() > 0)
	{
		if (aktywny)
			tablica.setFillColor(sf::Color(KOLOR_AKTYWNEGO));
		else
			tablica.setFillColor(sf::Color(KOLOR_GRACZA));
	}
	else
		tablica.setFillColor(sf::Color(KOLOR_PRZEGRANEGO));
	tablica.setOutlineColor(sf::Color(KOLOR_RAMKI));
	tablica.setOutlineThickness(5.0f);
	okno.draw(tablica);

	//SZANSE
	sf::RectangleShape szansa(sf::Vector2f((float)szerSzansy, (float)wysSzansy));
	szansa.setFillColor(sf::Color(KOLOR_SZANSY));
	for (int i = 0; i < gracz->GetSzanse(); i++)
	{	
		int posSzansyX = posX + (2 * i + 1) * szerSzansy;
		int posSzansyY = posY + wysokosc - wysSzansy;
		szansa.setPosition(sf::Vector2f((float)posSzansyX, (float)posSzansyY));
		okno.draw(szansa);
	}

	//NAPISY

}

void GUI::WypiszGraczy(bool punkty, int aktywny, Gracze* gracze)
{
	int odstep = szerokoscOkna / 16;
	int posX, posY;
	for (int i = 0; i < gracze->GetIlosc(); i++)
	{
		if (i > 4)
		{
			posX = (3 * i + 2) * odstep - szerokoscOkna;
			posY = 2 * wysokoscOkna / 3;
		}
		else
		{
			posX = (3 * i + 1) * odstep;
			posY = 0;
		}
		bool czyAktywny = (i == aktywny);
		this->WypiszGracza(gracze->GetGracz(i), punkty, czyAktywny, posX, posY);
	}
	okno.display();
}