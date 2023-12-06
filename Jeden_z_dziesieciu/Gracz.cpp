#pragma once
#include "Gracz.h"
#include <iostream>

//Konstruktor
Gracz::Gracz(int numer, std::string imie)
{
	this->numer = numer;
	this->imie = imie;
	this->punkty = 0;
	this->szanse = 3;
}


//GET
int Gracz::GetNumer()
{
	return this->numer;
}
std::string Gracz::GetImie()
{
	return this->imie;
}
int Gracz::GetPunkty()
{
	return this->punkty;
}
int Gracz::GetSzanse()
{
	return this->szanse;
}

//SET
void Gracz::SetNumer(int numer)
{
	this->numer = numer;
}
void Gracz::SetPunty(int punkty)
{
	this->punkty = punkty;
}
void Gracz::SetSzanse(int szanse)
{
	this->szanse = szanse;
}

void Gracz::DecSzanse()
{
	if (szanse > 0)
		szanse--;
}
void Gracz::IncPunkty()
{
	punkty++;
}
void Gracz::Wypisz()
{
	std::cout << "Gracz nr. " << this->numer + 1 << " szanse: " << this->szanse << " " << imie;
}


//Destruktor
Gracz::~Gracz()
{

}