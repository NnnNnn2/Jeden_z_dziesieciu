#include "Pytania.h"
#include "fstream"
#include <iostream>

Pytania::Pytania() 
{
	this->i = 0;
}
void Pytania::addPytanie(std::string pytanie, std::string odpowiedz)
{
	Pytanie* temp = new Pytanie(pytanie, odpowiedz);
	this->pytania.push_back(temp);
}
void Pytania::wczytajPytania(std::string scierzka)
{
	std::ifstream pytania(scierzka);
	std::string tempPyt;
	std::string tempOdp;
	bool endOfFile = false;
	while (!endOfFile)
	{
		if (std::getline(pytania, tempPyt))
			if (std::getline(pytania, tempOdp))
				this->addPytanie(tempPyt, tempOdp);
			else endOfFile = true;
		else endOfFile = true;
	}

}
void Pytania::wczytajPytania()
{
	this->wczytajPytania("pytania.txt");
}
void Pytania::wypiszPytania()
{
	for (int i = 0; i < this->pytania.size(); i++)
	{
		std::cout << std::endl;
		this->pytania[i]->wypiszPytanie();
	}
}
int Pytania::GetIlosc()
{
	return pytania.size();
}
Pytania::~Pytania()
{
	
}

