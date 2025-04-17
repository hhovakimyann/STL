#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

template <class T>
class Graph {
private:
    std::unordered_map<T, std::list<T>> adjList;

private:
    void helperPrint(const T& start, std::unordered_set<T>& visited) const;
    void helperLevels(const T& start, std::unordered_set<T>& visited) const;
    void helperComponents(const T& vertex, std::unordered_set<T>& visited) const;
    bool helperSrcToDest(const T& src, const T& dest, std::unordered_set<T>& visited) const;
    void helperGetAllPossibleWaysSrcToDest(const T& src, const T& dest, std::unordered_set<T>& visited,
                                           std::vector<T>& path, std::vector<std::vector<T>>& result) const;

public:
    void addEdge(const T& u, const T& v);
    void printElements(const T& vertex) const;
    void printLevels(const T& vertex) const;
    int getNumComponents() const;
    bool canReachFromSourceToDest(const T& src, const T& dest) const;
    std::vector<T> getShortestPathSrcToDest(const T& src, const T& dest) const;
    int getNumberOfNodeAtGivenLevel(const T& start, int level) const;
    std::vector<std::vector<T>> getAllPossibleWaysSrcToDest(const T& src, const T& dest) const;
};

#include "impl.tcc"

#endif // DIRECTED_GRAPH