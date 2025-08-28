#include "include.hpp"

template <class T>
TreeNode<T>::TreeNode(int _t, bool _isLeaf) : t(_t), isLeaf(_isLeaf) {}

template <class T>
TreeNode<T>::~TreeNode() {
    if (!isLeaf) {
        for (auto child : children) {
            delete child;
        }
    }
}

template <class T>
void TreeNode<T>::traverse() {
    int i;
    for (i = 0; i < keys.size(); i++) {
        if (!isLeaf)
            children[i]->traverse();
        std::cout << " " << keys[i];
    }
    if (!isLeaf)
        children[i]->traverse();
}

template <class T>
TreeNode<T>* TreeNode<T>::search(const T &k) {
    int i = 0;
    while (i < keys.size() && k > keys[i]) i++;
    if (i < keys.size() && keys[i] == k) return this;
    if (isLeaf) return nullptr;
    return children[i]->search(k);
}

template <class T>
void TreeNode<T>::insertNonFull(const T &k) {
    int i = keys.size() - 1;
    if (isLeaf) {
        keys.push_back(T());
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
    } else {
        while (i >= 0 && keys[i] > k) i--;
        i++;
        if (children[i]->keys.size() == 2 * t - 1) {
            splitChild(i, children[i]);
            if (keys[i] < k) i++;
        }
        children[i]->insertNonFull(k);
    }
}

template <class T>
void TreeNode<T>::splitChild(int i, TreeNode<T>* y) {
    TreeNode<T>* z = new TreeNode<T>(y->t, y->isLeaf);
    
    z->keys.resize(t - 1);
    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (!y->isLeaf) {
        z->children.resize(t);
        for (int j = 0; j < t; j++)
            z->children[j] = y->children[j + t];
    }

    T middleKey = y->keys[t - 1];
    y->keys.resize(t - 1);
    if (!y->isLeaf) y->children.resize(t);

    children.insert(children.begin() + i + 1, z);
    keys.insert(keys.begin() + i, middleKey);
}

template <class T>
B_Tree<T>::B_Tree(int _t) : root(nullptr), t(_t) {}

template <class T>
B_Tree<T>::~B_Tree() { delete root; }

template <class T>
void B_Tree<T>::traverse() {
    if (root) root->traverse();
}

template <class T>
TreeNode<T>* B_Tree<T>::search(const T &k) {
    return (root ? root->search(k) : nullptr);
}

template <class T>
void B_Tree<T>::insert(const T &k) {
    if (!root) {
        root = new TreeNode<T>(t, true);
        root->keys.push_back(k);
    } else {
        if (root->keys.size() == 2 * t - 1) {
            TreeNode<T>* s = new TreeNode<T>(t, false);
            s->children.push_back(root);
            s->splitChild(0, root);
            int i = (s->keys[0] < k) ? 1 : 0;
            s->children[i]->insertNonFull(k);
            root = s;
        } else {
            root->insertNonFull(k);
        }
    }
}