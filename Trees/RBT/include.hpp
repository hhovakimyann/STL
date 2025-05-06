#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE

#include <iostream>

enum Color {
    Red,
    Black,
};

template <class T>
class Node {
public:
    T key;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
    Color color;
public:
    Node(T k) : key(k), left(nullptr), right(nullptr), parent(nullptr), color(Red) {}
};

template <class T>
class RedBlackTree {
private:
    Node<T>* root, *nil;
    void inorder(Node<T>* root) const;
    void rightRotate(Node<T>* node);
    void leftRotate(Node<T>* node);
    void insertionFixUp(Node<T>* z);
    void rbTransplant(Node<T>* u, Node<T>* v);
    void rbDelete(Node<T>* z);
    void rbTreeFixUp(Node<T>* x);
    Node<T>* getSuccessor(Node<T>* node);
public:
    RedBlackTree();
    void insertNode(const T& k);
    void deleteNode(const T& k);
    Node<T>* searchNode(const T& k);
    void print() const;
    Node<T>* getRoot() const;
};

#include "imple.tpp"

#endif // RED_BLACK_TREE