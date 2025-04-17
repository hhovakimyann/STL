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
    Node* insert(Node *root, const T& val);
    Node* search(Node* root,const T& val) const;
    Node *deleteNode(Node* root, const T& val);
    void printInorder(Node * root);
    void printPostorder(Node* root);
    void printPreorder(Node* root);
    Node* getSuccessor(Node* root, const T& target);
    Node* getPredecessor(Node* root, const T& target);

    size_t getHeight(Node* node) const;
public:
    BST();
    void insert(const T& val);
    bool search(const T& val) const;
    void deleteNode(const T& val);

    void printInorder();
    void printPostorder();
    void printPreorder();

    Node* getSuccessor(const T& target);
    Node* getPredecessor(const T& target);

    size_t getHeight() const;
    void destroyTree(Node* root);
    ~BST();

};

#include "impl.tcc"

#endif // Binary Search Tree