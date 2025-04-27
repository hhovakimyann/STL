#ifndef WEIGHTED_GRAPH
#define WEIGHTED_GRAPH

#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <queue>
#include <stack>

template <class T> 
class Graph {
private:
    std::vector<std::vector<std::pair<T, double>>> graph;
    int _v;

private:
    void helpPrintGraph(std::vector<bool>& visited, const T& vertex) const;
    void helpPrintLevels(std::vector<bool>& visited, const T& vertex) const;
    void helperGetNumberComponents(std::vector<bool>& visited, const T& vertex) const;
    bool helperCanReachFromSrcToDest(const T& src, const T& dest, std::vector<bool>& visited) const;
public:
    Graph(int vertex_num);
    void addEdge(const T& v, const T& u, double weight); 
    void printGraph() const;
    void printLevels() const;
    int getNumComponents() const;
    bool canReachFromSourceToDest(const T& src, const T& dest) const;
    std::vector<T> getShortestPathSrcToDest(const T& src, const T& dest) const;

};

#include "impl.tpp"

#endif // WEIGHTED_GRAPH