#pragma once
#include <iostream>

struct ListaElement {
    int klucz;
    int wartosc;

    ListaElement(int k = 0, int w = 0) : klucz(k), wartosc(w) {}
};

struct Wezel {
    ListaElement dane;
    Wezel* next;

    Wezel(const ListaElement& e) : dane(e), next(nullptr) {}
};

class ListaJednokierunkowa {
private:
    Wezel* head;
    Wezel* tail;
    int rozmiar;

public:
    ListaJednokierunkowa();
    ~ListaJednokierunkowa();

    void insert(int klucz, int wartosc);
    void remove(int klucz);

    bool contains(int klucz) const;
    bool get(int klucz, int& wartosc) const;

    void wyswietl() const;
    int getSize() const;

    Wezel* getHead() const;
};
