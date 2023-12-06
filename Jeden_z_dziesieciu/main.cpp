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
	system("cls");
	gra->GetGracze()->WypiszGraczy();
	cout << "\n Pytania:";
	gra->GetPytania()->wypiszPytania();
	return 0;
}