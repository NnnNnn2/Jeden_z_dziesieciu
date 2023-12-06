#pragma once
#include <string>

class Pytanie
{
private:
	std::string pytanie;
	std::string odpowiedz;
public:
	Pytanie(std::string pytanie, std::string odpowiedz);
	std::string GetPytanie();
	std::string GetOdpowiedz();
	void wypiszPytanie();
	~Pytanie();
};