#ifndef HASHTABLE_AVL_H
#define HASHTABLE_AVL_H

#include <vector>
#include <memory>
#include <functional>
#include "AVLTree.h"

/// @brief Słownik: tablica mieszająca z kubełkami-drzewami AVL
class HashTableAVL {
public:
    explicit HashTableAVL(size_t init_capacity = 16);
    ~HashTableAVL() = default;

    void insert(int key, int value);
    bool remove(int key);
    int* find(int key);
    bool contains(int key) const;
    size_t size() const;

private:
    std::vector<std::unique_ptr<AVLTree>> buckets;
    size_t capacity;
    size_t size_;

    size_t hash(int key) const;
    void rehash();
};

#endif