#include "ListaJednokierunkowa.hpp"
#include <iostream>

using namespace std;

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
    if (contains(klucz)) return;

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

bool ListaJednokierunkowa::contains(int klucz) const {
    Wezel* aktualny = head;
    while (aktualny != nullptr) {
        if (aktualny->dane.klucz == klucz) return true;
        aktualny = aktualny->next;
    }
    return false;
}

bool ListaJednokierunkowa::get(int klucz, int& wartosc) const {
    Wezel* aktualny = head;
    while (aktualny != nullptr) {
        if (aktualny->dane.klucz == klucz) {
            wartosc = aktualny->dane.wartosc;
            return true;
        }
        aktualny = aktualny->next;
    }
    return false;
}

void ListaJednokierunkowa::wyswietl() const {
    Wezel* aktualny = head;
    while (aktualny != nullptr) {
        cout << "(" << aktualny->dane.klucz << ", " << aktualny->dane.wartosc << ") ";
        aktualny = aktualny->next;
    }
    cout << endl;
}

int ListaJednokierunkowa::getSize() const {
    return rozmiar;
}

Wezel* ListaJednokierunkowa::getHead() const {
    return head;
}
