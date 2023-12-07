#include <iostream>
#include "Gra.h"
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Polish");
	int iloscGraczy;
	cout << "Podaj ilosc graczy: ";
	cin >> iloscGraczy;
	Gra* gra = new Gra(iloscGraczy);
	Pytania* pytania = gra->GetPytania();
	system("cls");
	gra->GetGracze()->WypiszGraczy();
	//cout << "\n Pytania:";
	//pytania->wypiszPytania();
	int iloscPytan = pytania->GetIlosc();
	/*/
	cout << iloscPytan;
	cout << "\n\nLosowe pytania: ";
	for (int i = 0; i < iloscPytan; i++)
	{
		cout << i;
		pytania->GetLosowe()->wypiszPytanie();
		cout << "\n\n";
	}
	//*/
	gra->GetWyswietlacz()->WypiszGraczy(true);
	return 0;
}