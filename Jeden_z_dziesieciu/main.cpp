#include "Gra.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Polish");
	int iloscGraczy;
	cout << "Podaj ilosc graczy: ";
	cin >> iloscGraczy;
	Gra* gra = new Gra(iloscGraczy, "test.txt");
	/*/Pytania* pytania = gra->GetPytania();
	system("cls");
	gra->GetGracze()->WypiszGraczy();
	//cout << "\n Pytania:";
	//pytania->wypiszPytania();
	int iloscPytan = pytania->GetIlosc();

	cout << iloscPytan;
	cout << "\n\nLosowe pytania: ";
	for (int i = 0; i < iloscPytan; i++)
	{
		cout << i;
		pytania->GetLosowe()->wypiszPytanie();
		cout << "\n\n";
	}	
	Pytanie* losowe = pytania->GetLosowe();
	gra->GetWyswietlacz()->WypiszPytanie(losowe, false,-1);
	char znak = _getch();
	gra->GetWyswietlacz()->WypiszOdpowiedz(losowe, false,3);
	while (true);*/
	gra->GetGracze()->GetGracz(1)->SetSzanse(0);
	gra->Graj();
	while (true);
	return 0;
}