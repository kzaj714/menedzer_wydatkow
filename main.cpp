#include "budzet.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;
int main() {
    Budzet b;
    double kwota;
    cout << fixed << setprecision(2);
    cout << "Budzet poczatkowy: ";
    if (!(cin >> kwota)) return 1;
    try { b.setPoczatek(kwota); }
    catch (const exception& e) { cout << e.what() << '\n'; return 1; }
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
                if (wybor == 1) b += new Wydatek(opis, kwota, szczegoly);
                else b += new Przychod(opis, kwota, szczegoly);
            }
            else if (wybor == 3) b.pokaz();
            else if (wybor == 4) {
                string opis;
                cout << "Szukany opis: ";
                getline(cin >> ws, opis);
                b.szukaj(opis);
            }
            else if (wybor == 5) {
                int nr;
                string opis;
                b.pokaz();
                cout << "Numer: ";
                if (!(cin >> nr)) return 1;
                cout << "Nowy opis: ";
                getline(cin >> ws, opis);
                cout << "Nowa kwota: ";
                if (!(cin >> kwota)) return 1;
                b.edytuj(nr, opis, kwota);
            }
            else if (wybor == 6) {
                int nr;
                b.pokaz();
                cout << "Numer: ";
                if (!(cin >> nr)) return 1;
                b -= nr;
            }
            else if (wybor == 7) {
                cout << "Budzet poczatkowy: " << b.getPoczatek() << " zl\n";
                cout << "Aktualne saldo: " << b.saldo() << " zl\n";
            }
            else cout << "Nie ma takiej opcji\n";
        }
        catch (const exception& e) { cout << "Blad: " << e.what() << '\n'; }
    }
}
