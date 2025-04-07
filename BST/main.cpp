#include "include.hpp"

int main() {
    BST<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder Traversal: ";
    bst.printInorder();  

    std::cout << "Preorder Traversal: ";
    bst.printPreorder();  

    std::cout << "Postorder Traversal: ";
    bst.printPostorder();  

    std::cout << "Search 40: " << (bst.search(40) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 100: " << (bst.search(100) ? "Found" : "Not Found") << std::endl;

    std::cout << "Deleting 20\n";
    bst.deleteNode(20);
    std::cout << "Deleting 30\n";
    bst.deleteNode(30);  
    std::cout << "Deleting 50\n";
    bst.deleteNode(50); 
    std::cout << "Inorder after deletions: ";
    bst.printInorder(); 

    auto succ = bst.getSuccessor(40);
    if (succ) std::cout << "Successor of 40: " << succ->val << std::endl;
    else std::cout << "Successor of 40 not found\n";

    auto pred = bst.getPredecessor(60);
    if (pred) std::cout << "Predecessor of 60: " << pred->val << std::endl;
    else std::cout << "Predecessor of 60 not found\n";

    return 0;
}
