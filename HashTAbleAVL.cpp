#include "HashTableAVL.h"
#include <functional>

/// @brief Konstruktor – inicjalizuje wektor kubełków o zadanej pojemności.
HashTableAVL::HashTableAVL(size_t init_capacity)
    : buckets(init_capacity), capacity(init_capacity), size_(0) {}

/// @brief Wstawia parę klucz-wartość do odpowiedniego kubełka.
/// Jeśli element już istnieje, nadpisuje jego wartość.
void HashTableAVL::insert(int key, int value) {
    if ((size_ + 1.0) / capacity > 0.7)
        rehash();
    auto& tree = buckets[hash(key)];
    if (!tree.contains(key))
        ++size_;
    tree.insert(key, value);
}

/// @brief Usuwa element o danym kluczu.
/// @return true jeśli element został usunięty, false jeśli nie istniał.
bool HashTableAVL::remove(int key) {
    auto& tree = buckets[hash(key)];
    if (tree.remove(key)) {
        --size_;
        return true;
    }
    return false;
}

/// @brief Wyszukuje wartość skojarzoną z kluczem.
/// @return Wskaźnik do wartości lub nullptr jeśli nie znaleziono.
int* HashTableAVL::find(int key) {
    return buckets[hash(key)].find(key);
}

/// @brief Sprawdza, czy dany klucz istnieje w słowniku.
bool HashTableAVL::contains(int key) const {
    return buckets[hash(key)].contains(key);
}

/// @brief Zwraca liczbę elementów w słowniku.
size_t HashTableAVL::size() const {
    return size_;
}

/// @brief Funkcja mieszająca – oblicza indeks kubełka dla danego klucza.
size_t HashTableAVL::hash(int key) const {
    static std::hash<int> hasher;
    return hasher(key) % capacity;
}

/// @brief Przeprowadza rehashing – podwaja pojemność tablicy i rozmieszcza wszystkie elementy na nowo.
void HashTableAVL::rehash() {
    capacity *= 2;
    std::vector<AVLTree> newbuckets(capacity);

    for (auto& tree : buckets) {
        tree.traverse([&](int k, int v) {
            newbuckets[hash(k)].insert(k, v);
        });
    }

    buckets.swap(newbuckets);
}
