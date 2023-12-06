#include "Pytanie.h"
#include <iostream>

Pytanie::Pytanie(std::string pytanie, std::string odpowiedz)
{
	this->pytanie = pytanie;
	this->odpowiedz = odpowiedz;
}

std::string Pytanie::GetPytanie()
{
	return this->pytanie;
}

std::string Pytanie::GetOdpowiedz()
{
	return this->odpowiedz;
}

void Pytanie::wypiszPytanie()
{
	std::cout << this->pytanie << "\nOdp: " << this->odpowiedz;
}