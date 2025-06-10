#include "AVLTree.h"
#include <algorithm>

/// @brief Konstruktor – inicjalizuje puste drzewo.
AVLTree::AVLTree() : root(nullptr) {}

/// @brief Destruktor – usuwa całe drzewo i zwalnia pamięć.
AVLTree::~AVLTree() {
    deleteTree(root);
}

/// @brief Wstawia nową parę klucz-wartość do drzewa AVL.
void AVLTree::insert(int key, int value) {
    root = insertNode(root, key, value);
}

/// @brief Usuwa węzeł z podanym kluczem.
/// @return true jeśli klucz istniał i został usunięty, false w przeciwnym razie.
bool AVLTree::remove(int key) {
    if (!contains(key)) return false;
    root = removeNode(root, key);
    return true;
}

/// @brief Wyszukuje węzeł o podanym kluczu.
/// @return Wskaźnik do wartości, jeśli znaleziono, w przeciwnym razie nullptr.
int* AVLTree::find(int key) {
    AVLNode* n = findNode(root, key);
    return n ? &n->value : nullptr;
}

/// @brief Sprawdza, czy drzewo zawiera klucz.
bool AVLTree::contains(int key) const {
    return findNode(root, key) != nullptr;
}

/// @brief In-order przejście drzewa – wywołuje funkcję dla każdej pary klucz-wartość.
void AVLTree::traverse(const std::function<void(int, int)>& f) const {
    traverseNode(root, f);
}

/// @brief Zwraca wysokość danego węzła.
int AVLTree::height(AVLNode* n) const {
    return n ? n->height : 0;
}

/// @brief Oblicza współczynnik zbalansowania danego węzła.
int AVLTree::balanceFactor(AVLNode* n) const {
    return height(n->left) - height(n->right);
}

/// @brief Aktualizuje wysokość danego węzła.
void AVLTree::updateHeight(AVLNode* n) {
    n->height = 1 + std::max(height(n->left), height(n->right));
}

/// @brief Rotacja w lewo – potrzebna do balansowania.
AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    x->right = y->left;
    y->left = x;
    updateHeight(x);
    updateHeight(y);
    return y;
}

/// @brief Rotacja w prawo – potrzebna do balansowania.
AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    y->left = x->right;
    x->right = y;
    updateHeight(y);
    updateHeight(x);
    return x;
}

/// @brief Wstawia nowy węzeł do poddrzewa z zachowaniem reguł AVL.
/// @return Nowy korzeń poddrzewa.
AVLNode* AVLTree::insertNode(AVLNode* n, int k, int v) {
    if (!n) return new AVLNode(k, v);

    if (k < n->key)
        n->left  = insertNode(n->left,  k, v);
    else if (k > n->key)
        n->right = insertNode(n->right, k, v);
    else {
        n->value = v;
        return n;
    }

    updateHeight(n);
    int bf = balanceFactor(n);

    // Balansowanie drzewa
    if (bf > 1 && k < n->left->key)
        return rotateRight(n);
    if (bf < -1 && k > n->right->key)
        return rotateLeft(n);
    if (bf > 1 && k > n->left->key) {
        n->left = rotateLeft(n->left);
        return rotateRight(n);
    }
    if (bf < -1 && k < n->right->key) {
        n->right = rotateRight(n->right);
        return rotateLeft(n);
    }

    return n;
}

/// @brief Znajduje węzeł o najmniejszym kluczu w danym poddrzewie.
AVLNode* AVLTree::minValueNode(AVLNode* n) const {
    while (n->left) n = n->left;
    return n;
}

/// @brief Usuwa węzeł o danym kluczu z poddrzewa.
/// @return Nowy korzeń poddrzewa.
AVLNode* AVLTree::removeNode(AVLNode* n, int k) {
    if (!n) return nullptr;

    if (k < n->key)
        n->left  = removeNode(n->left, k);
    else if (k > n->key)
        n->right = removeNode(n->right, k);
    else {
        if (!n->left || !n->right) {
            AVLNode* tmp = n->left ? n->left : n->right;
            delete n;
            return tmp;
        }

        AVLNode* tmp = minValueNode(n->right);
        n->key = tmp->key;
        n->value = tmp->value;
        n->right = removeNode(n->right, tmp->key);
    }

    updateHeight(n);
    int bf = balanceFactor(n);

    if (bf > 1 && balanceFactor(n->left) >= 0)
        return rotateRight(n);
    if (bf > 1 && balanceFactor(n->left) < 0) {
        n->left = rotateLeft(n->left);
        return rotateRight(n);
    }
    if (bf < -1 && balanceFactor(n->right) <= 0)
        return rotateLeft(n);
    if (bf < -1 && balanceFactor(n->right) > 0) {
        n->right = rotateRight(n->right);
        return rotateLeft(n);
    }

    return n;
}

/// @brief Wyszukuje węzeł o danym kluczu w poddrzewie.
AVLNode* AVLTree::findNode(AVLNode* n, int k) const {
    if (!n) return nullptr;
    if (k == n->key) return n;
    return (k < n->key) ? findNode(n->left, k) : findNode(n->right, k);
}

/// @brief Usuwa całe drzewo i zwalnia pamięć.
void AVLTree::deleteTree(AVLNode* n) {
    if (!n) return;
    deleteTree(n->left);
    deleteTree(n->right);
    deleteTree(n->right);
    delete n;
}

/// @brief In-order przejście poddrzewa – wywołuje funkcję dla każdego elementu.
void AVLTree::traverseNode(AVLNode* n, const std::function<void(int, int)>& f) const {
    if (!n) return;
    traverseNode(n->left, f);
    f(n->key, n->value);
    traverseNode(n->right, f);
}
