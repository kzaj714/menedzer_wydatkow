
#include "budzet.h"
#include <iostream>
#include <stdexcept>
using namespace std;
void Transakcja::setKwota(double k) {
    if (k <= 0) throw invalid_argument("Kwota musi byc dodatnia");
    kwota = k;
}
Budzet::~Budzet() {
    for (auto t : lista) delete t;
}
void Budzet::setPoczatek(double p) {
    if (p < 0) throw invalid_argument("Budzet nie moze byc ujemny");
    poczatek = p;
}
void Budzet::operator+=(Transakcja* t) {
    lista.push_back(t);
}
void Budzet::operator-=(int nr) {
    if (nr < 1 || nr > (int)lista.size()) throw out_of_range("Nie ma takiego numeru");
    delete lista[nr - 1];
    lista.erase(lista.begin() + nr - 1);
}
void Budzet::pokaz() const {
    if (lista.empty()) cout << "Brak transakcji\n";
    for (int i = 0; i < (int)lista.size(); i++) {
        cout << i + 1 << ". " << lista[i]->typ() << " | "
             << lista[i]->getOpis() << " | " << lista[i]->wartosc() << " zl\n";
    }
}
void Budzet::szukaj(string opis) const {
    bool znaleziono = false;
    for (auto t : lista) {
        if (t->getOpis().find(opis) != string::npos) {
            cout << t->typ() << " | " << t->getOpis() << " | " << t->wartosc() << " zl\n";
            znaleziono = true;
        }
    }
    if (!znaleziono) cout << "Nie znaleziono\n";
}
void Budzet::edytuj(int nr, string opis, double kwota) {
    if (nr < 1 || nr > (int)lista.size()) throw out_of_range("Nie ma takiego numeru");
    lista[nr - 1]->setKwota(kwota);
    lista[nr - 1]->setOpis(opis);
}
double Budzet::saldo() const {
    double wynik = poczatek;
    for (auto t : lista) wynik += t->wartosc();
    return wynik;
}
