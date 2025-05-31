#include "AVLTree.h"
#include <algorithm>


AVLTree::AVLTree() : root(nullptr) {}
AVLTree::~AVLTree() { deleteTree(root); }

void AVLTree::insert(int key, int value) {
    root = insertNode(root, key, value);
}

bool AVLTree::remove(int key) {
    if (!contains(key)) return false;
    root = removeNode(root, key);
    return true;
}

int* AVLTree::find(int key) {
    AVLNode* n = findNode(root, key);
    return n ? &n->value : nullptr;
}

bool AVLTree::contains(int key) const {
    return findNode(root, key) != nullptr;
}

void AVLTree::traverse(const std::function<void(int,int)>& f) const {
    traverseNode(root, f);
}



int AVLTree::height(AVLNode* n) const {
    return n ? n->height : 0;
}

int AVLTree::balanceFactor(AVLNode* n) const {
    return n ? height(n->left) - height(n->right) : 0;
}

void AVLTree::updateHeight(AVLNode* n) {
    n->height = 1 + std::max(height(n->left), height(n->right));
}

AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    x->right = y->left;
    y->left = x;
    updateHeight(x);
    updateHeight(y);
    return y;
}

AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    y->left = x->right;
    x->right = y;
    updateHeight(y);
    updateHeight(x);
    return x;
}

AVLNode* AVLTree::insertNode(AVLNode* n, int k, int v) {
    if (!n) return new AVLNode(k, v);
    if (k < n->key) n->left = insertNode(n->left, k, v);
    else if (k > n->key) n->right = insertNode(n->right, k, v);
    else { n->value = v; return n; }

    updateHeight(n);
    int bf = balanceFactor(n);
    if (bf > 1 && k < n->left->key) return rotateRight(n);
    if (bf < -1 && k > n->right->key) return rotateLeft(n);
    if (bf > 1 && k > n->left->key) { n->left = rotateLeft(n->left); return rotateRight(n); }
    if (bf < -1 && k < n->right->key) { n->right = rotateRight(n->right); return rotateLeft(n); }
    return n;
}

AVLNode* AVLTree::minValueNode(AVLNode* n) const {
    while (n->left) n = n->left;
    return n;
}

AVLNode* AVLTree::removeNode(AVLNode* n, int k) {
    if (!n) return nullptr;
    if (k < n->key) n->left = removeNode(n->left, k);
    else if (k > n->key) n->right = removeNode(n->right, k);
    else {
        if (!n->left || !n->right) {
            AVLNode* tmp = n->left ? n->left : n->right;
            delete n;
            return tmp;
        } else {
            AVLNode* tmp = minValueNode(n->right);
            n->key = tmp->key;
            n->value = tmp->value;
            n->right = removeNode(n->right, tmp->key);
        }
    }
    updateHeight(n);
    int bf = balanceFactor(n);
    if (bf > 1 && balanceFactor(n->left) >= 0) return rotateRight(n);
    if (bf > 1 && balanceFactor(n->left) < 0) { n->left = rotateLeft(n->left); return rotateRight(n); }
    if (bf < -1 && balanceFactor(n->right) <= 0) return rotateLeft(n);
    if (bf < -1 && balanceFactor(n->right) > 0) { n->right = rotateRight(n->right); return rotateLeft(n); }
    return n;
}

AVLNode* AVLTree::findNode(AVLNode* n, int k) const {
    if (!n) return nullptr;
    if (k == n->key) return n;
    return (k < n->key)
         ? findNode(n->left, k)
         : findNode(n->right, k);
}

void AVLTree::deleteTree(AVLNode* n) {
    if (!n) return;
    deleteTree(n->left);
    deleteTree(n->right);
    delete n;
}

void AVLTree::traverseNode(AVLNode* n, const std::function<void(int,int)>& f) const {
    if (!n) return;
    traverseNode(n->left, f);
    f(n->key, n->value);
    traverseNode(n->right, f);
}

