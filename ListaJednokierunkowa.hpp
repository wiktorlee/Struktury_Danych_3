#pragma once

struct ListaElement {
    int klucz;
    int wartosc;
    ListaElement(int k, int v) : klucz(k), wartosc(v) {}
};

struct Wezel {
    ListaElement dane;
    Wezel* next;
    Wezel(ListaElement d) : dane(d), next(nullptr) {}
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

    int getSize() const;
    Wezel* getHead() const;
};
