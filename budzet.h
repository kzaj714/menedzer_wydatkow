#ifndef BUDZET_H
#define BUDZET_H
#include <string>
#include <vector>
using namespace std;
// wym. 1 - Klasa z atrybutami i metodami
class Transakcja {
    // wym. 2 - Pola prywatne, dostepne tylko wewnatrz klasy
private:
    string opis;
    double kwota;
public:
    // wym. 2 - Konstruktory domyslny i parametryczny
    Transakcja() : kwota(0) {}
    Transakcja(string opis, double kwota) : opis(opis), kwota(0) { ustawKwote(kwota); }
    virtual ~Transakcja() {}
    // wym. 3 - Enkapsulacja, pobieranie i zmiana prywatnych danych
    string pobierzOpis() const { return opis; }
    double pobierzKwote() const { return kwota; }
    void ustawOpis(string nowyOpis) { opis = nowyOpis; }
    void ustawKwote(double nowaKwota);
    // wym. 7 - Metody wirtualne do przeslaniania w klasach pochodnych
    virtual string typ() const = 0;
    virtual double wartosc() const = 0;
};
// wym. 5 - Dziedziczenie po klasie bazowej Transakcja
class Wydatek : public Transakcja {
    string kategoria;
public:
    // wym. 6 - Konstruktor klasy pochodnej
    Wydatek(string opis, double kwota, string kategoria) : Transakcja(opis, kwota), kategoria(kategoria) {}
    // wym. 7 - override przeslania metody wirtualne
    string typ() const override { return "Wydatek (" + kategoria + ")"; }
    double wartosc() const override { return -pobierzKwote(); }
};
class Przychod : public Transakcja {
    string zrodlo;
public:
    Przychod(string opis, double kwota, string zrodlo) : Transakcja(opis, kwota), zrodlo(zrodlo) {}
    string typ() const override { return "Przychod (" + zrodlo + ")"; }
    double wartosc() const override { return pobierzKwote(); }
};
// wym. 1 - Kolejna klasa z atrybutami i metodami
class Budzet {
    vector<Transakcja*> lista;
    double poczatek = 0;
public:
    Budzet() {}
    ~Budzet();
    void ustawPoczatek(double nowyPoczatek);
    double pobierzPoczatek() const { return poczatek; }
    // wym. 10 - Przeciazenie dwoch operatorow
    void operator+=(Transakcja* transakcja);
    void operator-=(int numer);
    // wym. 9 - Metody const nie zmieniaja danych obiektu
    void pokaz() const;
    void szukaj(string opis) const;
    void edytuj(int numer, string opis, double kwota);
    double saldo() const;
};
#endif
