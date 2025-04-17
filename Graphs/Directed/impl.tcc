#include "include.hpp"

template <class T>
void Graph<T>::addEdge(const T& u, const T& v) {
    adjList[u].push_back(v);
    adjList[v];
}

template <class T>
void Graph<T>::printElements(const T& vertex) const {
    std::unordered_set<T> visited;
    helperPrint(vertex, visited);
}

template <class T>
void Graph<T>::helperPrint(const T& start, std::unordered_set<T>& visited) const {
    if (adjList.find(start) == adjList.end()) return;
    visited.insert(start);
    std::cout << start << " ";

    for (const auto& vertex : adjList.at(start)) {
        if (!visited.count(vertex)) {
            helperPrint(vertex, visited);
        }
    }
}

template <class T>
void Graph<T>::printLevels(const T& vertex) const {
    std::unordered_set<T> visited;
    helperLevels(vertex, visited);
}

template <class T>
void Graph<T>::helperLevels(const T& vertex, std::unordered_set<T>& visited) const {
    if (adjList.find(vertex) == adjList.end()) return;
    std::queue<T> queue;
    queue.push(vertex);
    visited.insert(vertex);

    while (!queue.empty()) {
        const T& current = queue.front();
        queue.pop();
        std::cout << current << " ";
        if (adjList.find(current) != adjList.end()) {
            for (const auto& v : adjList.at(current)) {
                if (!visited.count(v)) {
                    queue.push(v);
                    visited.insert(v);
                }
            }
        }
    }
}

template <class T>
int Graph<T>::getNumComponents() const {
    int components = 0;
    std::unordered_set<T> visited;

    for (const auto& pair : adjList) {
        const T& node = pair.first;
        if (!visited.count(node)) {
            helperComponents(node, visited);
            components++;
        }
    }
    return components;
}

template <class T>
void Graph<T>::helperComponents(const T& start, std::unordered_set<T>& visited) const {
    if (adjList.find(start) == adjList.end()) return;
    visited.insert(start);

    for (const auto& v : adjList.at(start)) {
        if (!visited.count(v)) {
            helperComponents(v, visited);
        }
    }
}

template <class T>
bool Graph<T>::canReachFromSourceToDest(const T& src, const T& dest) const {
    std::unordered_set<T> visited;
    return helperSrcToDest(src, dest, visited);
}

template <class T>
bool Graph<T>::helperSrcToDest(const T& src, const T& dest, std::unordered_set<T>& visited) const {
    if (adjList.find(src) == adjList.end()) return false;
    if (src == dest) return true;

    visited.insert(src);

    for (const auto& vertex : adjList.at(src)) {
        if (!visited.count(vertex)) {
            if (helperSrcToDest(vertex, dest, visited)) {
                return true;
            }
        }
    }
    return false;
}

template <class T>
std::vector<T> Graph<T>::getShortestPathSrcToDest(const T& src, const T& dest) const {
    std::vector<T> path;
    std::unordered_map<T, T> parent;
    std::unordered_set<T> visited;
    std::queue<T> queue;

    if (adjList.find(src) == adjList.end() || adjList.find(dest) == adjList.end()) {
        return path;
    }
    queue.push(src);
    visited.insert(src);
    parent[src] = src;

    while (!queue.empty()) {
        const T& current = queue.front();
        queue.pop();

        if (current == dest) break;
        if (adjList.find(current) != adjList.end()) {
            for (const auto& neighbor : adjList.at(current)) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    parent[neighbor] = current;
                    queue.push(neighbor);
                }
            }
        }
    }

    if (!visited.count(dest)) return path;

    for (T at = dest; at != src; at = parent[at]) {
        path.push_back(at);
    }
    path.push_back(src);
    std::reverse(path.begin(), path.end());

    return path;
}

template <class T>
int Graph<T>::getNumberOfNodeAtGivenLevel(const T& start, int level) const {
    if (level < 0) return 0;

    std::queue<std::pair<T, int>> queue;
    std::unordered_set<T> visited;

    queue.push({start, 0});
    visited.insert(start);

    int count = 0;

    while (!queue.empty()) {
        auto [current, currentLevel] = queue.front();
        queue.pop();

        if (currentLevel == level) {
            count++;
        }

        if (adjList.find(current) != adjList.end()) {
            for (const auto& neighbor : adjList.at(current)) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    queue.push({neighbor, currentLevel + 1});
                }
            }
        }
    }

    return count;
}

template <class T>
std::vector<std::vector<T>> Graph<T>::getAllPossibleWaysSrcToDest(const T& src, const T& dest) const {
    std::vector<std::vector<T>> result;
    std::vector<T> path;
    std::unordered_set<T> visited;
    helperGetAllPossibleWaysSrcToDest(src, dest, visited, path, result);
    return result;
}

template <class T>
void Graph<T>::helperGetAllPossibleWaysSrcToDest(const T& src, const T& dest,
                                                std::unordered_set<T>& visited,
                                                std::vector<T>& path,
                                                std::vector<std::vector<T>>& result) const {
    visited.insert(src);
    path.push_back(src);

    if (src == dest) {
        result.push_back(path);
    } else {
        if (adjList.find(src) != adjList.end()) {
            for (const auto& neighbor : adjList.at(src)) {
                if (!visited.count(neighbor)) {
                    helperGetAllPossibleWaysSrcToDest(neighbor, dest, visited, path, result);
                }
            }
        }
    }

    path.pop_back();
    visited.erase(src);
}