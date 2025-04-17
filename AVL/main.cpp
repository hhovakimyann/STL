#include "include.hpp"
int main() {
    AVL<int> tree;

    tree.insert(30);
    tree.insert(20);
    tree.insert(10);
    tree.insert(5);
    tree.insert(4);

    tree.deleteNode(20);
    tree.deleteNode(4);
    std::cout << tree.search(11) << std::endl;
    std::cout << "Tree after insertions (InOrder): ";
    tree.printInOrder(tree.getRoot());
    std::cout << std::endl;
}
