#ifndef AVLTREE_H
#define AVLTREE_H

#include <algorithm>
#include <functional>

// Węzeł drzewa AVL przechowujący parę (int → int)
struct AVLNode {
    int key;
    int value;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(int k, int v)
      : key(k), value(v), left(nullptr), right(nullptr), height(1) {}
};

/// @brief Proste drzewo AVL (klucz i wartość typu int)
class AVLTree {
public:
    AVLTree();
    ~AVLTree();

    void insert(int key, int value);
    bool remove(int key);
    int*  find(int key);
    bool contains(int key) const;
    void  traverse(const std::function<void(int,int)>& f) const;

private:
    AVLNode* root;

    int  height(AVLNode* n) const;
    int  balanceFactor(AVLNode* n) const;
    void updateHeight(AVLNode* n);
    AVLNode* rotateLeft(AVLNode*  x);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* insertNode(AVLNode* n, int k, int v);
    AVLNode* removeNode(AVLNode* n, int k);
    AVLNode* minValueNode(AVLNode* n) const;
    AVLNode* findNode(AVLNode* n, int k) const;
    void deleteTree(AVLNode* n);
    void traverseNode(AVLNode* n, const std::function<void(int,int)>& f) const;

    // dajemy dostęp do root w rehashie
    friend class HashTableAVL;
};

#endif // AVLTREE_H