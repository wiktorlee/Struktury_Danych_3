#ifndef AVLTREE_H
#define AVLTREE_H

#include <functional>

/// @brief Struktura reprezentująca pojedynczy węzeł drzewa AVL.
struct AVLNode {
    int key;       /// Klucz przechowywany w węźle.
    int value;     /// Wartość przypisana do klucza.
    int height;    /// Wysokość węzła w drzewie AVL.
    AVLNode* left = nullptr;  /// Wskaźnik na lewe poddrzewo.
    AVLNode* right = nullptr; /// Wskaźnik na prawe poddrzewo.

    /// @brief Konstruktor tworzący węzeł z kluczem i wartością.
    AVLNode(int k, int v) : key(k), value(v), height(1) {}
};

/// @brief Klasa reprezentująca drzewo AVL – zrównoważone drzewo BST.
class AVLTree {
public:
    /// @brief Konstruktor domyślny – tworzy puste drzewo.
    AVLTree();

    /// @brief Destruktor – zwalnia pamięć zajmowaną przez drzewo.
    ~AVLTree();

    /// @brief Wstawia do drzewa nową parę klucz-wartość.
    void insert(int key, int value);

    /// @brief Usuwa węzeł z drzewa na podstawie klucza.
    /// @return true jeśli usunięto, false jeśli klucza nie znaleziono.
    bool remove(int key);

    /// @brief Wyszukuje wartość przypisaną do danego klucza.
    /// @return Wskaźnik na wartość lub nullptr, jeśli brak klucza.
    int* find(int key);

    /// @brief Sprawdza, czy w drzewie istnieje dany klucz.
    /// @return true jeśli istnieje, false w przeciwnym wypadku.
    bool contains(int key) const;

    /// @brief Przechodzi przez wszystkie pary (klucz, wartość) w porządku rosnącym.
    /// @param f Funkcja wywoływana dla każdej pary (klucz, wartość).
    void traverse(const std::function<void(int, int)>& f) const;

private:
    AVLNode* root = nullptr; ///< Korzeń drzewa AVL.

    /// @brief Zwraca wysokość danego węzła.
    int height(AVLNode* n) const;

    /// @brief Oblicza współczynnik zrównoważenia dla danego węzła.
    int balanceFactor(AVLNode* n) const;

    /// @brief Aktualizuje wysokość węzła na podstawie jego dzieci.
    void updateHeight(AVLNode* n);

    /// @brief Wykonuje rotację w lewo w celu przywrócenia równowagi drzewa.
    AVLNode* rotateLeft(AVLNode* x);

    /// @brief Wykonuje rotację w prawo w celu przywrócenia równowagi drzewa.
    AVLNode* rotateRight(AVLNode* y);

    /// @brief Rekurencyjnie wstawia węzeł do drzewa.
    AVLNode* insertNode(AVLNode* n, int k, int v);

    /// @brief Rekurencyjnie usuwa węzeł z drzewa.
    AVLNode* removeNode(AVLNode* n, int k);

    /// @brief Znajduje węzeł o najmniejszym kluczu w poddrzewie.
    AVLNode* minValueNode(AVLNode* n) const;

    /// @brief Wyszukuje węzeł o zadanym kluczu.
    AVLNode* findNode(AVLNode* n, int k) const;

    /// @brief Rekurencyjnie usuwa wszystkie węzły drzewa (zwalnia pamięć).
    void deleteTree(AVLNode* n);

    /// @brief Rekurencyjnie przechodzi przez drzewo w porządku rosnącym (in-order).
    /// @param f Funkcja wywoływana dla każdej pary (klucz, wartość).
    void traverseNode(AVLNode* n, const std::function<void(int, int)>& f) const;
};

#endif // AVLTREE_H
