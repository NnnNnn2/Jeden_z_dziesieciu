#pragma once
#include "Pytanie.h"
#include <string>
#include <vector>


class Pytania
{
private:
	std::vector<Pytanie*> pytania;
	std::vector<Pytanie*> niewykorzystane;

public:
	Pytania();
	void addPytanie(std::string pytanie, std::string odpowiedz);
	void wczytajPytania(std::string scierzka);
	void wczytajPytania();
	void wypiszPytania();
	Pytanie* GetLosowe();
	int GetIlosc();
	~Pytania();
};