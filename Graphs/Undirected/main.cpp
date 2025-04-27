#include "include.hpp"

int main()
{
    Graph<int> gp(6);
    gp.addEdge(1, 2);
    gp.addEdge(2, 3);
    gp.addEdge(3, 4);
    gp.addEdge(1, 5);
    gp.addEdge(5, 4);

    auto path = gp.getShortestPathSrcToDest(1, 4);
    std::cout << "Shortest path from 1 to 4: ";
    for (int node : path)
        std::cout << node << " ";
    std::cout << "\n";

    Graph<char> g(6);
    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('B', 'D');
    g.addEdge('C', 'D');

    auto allPaths = g.getAllPossibleWaysSrcToDest('A', 'D');
    for (const auto &path : allPaths)
    {
        for (char c : path)
            std::cout << c << " ";
        std::cout << "\n";
    }
}
