#ifndef BUDZET_H
#define BUDZET_H
#include <string>
#include <vector>
using namespace std;
class Transakcja {
    string opis;
    double kwota;
public:
    Transakcja() : kwota(0) {}
    Transakcja(string o, double k) : opis(o), kwota(0) { setKwota(k); }
    virtual ~Transakcja() {}
    string getOpis() const { return opis; }
    double getKwota() const { return kwota; }
    void setOpis(string o) { opis = o; }
    void setKwota(double k);
    virtual string typ() const = 0;
    virtual double wartosc() const = 0;
};
class Wydatek : public Transakcja {
    string kategoria;
public:
    Wydatek(string o, double k, string kat) : Transakcja(o, k), kategoria(kat) {}
    string typ() const override { return "Wydatek (" + kategoria + ")"; }
    double wartosc() const override { return -getKwota(); }
};
class Przychod : public Transakcja {
    string zrodlo;
public:
    Przychod(string o, double k, string z) : Transakcja(o, k), zrodlo(z) {}
    string typ() const override { return "Przychod (" + zrodlo + ")"; }
    double wartosc() const override { return getKwota(); }
};
class Budzet {
    vector<Transakcja*> lista;
    double poczatek = 0;
public:
    Budzet() {}
    ~Budzet();
    void setPoczatek(double p);
    double getPoczatek() const { return poczatek; }
    void operator+=(Transakcja* t);
    void operator-=(int nr);
    void pokaz() const;
    void szukaj(string opis) const;
    void edytuj(int nr, string opis, double kwota);
    double saldo() const;
};
#endif
