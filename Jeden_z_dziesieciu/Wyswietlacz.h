#pragma once
#include "Gracze.h"
#include "Pytanie.h"

class Wyswietlacz
{
private:
	void WypiszGracza(Gracz* gracz, bool punkty);
	
	Gracze* gracze;
public:
	Wyswietlacz(Gracze* gracze);
	void WypiszGraczy(bool punkty);
	void WypiszPytanie(Pytanie* pytanie);
	void WypiszOdpowiedz(Pytanie* pytanie);
	~Wyswietlacz();

};