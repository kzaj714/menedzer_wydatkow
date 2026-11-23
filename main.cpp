#include "budzet.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;
int main() {
    Budzet budzet;
    double kwota;
    cout << fixed << setprecision(2);
    cout << "Budzet poczatkowy: ";
    if (!(cin >> kwota)) return 1;
    // wym. 11 - try i catch przechwytuja wyjatki
    try { budzet.ustawPoczatek(kwota); }
    catch (const exception& blad) { cout << blad.what() << '\n'; return 1; }
    // Menu powtarza sie do wybrania opcji 0
    while (true) {
        int wybor;
        cout << "\n1. Dodaj wydatek\n2. Dodaj przychod\n3. Lista\n"
             << "4. Szukaj\n5. Edytuj\n6. Usun\n7. Saldo\n0. Koniec\nWybor: ";
        if (!(cin >> wybor) || wybor == 0) break;
        try {
            if (wybor == 1 || wybor == 2) {
                string opis, szczegoly;
                cout << "Opis: ";
                getline(cin >> ws, opis);
                cout << "Kwota: ";
                if (!(cin >> kwota)) return 1;
                cout << (wybor == 1 ? "Kategoria: " : "Zrodlo: ");
                getline(cin >> ws, szczegoly);
                // wym. 10 - Praktyczne wykorzystanie operatora +=
                if (wybor == 1) budzet += new Wydatek(opis, kwota, szczegoly);
                else budzet += new Przychod(opis, kwota, szczegoly);
            }
            else if (wybor == 3) budzet.pokaz();
            else if (wybor == 4) {
                string opis;
                cout << "Szukany opis: ";
                getline(cin >> ws, opis);
                budzet.szukaj(opis);
            }
            else if (wybor == 5) {
                int numer;
                string opis;
                budzet.pokaz();
                cout << "Numer: ";
                if (!(cin >> numer)) return 1;
                cout << "Nowy opis: ";
                getline(cin >> ws, opis);
                cout << "Nowa kwota: ";
                if (!(cin >> kwota)) return 1;
                budzet.edytuj(numer, opis, kwota);
            }
            else if (wybor == 6) {
                int numer;
                budzet.pokaz();
                cout << "Numer: ";
                if (!(cin >> numer)) return 1;
                // wym. 10 - Praktyczne wykorzystanie operatora -=
                budzet -= numer;
            }
            else if (wybor == 7) {
                cout << "Budzet poczatkowy: " << budzet.pobierzPoczatek() << " zl\n";
                cout << "Aktualne saldo: " << budzet.saldo() << " zl\n";
            }
            else cout << "Nie ma takiej opcji\n";
        }
        // wym. 11 - Przechwycenie bledu pozwala kontynuowac program
        catch (const exception& blad) { cout << "Blad: " << blad.what() << '\n'; }
    }
}
