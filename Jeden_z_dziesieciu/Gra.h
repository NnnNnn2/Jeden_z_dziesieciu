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

public:
	Gra(int iloscGraczy);
	Gra(int iloscGraczy, std::string scierzka);
	Gracze* GetGracze();
	Pytania* GetPytania();
	void Graj();
	~Gra();
};
