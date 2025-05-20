#include "KubelkiJednokierunkowe.hpp"

KubelkiJednokierunkowe::KubelkiJednokierunkowe(int rozmiar) {
    rozmiarTablicy = rozmiar;
    tablica = new ListaJednokierunkowa[rozmiarTablicy];
}

KubelkiJednokierunkowe::~KubelkiJednokierunkowe() {
    delete[] tablica;
}

int KubelkiJednokierunkowe::hash(int klucz) const {
    return klucz % rozmiarTablicy;
}

void KubelkiJednokierunkowe::insert(int klucz, int wartosc) {
    int indeks = hash(klucz);
    tablica[indeks].insert(klucz, wartosc);
}

void KubelkiJednokierunkowe::remove(int klucz) {
    int indeks = hash(klucz);
    tablica[indeks].remove(klucz);
}

