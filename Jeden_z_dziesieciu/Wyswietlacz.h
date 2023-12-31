#pragma once
#include "Gracze.h"
#include "Pytanie.h"
#include "GUI.h"

class Wyswietlacz
{
private:
	void WypiszGracza(Gracz* gracz, bool punkty, bool aktywny);
	GUI* gui;
	Gracze* gracze;
public:
	Wyswietlacz(Gracze* gracze);
	void WypiszGraczy(bool punkty, int aktywny);
	void WypiszPytanie(Pytanie* pytanie, bool punkty, int aktywny);
	void WypiszOdpowiedz(Pytanie* pytanie, bool punkty, int aktywny);
	void WypiszRunde(int runda);
	GUI* GetGUI();
	~Wyswietlacz();

};