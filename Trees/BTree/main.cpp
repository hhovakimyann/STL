#include "include.hpp"

int main() {
    B_Tree<int> t(3); 

    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    std::cout << "Traversal of B-tree is:";
    t.traverse();

    int k = 6;
    (t.search(k) != nullptr) ? std::cout << "\nPresent\n" : std::cout << "\nNot Present\n";

    k = 15;
    (t.search(k) != nullptr) ? std::cout << "Present\n" : std::cout << "Not Present\n";

    return 0;
}