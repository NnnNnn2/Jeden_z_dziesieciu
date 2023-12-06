#include "Pytania.h"
#include "fstream"
#include <iostream>
#include <cstdlib>

Pytania::Pytania() 
{

}
void Pytania::addPytanie(std::string pytanie, std::string odpowiedz)
{
	Pytanie* temp = new Pytanie(pytanie, odpowiedz);
	this->pytania.push_back(temp);
	this->niewykorzystane.push_back(temp);
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
		std::cout << "\n\n";
		this->pytania[i]->wypiszPytanie();
	}
}
Pytanie* Pytania::GetLosowe()
{
	srand((unsigned)time(NULL));
	int random = (rand() % this->GetIlosc());
	Pytanie* temp = this->niewykorzystane[random];
	this->niewykorzystane.erase(this->niewykorzystane.begin() + random);
	return temp;
}
int Pytania::GetIlosc()
{
	return niewykorzystane.size();
}
Pytania::~Pytania()
{
	
}

