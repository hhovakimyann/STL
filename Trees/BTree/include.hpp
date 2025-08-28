#ifndef B_TREE
#define B_TREE

#include <iostream>
#include <vector>

template <class T>
class TreeNode {
public:
    std::vector<TreeNode<T>*> children;
    std::vector<T> keys;
    bool isLeaf;
    int t;

    TreeNode(int _t, bool _isLeaf);
    ~TreeNode();

    void traverse();
    TreeNode<T>* search(const T &k);
    void insertNonFull(const T &k);
    void splitChild(int i, TreeNode<T>* y);
};

template <class T>
class B_Tree {
    TreeNode<T>* root;
    int t;

public:
    B_Tree(int _t);
    ~B_Tree();

    void traverse();
    TreeNode<T>* search(const T &k);
    void insert(const T &k);
};

#include "impl.tpp"

#endif // B_TREE