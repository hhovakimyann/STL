#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

template <class T>
class Graph {
private:
    std::unordered_map<T,std::list<T>> adjList;

private:
    void helperPrint(const T& start, std::unordered_set<T>& set);
    void helperLevels(const T& start, std::unordered_set<T>& set);
    void helperComponents(const T& vertex, std::unordered_set<T>& set) const;
    bool helperSrcToDest(const T& src, const T& dest,std::unordered_set<T>&set)const ;
    void helperGetAllPossibleWaysSrcToDest(const T& src, const T& dest, std::unordered_set<T>& map, std::vector<T>& path, std::vector<std::vector<T>>& res) const;
public:
    void addEdge(const T& u, const T& v);
    void printElements(const T& vertex);
    void printLevels(const T& vertex);
    int getNumComponents() const;
    bool canReachFromSourceToDest(const T& src, const T& dest) const ;
    std::vector<T> getShortestPathSrcToDest(const T& src, const T& des);
    int getNumberOfNodeAtGivenLevel(const T& start, int level) const;
    std::vector<std::vector<T>> getAllPossibleWaysSrcToDest(const T& src, const T& dest) const;
};  


#include "impl.tcc"

#endif // UNDIRECTED_GRAPH