#include "include.hpp"

template <class T>
void AVL<T>::insert(const T &val)
{
    root = insert(root, val);
}
template <class T>
bool AVL<T>::search(const T &val) const
{
    return search(root, val) != nullptr;
}
template <class T>
void AVL<T>::deleteNode(const T &val)
{
    root = deleteNode(root, val);
}

template <class T>
typename AVL<T>::Node *AVL<T>::insert(typename AVL<T>::Node *node, const T &val)
{
    if (!node)
    {
        return new Node(val);
    }

    if (node->val > val)
    {
        node->left = insert(node->left, val);
    }
    else if (node->val < val)
    {
        node->right = insert(node->right, val);
    }
    else
    {
        return node;
    }

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    int bf = leftHeight - rightHeight;

    if (bf > 1 && node->left->val > val)
    {
        return rightRotate(node);
    }
    else if (bf > 1 && node->left->val < val)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    else if (bf < -1 && node->right->val > val)
    {
        return leftRotate(node);
    }
    else if (bf < -1 && node->right->val < val)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

template <class T>
typename AVL<T>::Node *AVL<T>::search(typename AVL<T>::Node *node, const T &val) const
{
    if (!node)
        return nullptr;

    if (node->val == val)
        return node;
    if (node->val > val)
    {
        return search(node->left, val);
    }
    else
    {
        return search(node->right, val);
    }
}
template <class T>
typename AVL<T>::Node *AVL<T>::deleteNode(typename AVL<T>::Node *node, const T &val)
{
    if (!node)
        return node;

    if (node->val > val)
    {
        node->left = deleteNode(node->left, val);
    }
    else if (node->val < val)
    {
        node->right = deleteNode(node->right, val);
    }
    else
    {
        if (!node->left)
        {
            Node *temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right)
        {
            Node *temp = node->left;
            delete node;
            return temp;
        }
        else
        {
            Node *temp = getMin(node->right);
            node->val = temp->val;
            node->right = deleteNode(node->right, temp->val);
        }
    }

    int left = getHeight(node->left);
    int right = getHeight(node->right);
    int bf = left - right;

    if (bf > 1)
    {
        if (getHeight(node->left->left) >= getHeight(node->left->right)) {
            return rightRotate(node);
        }

        else {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (bf < -1)
    {
        if (getHeight(node->right->left) <= getHeight(node->right->right)) {
            return leftRotate(node);
        }
        else {
            node->right = rightRotate(node->right);
            return leftRotate(node);   
        }   
    }
    return node;
}

template <class T>
typename AVL<T>::Node *AVL<T>::getRoot() const
{
    return root;
}

template <class T>
void AVL<T>::printInOrder(typename AVL<T>::Node *node) const
{
    if (!node)
        return;
    printInOrder(node->left);
    std::cout << node->val << " ";
    printInOrder(node->right);
}
template <class T>
void AVL<T>::printPreOrder(typename AVL<T>::Node *node) const
{
    if (!node)
        return;
    std::cout << node->val << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}
template <class T>
void AVL<T>::printPostOrder(typename AVL<T>::Node *node) const
{
    if (!node)
        return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    std::cout << node->val << " ";
}
template <class T>
typename AVL<T>::Node *AVL<T>::getMax(typename AVL<T>::Node *node)
{
    if (!node)
        return node;
    while (node->right)
        node = node->right;
    return node;
}

template <class T>
typename AVL<T>::Node *AVL<T>::getMin(typename AVL<T>::Node *node)
{
    if (!node)
        return node;
    while (node->left)
        node = node->left;
    return node;
}

template <class T>
typename AVL<T>::Node *AVL<T>::leftRotate(typename AVL<T>::Node *x)
{
    if (!x || !x->right)
        return x;

    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

template <class T>
typename AVL<T>::Node *AVL<T>::rightRotate(typename AVL<T>::Node *y)
{
    if (!y || !y->left)
        return y;

    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}
template <class T>
int AVL<T>::getHeight(typename AVL<T>::Node *node) const
{
    if (!node)
        return 0;
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
}

template <class T>
void AVL<T>::destroyTree(typename AVL<T>::Node *node)
{
    if (!node)
        return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}
