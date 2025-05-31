#include "HashTableAVL.h"

// Konstruktor
HashTableAVL::HashTableAVL(size_t init_capacity)
  : capacity(init_capacity), size_(0)
{
    buckets.resize(capacity);
    for (auto& b : buckets)
        b = std::make_unique<AVLTree>();
}

void HashTableAVL::insert(int key, int value) {
    if ((size_ + 1.0) / capacity > 0.7)
        rehash();
    auto& t = buckets[hash(key)];
    if (!t->contains(key)) ++size_;
    t->insert(key, value);
}

bool HashTableAVL::remove(int key) {
    auto& t = buckets[hash(key)];
    if (t->remove(key)) { --size_; return true; }
    return false;
}

int* HashTableAVL::find(int key) {
    return buckets[hash(key)]->find(key);
}

bool HashTableAVL::contains(int key) const {
    return buckets[hash(key)]->contains(key);
}

size_t HashTableAVL::size() const {
    return size_;
}

size_t HashTableAVL::hash(int key) const {
    return std::hash<int>{}(key) % capacity;
}

void HashTableAVL::rehash() {
    size_t old = capacity;
    capacity *= 2;
    std::vector<std::unique_ptr<AVLTree>> tmp;
    tmp.resize(capacity);
    for (auto& b : tmp)
        b = std::make_unique<AVLTree>();

    for (size_t i = 0; i < old; ++i) {
        buckets[i]->traverse([&](int k, int v){
            tmp[std::hash<int>{}(k) % capacity]->insert(k, v);
        });
    }
    buckets.swap(tmp);
}

