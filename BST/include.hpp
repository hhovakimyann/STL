#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>

template <class T>
class BST {
private:
    struct Node {
        Node *left;
        Node *right;
        T val;

        Node(T val_) {
            val = val_;
            left = nullptr;
            right = nullptr;
        }
    };

private:
    Node *root;
private:
    Node* insert(Node *root, T val);
    Node* search(Node* root,T val);
    Node *deleteNode(Node* root, T val);
    void printInorder(Node * root);
    void printPostorder(Node* root);
    void printPreorder(Node* root);
    Node* getSuccessor(Node* root, T target);
    Node* getPredecessor(Node* root, T target);

    Node* leftMost(Node* node);
    Node* rightMost(Node* node);
    
public:
    BST();
    void insert(T val);
    bool search(T val);
    void deleteNode(T val);

    void printInorder();
    void printPostorder();
    void printPreorder();

    Node* getSuccessor(T target);
    Node* getPredecessor(T target);
};

#include "impl.tcc"

#endif // Binary Search Tree