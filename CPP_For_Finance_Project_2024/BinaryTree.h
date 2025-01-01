#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <vector>
#include <iostream>
#include <iomanip>

template <typename T>
class BinaryTree {
private:
    int _depth;
    std::vector<std::vector<T>> _tree;

public:
    BinaryTree();
    void setDepth(int depth);
    void setNode(int level, int index, T value);
    T getNode(int level, int index) const;
    void display() const;
};



template <typename T>
BinaryTree<T>::BinaryTree() : _depth(0) {}

template <typename T>
void BinaryTree<T>::setDepth(int depth) {
    _depth = depth;
    _tree.resize(_depth + 1);
    for (int i = 0; i <= _depth; ++i) {
        _tree[i].resize(2 * i + 1);
    }
}

template <typename T>
void BinaryTree<T>::setNode(int level, int index, T value) {
    if (level >= 0 && level <= _depth && index >= 0 && index <= 2 * level) {
        _tree[level][index] = value;
    }
    else {
        std::cerr << "Error: Index out of bounds." << std::endl;
    }
}

template <typename T>
T BinaryTree<T>::getNode(int level, int index) const {
    if (level >= 0 && level <= _depth && index >= 0 && index <= 2 * level) {
        return _tree[level][index];
    }
    else {
        std::cerr << "Error: Index out of bounds. Returning default value." << std::endl;
        return T();
    }

}

template <typename T>
void BinaryTree<T>::display() const {
    for (int i = 0; i <= _depth; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << _tree[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n" << "";

    for (int i = 0; i <= _depth; ++i) {
        int spaces = _depth - i;

        std::cout << std::setw(spaces * 4) << "";

        for (int j = 0; j <= i; ++j) {
            std::cout << std::setw(8) << _tree[i][j];
        }
        std::cout << "\n";
        std::cout << std::setw(spaces * 4 + 2) << "";
        for (int j = 0; j < i + 1; ++j) {
            if (i == _depth) {
                break;
            }
            std::cout << std::setw(8) << "/   \\";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

#endif

