#include "include.hpp"

template <class T>
Node<T>* RedBlackTree<T>::getRoot() const {
    return root;
}

template <class T>
void RedBlackTree<T>::print() const {
    inorder(root);
    std::cout << std::endl;
}

template <class T>
void RedBlackTree<T>::inorder(Node<T>* root) const{
    if(root == nil) return;
    inorder(root->left);
    std::cout << "(" << root->color << ")" << " " << root->key << " "; 
    inorder(root->right);
    return ;
}

template <class T>
RedBlackTree<T>::RedBlackTree() {
    nil = new Node<T>(-1);
    nil->color = Black;
    nil->left = nil->right = nil->parent = nil;
    root = nil;
}

template <class T>
void RedBlackTree<T>::insertNode(const T& k) {
    Node<T> * z = new Node<T>(k); 
    z->left = z->right = z->parent = nil;

    Node<T> * x = root;
    Node<T> * y = nil;

    while(x != nil) {
        y = x;
        if(z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;

    if(y == nil) {
        root = z;
    } else if(z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }

    z->color = Red;
    z->left = z->right = nil;

    insertionFixUp(z);
}

template <class T>
void RedBlackTree<T>::leftRotate(Node<T>* x) {
    Node<T> *y = x->right;
    x->right = y->left;
    if(y->left != nil) {
        y->left->parent = x; 
    }
    y->parent = x->parent;

    if(x->parent == nil) {
        root = y;
    } else if(x->parent->left == x) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

template <class T>
void RedBlackTree<T>::rightRotate(Node<T>* x) {
    Node<T> *y = x->left;
    x->left = y->right;
    if(y->right != nil) {
        y->right->parent = x;
    }

    y->parent = x->parent;

    if(x->parent == nil) {
        root = y;
    } else if(x->parent->left == x) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    x->parent = y;
    y->right = x;
}

template <class T>
void RedBlackTree<T>::insertionFixUp(Node<T>* z) {
    while(z->parent->color == Red) {
        if(z->parent == z->parent->parent->left) {
            Node<T> * y = z->parent->parent->right;
            if(y->color == Red) {
                y->color = Black;
                z->parent->color = Black;
                z->parent->parent->color = Red;
                z = z->parent->parent;
            } else {
                if(z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = Black;
                z->parent->parent->color = Red;
                rightRotate(z->parent->parent);
            }
        } else {
            Node<T>* y = z->parent->parent->left;
            if(y->color == Red) {
                y->color = Black;
                z->parent->color = Black;
                z->parent->parent->color = Red;
                z = z->parent->parent;
            } else {
                if(z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = Black;
                z->parent->parent->color = Red;
                leftRotate(z->parent->parent);
            }
        }   
    }
    root->color = Black;
}

template <class T>
Node<T>* RedBlackTree<T>::searchNode(const T& key) {
    Node<T>* current = root;
    while(current != nil && current->key != key) {
        if(key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return current != nil ? current : nullptr;
}

template <class T>
void RedBlackTree<T>::rbTransplant(Node<T>* u, Node<T>* v) {
    if(u->parent == nil) {
        root = v;
    } else if(u->parent->left == u) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

template <class T>
void RedBlackTree<T>::deleteNode(const T& key) {
    Node<T>* delNode = searchNode(key);
    if(delNode != nullptr) {
        rbDelete(delNode);
    } else {
        std::cout << "Key not found in tree " << std::endl; 
    }
}

template <class T>
Node<T>* RedBlackTree<T>::getSuccessor(Node<T>* node) {
    while(node->left != nil) {
        node = node->left;
    }
    return node;
}

template <class T>
void RedBlackTree<T>::rbDelete(Node<T>* z) {
    Color originalColor = z->color;
    Node<T>* succ = z;
    Node<T>* moveChild = nullptr;

    if(z->left == nil) {
        moveChild = z->right;
        rbTransplant(z, moveChild);
    } else if(z->right == nil) {
        moveChild = z->left;
        rbTransplant(z, moveChild);
    } else {
        succ = getSuccessor(z->right);
        originalColor = succ->color;
        moveChild = succ->right;

        if(succ->parent != z) {
            rbTransplant(succ, moveChild);
            succ->right = z->right;
            succ->right->parent = succ;
        } else {
            moveChild->parent = succ;
        }

        rbTransplant(z, succ);
        succ->left = z->left;
        succ->left->parent = succ;
        succ->color = z->color;
    }

    if(originalColor == Black) {
        rbTreeFixUp(moveChild);
    }
    delete z;
}

template <class T>
void RedBlackTree<T>::rbTreeFixUp(Node<T>* x) {
    while(x != nil && x->color == Black) {
        if(x == x->parent->left) {
            Node<T>* w = x->parent->right;
            if(w->color == Red) {
                w->color = Black;
                x->parent->color = Red;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if(w->left->color == Black && w->right->color == Black) {
                w->color = Red;
                x = x->parent;
            } else {
                if(w->right->color == Black) {
                    w->left->color = Black;
                    w->color = Red;
                    rightRotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = Black;
                w->right->color = Black;
                leftRotate(x->parent);
                x = root;
            }
        } else {
            Node<T>* w = x->parent->left;
            if(w->color == Red) {
                w->color = Black;
                x->parent->color = Red;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if(w->right->color == Black && w->left->color == Black) {
                w->color = Red;
                x = x->parent;
            } else {
                if(w->left->color == Black) {
                    w->right->color = Black;
                    w->color = Red;
                    leftRotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = Black;
                w->left->color = Black;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    if(x != nil) {
        x->color = Black;
    }
}