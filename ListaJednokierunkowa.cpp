#include "ListaJednokierunkowa.hpp"

ListaJednokierunkowa::ListaJednokierunkowa()
    : head(nullptr), tail(nullptr), rozmiar(0) {}

ListaJednokierunkowa::~ListaJednokierunkowa() {
    while (head != nullptr) {
        Wezel* temp = head;
        head = head->next;
        delete temp;
    }
}

void ListaJednokierunkowa::insert(int klucz, int wartosc) {
    Wezel* aktualny = head;
    while (aktualny != nullptr) {                               // przeszukanie liniowe czy klucz istnieje już w liście
        if (aktualny->dane.klucz == klucz) {
            aktualny->dane.wartosc = wartosc;                   // jeśli TAK: nadpisujemy
            return;
        }
        aktualny = aktualny->next;
    }

    ListaElement e(klucz, wartosc);
    Wezel* newWezel = new Wezel(e);

    if (head == nullptr) {
        head = tail = newWezel;
    } else {
        tail->next = newWezel;
        tail = newWezel;
    }

    rozmiar++;
}

void ListaJednokierunkowa::remove(int klucz) {
    if (head == nullptr) return;

    if (head->dane.klucz == klucz) {
        Wezel* temp = head;
        head = head->next;
        if (tail == temp) tail = nullptr;
        delete temp;
        rozmiar--;
        return;
    }

    Wezel* aktualny = head;
    while (aktualny->next != nullptr && aktualny->next->dane.klucz != klucz) {
        aktualny = aktualny->next;
    }

    if (aktualny->next != nullptr) {
        Wezel* doUsuniecia = aktualny->next;
        aktualny->next = doUsuniecia->next;
        if (doUsuniecia == tail) tail = aktualny;
        delete doUsuniecia;
        rozmiar--;
    }
}

int ListaJednokierunkowa::getSize() const {
    return rozmiar;
}

Wezel* ListaJednokierunkowa::getHead() const {
    return head;
}
