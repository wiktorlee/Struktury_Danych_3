#include "TablicaDynamiczna.hpp"

TablicaDynamiczna::TablicaDynamiczna() {
    pojemnosc = 10;
    rozmiar = 0;
    tablica = new Element[pojemnosc];
}

TablicaDynamiczna::~TablicaDynamiczna() {
    delete[] tablica;
}

int TablicaDynamiczna::hash(int klucz) const {
    return klucz % pojemnosc;
}

void TablicaDynamiczna::powieksz() {
    int staraPojemnosc = pojemnosc;
    Element* staraTablica = tablica;

    pojemnosc *= 2;
    tablica = new Element[pojemnosc];
    rozmiar = 0;

    for (int i = 0; i < staraPojemnosc; ++i) {
        if (staraTablica[i].stan == ZAJETY) {
            insert(staraTablica[i].klucz, staraTablica[i].wartosc);
        }
    }

    delete[] staraTablica;
}

void TablicaDynamiczna::insert(int klucz, int wartosc) {
    if ((rozmiar + 1) * 1.0 / pojemnosc > 0.7) {
        powieksz();
    }

    int indeks = hash(klucz);

    for (int i = 0; i < pojemnosc; ++i) {
        int probe = (indeks + i) % pojemnosc;

        if (tablica[probe].stan == PUSTY || tablica[probe].stan == USUNIETY) {
            tablica[probe].klucz = klucz;
            tablica[probe].wartosc = wartosc;
            tablica[probe].stan = ZAJETY;
            rozmiar++;
            return;
        }

        if (tablica[probe].stan == ZAJETY && tablica[probe].klucz == klucz) {
            tablica[probe].wartosc = wartosc;
            return;
        }
    }
}

bool TablicaDynamiczna::remove(int klucz) {
    int indeks = hash(klucz);

    for (int i = 0; i < pojemnosc; ++i) {
        int probe = (indeks + i) % pojemnosc;

        if (tablica[probe].stan == PUSTY) {
            return false;
        }

        if (tablica[probe].stan == ZAJETY && tablica[probe].klucz == klucz) {
            tablica[probe].stan = USUNIETY;
            rozmiar--;
            return true;
        }
    }

    return false;
}
