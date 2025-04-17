#include "include.hpp"
#include <iostream>

int main() {
    Graph<int> g;

    // Create a sample graph
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 6);
    g.addEdge(3, 7);
    g.addEdge(4, 8);
    g.addEdge(6, 9);

    std::cout << "DFS Print from node 1:\n";
    g.printElements(1);
    std::cout << "\n\n";

    std::cout << "BFS Print (Levels) from node 1:\n";
    g.printLevels(1);
    std::cout << "\n\n";

    std::cout << "Number of components in graph: ";
    std::cout << g.getNumComponents() << "\n\n";
    
    std::cout << "Can reach from 1 to 9: ";
    std::cout << (g.canReachFromSourceToDest(1, 9) ? "Yes" : "No") << "\n";
    
    std::cout << "Can reach from 5 to 9: ";
    std::cout << (g.canReachFromSourceToDest(5, 9) ? "Yes" : "No") << "\n\n";

    std::cout << "Shortest path from 1 to 9:\n";
    auto path = g.getShortestPathSrcToDest(1, 9);
    for (const auto& node : path) {
        std::cout << node << " ";
    }
    std::cout << "\n\n";

    std::cout << "Number of nodes at level 2 from node 1: ";
    std::cout << g.getNumberOfNodeAtGivenLevel(1, 2) << "\n\n";

    std::cout << "All paths from 1 to 9:\n";
    auto allPaths = g.getAllPossibleWaysSrcToDest(1, 9);
    for (const auto& p : allPaths) {
        for (const auto& node : p) {
            std::cout << node << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
