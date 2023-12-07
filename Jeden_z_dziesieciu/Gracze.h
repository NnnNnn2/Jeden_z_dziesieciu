#pragma once
#include "Gracz.h"

class Gracze
{
private:
	int ilosc;
	Gracz** gracze;
	void DodajGracza(int numer, std::string imie);

public:
	//Konstruktor
	Gracze(int ilosc);

	//GET
	Gracz* GetGracz(int numer);
	void WpiszGraczy();
	void WypiszGraczy();
	int GetIlosc();
	int GetIloscAktywnych();

	//Destruktor
	~Gracze();
};