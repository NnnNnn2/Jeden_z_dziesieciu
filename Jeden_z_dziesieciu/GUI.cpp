#define KOLOR_RAMKI 0x121414FF
#define KOLOR_GRACZA 0x0236FCFF
#define KOLOR_AKTYWNEGO 0x05A9EAFF
#define KOLOR_PRZEGRANEGO 0x1638FB20
#define KOLOR_SZANSY 0xFFA404FF
#define KOLOR_TEKSTU 0xFFFFFFFF

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
	sf::Font czcionka;
	if (czcionka.loadFromFile("impact.ttf"))
	{
		sf::Text tekst;
		int rozmImie = (wysokosc - wysSzansy) / 3 - 4;
		int rozmNum = (wysokosc - wysSzansy) / 3 * 2 - 4;
		tekst.setFont(czcionka);
		//imiona
		tekst.setString(gracz->GetImie());
		tekst.setCharacterSize(rozmImie);
		tekst.setFillColor(sf::Color(KOLOR_TEKSTU));
		sf::FloatRect ramkaTekstu = tekst.getLocalBounds();
		tekst.setOrigin(ramkaTekstu.left + ramkaTekstu.width / 2.0f,
			ramkaTekstu.top + ramkaTekstu.height / 2.0f);
		int posTekstuX = posX + szerokosc / 2;
		int posTekstuY = posY + rozmImie / 2 + 2;
		tekst.setPosition(sf::Vector2f((float)posTekstuX, (float)posTekstuY));
		okno.draw(tekst);
		//numery/punkty
		int numer;
		if (punkty)
			numer = gracz->GetPunkty();
		else
			numer = gracz->GetNumer() + 1;
		tekst.setString(std::to_string(numer));
		tekst.setCharacterSize(rozmNum);
		ramkaTekstu = tekst.getLocalBounds();
		tekst.setOrigin(ramkaTekstu.left + ramkaTekstu.width / 2.0f,
			ramkaTekstu.top + ramkaTekstu.height / 2.0f);
		posTekstuX = posX + szerokosc / 2;
		posTekstuY = posY + rozmNum / 2 + rozmImie + 4;
		tekst.setPosition(sf::Vector2f((float)posTekstuX, (float)posTekstuY));
		okno.draw(tekst);
	}
}

void GUI::WypiszGraczy(bool punkty, int aktywny, Gracze* gracze)
{
	okno.clear(sf::Color::Black);
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

void GUI::WypiszRunde(int runda)
{
	okno.clear();
	sf::Font czcionka;
	if (czcionka.loadFromFile("impact.ttf"))
	{
		sf::Text tekst;
		tekst.setFont(czcionka);
		tekst.setFillColor(sf::Color(KOLOR_TEKSTU));
		std::string tekstRundy;
		if (runda < 3)
			tekstRundy = "Runda " + std::to_string(runda);
		else
			tekstRundy = "FINA£";
		tekst.setString(tekstRundy);
		sf::FloatRect ramkaTekstu = tekst.getLocalBounds();
		tekst.setOrigin(ramkaTekstu.left + ramkaTekstu.width / 2.0f,
			ramkaTekstu.top + ramkaTekstu.height / 2.0f);
		tekst.setPosition(sf::Vector2f((szerokoscOkna / 2.0f), (wysokoscOkna / 2.0f)));
		tekst.setCharacterSize(wysokoscOkna / 5);
		okno.draw(tekst);
		okno.display();
	}
}