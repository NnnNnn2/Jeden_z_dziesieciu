#pragma once
#include <string>

class Gracz
{
private:
	int numer, punkty, szanse;
	std::string imie;

public:
	//Konstruktor
	Gracz(int numer, std::string imie);

	//GET
	int GetNumer();
	std::string GetImie();
	int GetPunkty();
	int GetSzanse();

	//SET
	void SetNumer(int numer);
	void SetPunty(int punkty);
	void SetSzanse(int szanse);

	void DecSzanse();
	void IncPunkty(int numer);
	void Wypisz();

	//Destruktor
	~Gracz();
};