/*#include "BinaryTree.h"

// Constructeur
template <typename T>
BinaryTree<T>::BinaryTree() : _depth(0) {}

// Définition de setDepth
template <typename T>
void BinaryTree<T>::setDepth(int depth) {
    _depth = depth;
    _tree.resize(_depth + 1); // Redimensionne pour inclure tous les niveaux
    for (int i = 0; i <= _depth; ++i) {
        _tree[i].resize(i + 1); // Chaque niveau i a i + 1 nœuds
    }
}

// Définition de setNode
template <typename T>
void BinaryTree<T>::setNode(int level, int index, T value) {
    if (level >= 0 && level <= _depth && index >= 0 && index <= level) {
        _tree[level][index] = value;
    }
    else {
        std::cerr << "Invalid indices for setNode.\n";
    }
}

// Définition de getNode
template <typename T>
T BinaryTree<T>::getNode(int level, int index) const {
    if (level >= 0 && level <= _depth && index >= 0 && index <= level) {
        return _tree[level][index];
    }
    else {
        std::cerr << "Invalid indices for getNode.\n";
        return T(); // Retourne une valeur par défaut de T si hors limites
    }
}

// Définition de display
template <typename T>
void BinaryTree<T>::display() const {
    for (int i = 0; i <= _depth; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << _tree[i][j] << " ";
        }
        std::cout << "\n";
    }
}
*/