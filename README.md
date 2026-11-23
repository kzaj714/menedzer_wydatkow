Menedzer wydatkow
Prosty program konsolowy w C++ do zarzadzania budzetem.
Funkcje:
- Dodawanie wydatkow i przychodow
- Wyswietlanie transakcji
- Wyszukiwanie po fragmencie opisu
- Edytowanie i usuwanie transakcji
- Obliczanie aktualnego salda
Klasy:
- Transakcja - klasa bazowa dla wydatkow i przychodow
- Wydatek - transakcja z kategoria, zmniejsza saldo
- Przychod - transakcja ze zrodlem, zwieksza saldo
- Budzet - przechowuje transakcje i oblicza saldo
Program wykorzystuje dziedziczenie, polimorfizm, enkapsulacje, przeciazanie operatorow i obsluge wyjatkow.
Kompilacja i uruchomienie:
1. Wejdz na https://www.onlinegdb.com/online_c++_compiler
2. Wybierz C++.
3. Dodaj pliki main.cpp, budzet.h i budzet.cpp do jednego projektu.
4. Kliknij Run - OnlineGDB skompiluje i uruchomi program.
Przyklad dzialania:
- Budzet poczatkowy: 1000 zl
- Dodany wydatek: Zakupy, 100 zl
- Dodany przychod: Wyplata, 2000 zl
- Aktualne saldo: 2900 zl
