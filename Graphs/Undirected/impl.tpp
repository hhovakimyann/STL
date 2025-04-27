#include "include.hpp"

template <class T>
void Graph<T>::addEdge(const T& u, const T& v)  {
    adjList[u].push_back(v);
    adjList[v].push_back(u);  
}

template <class T>
void Graph<T>::printElements(const T& vertex) const {
    std::vector<bool> visited(v, false);
    helperPrint(vertex, visited);
    
    for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
            helperPrint(i, visited);
        }
    }
}

template <class T>
void Graph<T>::helperPrint(const T& vertex, std::vector<bool>& visited) const {
    visited[vertex] = true;
    std::cout << vertex << " ";

    for (const T& node : adjList[vertex]) {
        if (!visited[node]) {
            helperPrint(node, visited);
        }
    }
}

template <class T>
void Graph<T>::printLevels(const T& vertex) const {
    std::vector<bool> visited(v, false);
    helperLevels(vertex, visited);

    for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
            helperLevels(i, visited);
        }
    }
}

template <class T>
void Graph<T>::helperLevels(const T& vertex, std::vector<bool>& visited) const {
    std::queue<T> q;
    q.push(vertex);
    visited[vertex] = true;

    while (!q.empty()) {
        T node = q.front();
        q.pop();
        std::cout << node << " ";

        for (const T& neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

template <class T>
int Graph<T>::getNumComponents() const {
    std::vector<bool> visited(v, false);
    int count = 0;
    for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
            helperComponents(i, visited);
            count++;
        }
    }
    return count;
}

template <class T>
void Graph<T>::helperComponents(const T& vertex, std::vector<bool>& visited) const {
    visited[vertex] = true;
    for (const T& node : adjList[vertex]) {
        if (!visited[node]) {
            helperComponents(node, visited);
        }
    }
}

template <class T>
bool Graph<T>::canReachFromSourceToDest(const T& src, const T& dest) const {
    std::vector<bool> visited(v, false);
    std::queue<T> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        T current = q.front();
        q.pop();
        if (current == dest) return true;
        for (const T& neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return false;
}

template <class T>
std::vector<T> Graph<T>::getShortestPathSrcToDest(const T& src, const T& dest) {
    std::vector<bool> visited(v, false);
    std::vector<T> parent(v);
    std::queue<T> q;
    q.push(src);
    visited[src] = true;

    T current;
    while (!q.empty()) {
        current = q.front();
        q.pop();
        if (current == dest) break;
        for (const T& neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    if (!visited[dest]) return {};

    std::vector<T> path;
    T at = dest;
    while (at != src) {
        path.push_back(at);
        at = parent[at];
    }
    path.push_back(src);
    std::reverse(path.begin(), path.end());
    return path;
}

template <class T>
int Graph<T>::getNumberOfNodeAtGivenLevel(const T& vertex, int level) const {
    std::vector<bool> visited(v, false);
    std::queue<T> q;
    q.push(vertex);
    visited[vertex] = true;

    int currentLevel = 0;
    while (!q.empty()) {
        int size = q.size();
        if (currentLevel == level) return size;
        for (int i = 0; i < size; ++i) {
            T node = q.front();
            q.pop();
            for (const T& neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        currentLevel++;
    }
    return -1;
}

template <class T>
std::vector<std::vector<T>> Graph<T>::getAllPossibleWaysSrcToDest(const T& src, const T& dest) const {
    std::vector<std::vector<T>> res;
    std::vector<bool> visited(v, false);
    std::vector<T> path;
    helperGetAllPossibleWaysSrcToDest(src, dest, visited, path, res);
    return res;
}

template <class T>
void Graph<T>::helperGetAllPossibleWaysSrcToDest(const T& src, const T& dest, std::vector<bool>& visited, std::vector<T>& path, std::vector<std::vector<T>>& res) const {
    visited[src] = true;
    path.push_back(src);

    if (src == dest) {
        res.push_back(path);
    } else {
        for (const T& neighbor : adjList[src]) {
            if (!visited[neighbor]) {
                helperGetAllPossibleWaysSrcToDest(neighbor, dest, visited, path, res);
            }
        }
    }

    path.pop_back();
    visited[src] = false;
}