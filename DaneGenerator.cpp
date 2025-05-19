#include "DaneGenerator.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int* DaneGenerator::generujLosoweKlucze(int rozmiar) {
    int* tab = new int[rozmiar];
    for (int i = 0; i < rozmiar; i++)
        tab[i] = i;

    fisherYatesShuffle(tab, rozmiar);
    return tab;
}

pair<int, int>* DaneGenerator::generujParyKluczWartosc(int rozmiar) {
    int* klucze = generujLosoweKlucze(rozmiar);
    pair<int, int>* pary = new pair<int, int>[rozmiar];

    for (int i = 0; i < rozmiar; ++i) {
        pary[i] = {klucze[i], klucze[i]};
    }

    delete[] klucze;
    return pary;
}

void DaneGenerator::fisherYatesShuffle(int* tab, int rozmiar) {
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = rozmiar - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(tab[i], tab[j]);
    }
}
