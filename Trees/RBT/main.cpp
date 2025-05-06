#include <iostream>
#include "include.hpp"

int main() {
    RedBlackTree<int> rbt;

    std::cout << "Inserting elements..." << std::endl;
    rbt.insertNode(10);
    rbt.insertNode(20);
    rbt.insertNode(30);
    rbt.insertNode(15);
    rbt.insertNode(25);
    rbt.insertNode(5);
    rbt.insertNode(1);

    std::cout << "Inorder traversal after insertion: ";
    rbt.print();

    std::cout << "Searching for key 15: ";
    Node<int>* searchResult = rbt.searchNode(15);
    if (searchResult != nullptr) {
        std::cout << "Found with value: " << searchResult->key << std::endl;
    } else {
        std::cout << "Key not found!" << std::endl;
    }

    std::cout << "Deleting key 20..." << std::endl;
    rbt.deleteNode(20);
    std::cout << "Inorder traversal after deletion: ";
    rbt.print();

    std::cout << "Deleting key 10..." << std::endl;
    rbt.deleteNode(10);
    std::cout << "Inorder traversal after deletion: ";
    rbt.print();

    std::cout << "Trying to delete a non-existent key (100)..." << std::endl;
    rbt.deleteNode(100);

    std::cout << "Final inorder traversal: ";
    rbt.print();

    return 0;
}