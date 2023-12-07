#pragma once
#include "Gracze.h"
#include "Pytania.h"
#include "Wyswietlacz.h"
#include <string>

class Gra
{
private:
	Pytania* pytania;
	Gracze* gracze;
	Wyswietlacz* wyswietlacz;
	int runda;
	void Czekaj();
	void PytanieS(int mnoznik, bool punkty);
	void Runda();

public:
	Gra(int iloscGraczy);
	Gra(int iloscGraczy, std::string scierzka);
	Gracze* GetGracze();
	Pytania* GetPytania();
	Wyswietlacz* GetWyswietlacz();
	void Graj();
	~Gra();
};
