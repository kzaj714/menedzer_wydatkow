#include "budzet.h"
#include <iostream>
#include <stdexcept>
using namespace std;
// wym. 11 - throw zglasza wyjatek przy niepoprawnej kwocie
void Transakcja::ustawKwote(double nowaKwota) {
    if (nowaKwota <= 0) throw invalid_argument("Kwota musi byc dodatnia");
    kwota = nowaKwota;
}
// Destruktor zwalnia pamiec zajeta przez transakcje
Budzet::~Budzet() {
    for (auto transakcja : lista) delete transakcja;
}
void Budzet::ustawPoczatek(double nowyPoczatek) {
    if (nowyPoczatek < 0) throw invalid_argument("Budzet nie moze byc ujemny");
    poczatek = nowyPoczatek;
}
// wym. 4 i 10 - Dodawanie i usuwanie za pomoca przeciazonych operatorow
void Budzet::operator+=(Transakcja* transakcja) {
    lista.push_back(transakcja);
}
void Budzet::operator-=(int numer) {
    if (numer < 1 || numer > (int)lista.size()) throw out_of_range("Nie ma takiego numeru");
    delete lista[numer - 1];
    lista.erase(lista.begin() + numer - 1);
}
void Budzet::pokaz() const {
    if (lista.empty()) cout << "Brak transakcji\n";
    for (int indeks = 0; indeks < (int)lista.size(); indeks++) {
        cout << indeks + 1 << ". " << lista[indeks]->typ() << " | "
             << lista[indeks]->pobierzOpis() << " | " << lista[indeks]->wartosc() << " zl\n";
    }
}
// wym. 4 - Wyszukiwanie po dowolnym fragmencie opisu
void Budzet::szukaj(string opis) const {
    bool znaleziono = false;
    for (auto transakcja : lista) {
        if (transakcja->pobierzOpis().find(opis) != string::npos) {
            cout << transakcja->typ() << " | " << transakcja->pobierzOpis() << " | " << transakcja->wartosc() << " zl\n";
            znaleziono = true;
        }
    }
    if (!znaleziono) cout << "Nie znaleziono\n";
}
// wym. 4 - Modyfikacja opisu i kwoty transakcji
void Budzet::edytuj(int numer, string opis, double kwota) {
    if (numer < 1 || numer > (int)lista.size()) throw out_of_range("Nie ma takiego numeru");
    lista[numer - 1]->ustawKwote(kwota);
    lista[numer - 1]->ustawOpis(opis);
}
// wym. 8 - Polimorfizm, wartosc() inaczej dziala dla wydatku i przychodu
double Budzet::saldo() const {
    double wynik = poczatek;
    for (auto transakcja : lista) wynik += transakcja->wartosc();
    return wynik;
}
