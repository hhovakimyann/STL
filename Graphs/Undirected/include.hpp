#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

template <class T>
class Graph {
private:
    int v;
    std::vector<std::vector<T>> adjList;
private:
    void helperPrint(const T& vertex,std::vector<bool>& visited) const;
    void helperLevels(const T& vertex, std::vector<bool>& visited) const;
    void helperComponents(const T& vertex, std::vector<bool>& visited) const;
    bool helperSrcToDest(const T& src, const T& dest,std::vector<bool>& visited)const ;
    void helperGetAllPossibleWaysSrcToDest(const T& src, const T& dest, std::vector<bool>& visited, std::vector<T>& path, std::vector<std::vector<T>>& res) const;
public:
    int getVertexCount() {
        return v;
    }
    Graph(int vertex) : v(vertex), adjList(vertex) {}
    void addEdge(const T& u, const T& v) ;
    void printElements(const T& vertex) const;
    void printLevels(const T& vertex) const;
    int getNumComponents() const;
    bool canReachFromSourceToDest(const T& src, const T& dest) const ;
    std::vector<T> getShortestPathSrcToDest(const T& src, const T& des);
    int getNumberOfNodeAtGivenLevel(const T& start, int level) const;
    std::vector<std::vector<T>> getAllPossibleWaysSrcToDest(const T& src, const T& dest) const;
};  

#include "impl.tpp"

#endif // UNDIRECTED_GRAPH