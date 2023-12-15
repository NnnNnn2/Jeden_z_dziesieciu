#pragma once
#include "Gracze.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class GUI
{
private:
	sf::RenderWindow okno;
	int szerokoscOkna, wysokoscOkna;
	void WypiszGracza(Gracz* gracz, bool punkty, bool aktywny, int posX, int posY);
public:
	GUI(int szerokoscOkna, int wysokoscOkna);
	void WypiszGraczy(bool punkty, int aktywny, Gracze* gracze);
	void WypiszRunde(int runda);
	~GUI();
};