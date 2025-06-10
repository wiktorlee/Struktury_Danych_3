#ifndef HASHTABLE_AVL_H
#define HASHTABLE_AVL_H

#include <vector>
#include "AVLTree.h"

/// @brief Klasa implementująca słownik (mapę) oparty na tablicy mieszającej z kubełkami w postaci drzew AVL.
class HashTableAVL {
public:
    /// @brief Konstruktor. Tworzy tablicę mieszającą o początkowej pojemności.
    /// @param init_capacity Początkowa liczba kubełków (domyślnie 16).
    explicit HashTableAVL(size_t init_capacity = 16);

    /// @brief Wstawia parę klucz-wartość do słownika.
    /// @param key Klucz.
    /// @param value Wartość.
    void insert(int key, int value);

    /// @brief Usuwa parę o podanym kluczu.
    /// @param key Klucz do usunięcia.
    /// @return true jeśli element został usunięty, false jeśli nie istniał.
    bool remove(int key);

    /// @brief Wyszukuje wartość przypisaną do klucza.
    /// @param key Klucz do wyszukania.
    /// @return Wskaźnik do wartości lub nullptr jeśli nie znaleziono.
    int* find(int key);

    /// @brief Sprawdza, czy dany klucz istnieje w słowniku.
    /// @param key Klucz.
    /// @return true jeśli istnieje, false jeśli nie.
    bool contains(int key) const;

    /// @brief Zwraca liczbę elementów w słowniku.
    size_t size() const;

private:
    std::vector<AVLTree> buckets; /// Wektor kubełków – każde drzewo AVL reprezentuje kubełek.
    size_t capacity;              /// Aktualna pojemność tablicy (liczba kubełków).
    size_t size_;                 /// Liczba przechowywanych elementów.

    /// @brief Funkcja mieszająca – przekształca klucz na indeks kubełka.
    /// @param key Klucz.
    /// @return Indeks kubełka.
    size_t hash(int key) const;

    /// @brief Przeprowadza rehashing – zwiększa pojemność i rozmieszcza elementy na nowo.
    void rehash();
};

#endif // HASHTABLE_AVL_H
