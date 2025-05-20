#pragma once
#include "ListaJednokierunkowa.hpp"

class KubelkiJednokierunkowe {
private:
    ListaJednokierunkowa* tablica;
    int rozmiarTablicy;

    int hash(int klucz) const;

public:
    KubelkiJednokierunkowe(int rozmiar);
    ~KubelkiJednokierunkowe();

    void insert(int klucz, int wartosc);
    void remove(int klucz);
};
