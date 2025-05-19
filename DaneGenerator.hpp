#pragma once
#include <utility>

class DaneGenerator {
public:
    static int* generujLosoweKlucze(int rozmiar);
    static std::pair<int, int>* generujParyKluczWartosc(int rozmiar);

private:
    static void fisherYatesShuffle(int* tab, int rozmiar);
};
