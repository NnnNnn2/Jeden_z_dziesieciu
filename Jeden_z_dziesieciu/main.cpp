#include "Gra.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_CTYPE, "Polish");
    int iloscGraczy;
    const char* filename = (argc > 1) ? argv[1] : "pytania.txt";

    if (argc > 2) {
        iloscGraczy = atoi(argv[2]);
    } else {
        cout << "Podaj ilosc graczy: ";
        cin >> iloscGraczy;
    }

    Gra* gra = new Gra(iloscGraczy, filename);
    gra->Graj();
    return 0;
}