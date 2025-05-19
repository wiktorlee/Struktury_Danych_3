#ifndef TABLICA_DYNAMICZNA_HPP
#define TABLICA_DYNAMICZNA_HPP

enum Stan {
    PUSTY,
    ZAJETY,
    USUNIETY
};

struct Element {
    int klucz;
    int wartosc;
    Stan stan;

    Element() {
        stan = PUSTY;
    }
};

class TablicaDynamiczna {
private:
    Element* tablica;
    int rozmiar;
    int pojemnosc;

    int hash(int klucz) const;
    void powieksz();

public:
    TablicaDynamiczna();
    ~TablicaDynamiczna();

    void insert(int klucz, int wartosc);
    bool remove(int klucz);
};

#endif
