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
	int ostatni;
	bool naSiebie;
	bool zglaszanie;
	void Czekaj();
	void PytanieS(int mnoznik, bool punkty, int aktywny);
	int wyborGracza(int aktywny);
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
