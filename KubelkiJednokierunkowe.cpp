#include "KubelkiJednokierunkowe.hpp"

KubelkiJednokierunkowe::KubelkiJednokierunkowe(int rozmiar) {
    rozmiarTablicy = rozmiar;
    tablica = new ListaJednokierunkowa[rozmiarTablicy];                 // tworzenie tablicy kubełków; każdy kubełek to osobna lista jednokierunkowa
}

KubelkiJednokierunkowe::~KubelkiJednokierunkowe() {
    delete[] tablica;
}

int KubelkiJednokierunkowe::hash(int klucz) const {
    return klucz % rozmiarTablicy;                                      // prosta funkcja haszujaca modulo
}

void KubelkiJednokierunkowe::insert(int klucz, int wartosc) {
    int indeks = hash(klucz);
    tablica[indeks].insert(klucz, wartosc);
}

void KubelkiJednokierunkowe::remove(int klucz) {
    int indeks = hash(klucz);
    tablica[indeks].remove(klucz);
}

