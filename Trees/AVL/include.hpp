#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include <algorithm>

template <class T>
class AVL
{
private:
    struct Node
    {
        T val;
        Node *left;
        Node *right;
        Node(const T &val_) : val(val_), left(nullptr), right(nullptr) {}
    };
    Node *root;

public:
    AVL() : root(nullptr) {}
    ~AVL()
    {
        destroyTree(root);
    }
    void insert(const T &val);
    bool search(const T &val) const;
    void deleteNode(const T &val);

    Node* getRoot() const;

    void printInOrder(Node *node) const;
    void printPreOrder(Node *node) const;
    void printPostOrder(Node *node) const;

private:
    Node *insert(Node *node, const T &val);
    Node *search(Node *node, const T &val) const;
    Node *deleteNode(Node *node, const T &val);


    Node * getMax(Node *node);
    Node * getMin(Node *node);

    Node *rightRotate(Node *y);
    Node *leftRotate(Node *x);
    int getHeight(Node * node) const;
    void destroyTree(Node *node);
};

#include "impl.tcc"

#endif // AVL_HPP