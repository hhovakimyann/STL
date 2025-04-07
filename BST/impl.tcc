#include "include.hpp"

template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
void BST<T>::insert(T val)
{
    root = insert(root, val);
}

template <typename T>
bool BST<T>::search(T val)
{
    return search(root, val) != nullptr;
}

template <typename T>
void BST<T>::deleteNode(T val)
{
    root = deleteNode(root, val);
}

template <typename T>
void BST<T>::printInorder()
{
    printInorder(root);
    std::cout << std::endl;
}

template <typename T>
void BST<T>::printPostorder()
{
    printPostorder(root);
    std::cout << std::endl;

}

template <typename T>
void BST<T>::printPreorder()
{
    printPreorder(root);
    std::cout << std::endl;

}



template <typename T>
typename BST<T>::Node *BST<T>::getSuccessor(T target)
{
    return getSuccessor(root,target);
}
template <typename T>
typename BST<T>::Node *BST<T>::getPredecessor(T target)
{
    return getPredecessor(root,target);
}
template <typename T>
typename BST<T>::Node *BST<T>::insert(typename BST<T>::Node *root, T val)
{
    if(!root) return new Node(val);

    if(root->val < val) {
        root->right = insert(root->right, val);
    }else {
        root->left = insert(root->left, val);
    }
    return root;
}
template <typename T>
typename BST<T>::Node* BST<T>::search(typename BST<T>::Node* root, T val)
{
    if (!root) {
        return nullptr;
    }
    if (root->val == val) {
        return root;
    }

    if (val < root->val) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}


template <typename T>
typename BST<T>::Node *BST<T>::deleteNode(typename BST<T>::Node *root, T val)
{
    if(!root) return root;
    
    if(root->val > val) {
        root->left = deleteNode(root->left,val);
    }else if (root->val < val) {
        root->right = deleteNode(root->right,val);
    }else {
        if(!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }else if (!root->right) {
            Node * tmp =root->left;
            delete root;
            return tmp;
        }else {
            Node* successor = getSuccessor(root->right, val);
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }
    }
    return root;
}

template <class T>
typename BST<T>::Node * BST<T>::leftMost(typename BST<T>::Node *root) {
    Node *current = root;
    while(root && root->left) {
        root = root->left;
    }
    return root;
}

template <typename T>
typename BST<T>::Node *BST<T>::getSuccessor(typename BST<T>::Node *root, T val)
{

    if(!root) return nullptr;

    if(root->val == val && root->right) {
        return leftMost(root->right);
    }


    Node* curr = root;
    Node* prev = nullptr;

    while(curr) {
        if(val < curr->val) {
            prev = curr;
            curr = curr->left;
        }else {
            curr = curr->right;
        }
    }
    return prev;
}

template<class T>
typename BST<T>::Node *BST<T>::rightMost(typename BST<T>::Node *root) {

    Node* temp = root->left;
    while (temp && temp->right) temp = temp->right;
    return temp;
}

template <typename T>
typename BST<T>::Node *BST<T>::getPredecessor(typename BST<T>::Node *root, T val)
{
    if (!root) return nullptr;

    Node* current = search(root, val);
    if (!current) return nullptr;

    if (current->left) {
        Node* temp = current->left;
        while (temp->right) {
            temp = temp->right;
        }
        return temp;
    }

    Node* ancestor = nullptr;
    Node* curr = root;

    while (curr != current) {
        if (val > curr->val) {
            ancestor = curr;
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }

    return ancestor;

}

template <class T>

void BST<T>::printInorder(Node* root)
{
    if(!root) return;   
    printInorder(root->left);
    std::cout << root->val << " ";
    printInorder(root->right);
}
template <class T>
void BST<T>::printPostorder(Node* root)
{
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    std::cout << root->val << " ";
}

template <class T>
void BST<T>::printPreorder(Node* root)
{
    if (!root) return;
    std::cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

