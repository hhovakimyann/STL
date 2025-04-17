#include "include.hpp"

template <class T>
void Graph<T>::addEdge(const T &v, const T &u)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}
template <class T>
void Graph<T>::printElements(const T &vertex)
{
    std::unordered_set<T> set;
    helperPrint(vertex, set);
    std::cout << std::endl;
}
template <class T>
void Graph<T>::helperPrint(const T &start, std::unordered_set<T> &set)
{
    set.insert(start);

    if (adjList.count(start))
    {
        std::cout << start << " ";
    }
    else
    {
        std::cout << "Given wrong Vertex";
    }

    for (const auto &vertex : adjList[start])
    {
        if (!set.count(vertex))
        {
            helperPrint(vertex, set);
        }
    }
}

template <class T>
void Graph<T>::printLevels(const T &start)
{
    std::unordered_set<T> set;
    helperLevels(start, set);
    std::cout << std::endl;
}

template <class T>
void Graph<T>::helperLevels(const T &vertex, std::unordered_set<T> &set)
{
    std::queue<T> queue;
    queue.push(vertex);
    set.insert(vertex);

    while (!queue.empty())
    {
        T &elem = queue.front();
        queue.pop();
        std::cout << elem << " ";

        for (const auto &v : adjList[elem])
        {
            if (!set.count(v))
            {
                set.insert(v);
                queue.push(v);
            }
        }
    }
}

template <class T>
int Graph<T>::getNumComponents() const
{
    int components = 0;
    std::unordered_set<T> set;

    for (const auto &line : adjList)
    {
        const T &vertex = line.first;
        if (!set.count(vertex))
        {
            helperComponents(vertex, set);
            components++;
        }
    }
    return components;
}

template <class T>
void Graph<T>::helperComponents(const T &vertex, std::unordered_set<T> &set) const
{
    set.insert(vertex);

    for (const auto &v : adjList.at(vertex))
    {
        if (!set.count(v))
        {
            helperComponents(v, set);
        }
    }
}

template <class T>
bool Graph<T>::canReachFromSourceToDest(const T &src, const T &dest) const
{
    std::unordered_set<T> set;
    return helperSrcToDest(src, dest, set);
}
template <class T>
bool Graph<T>::helperSrcToDest(const T &src, const T &dest, std::unordered_set<T> &set) const
{

    if (src == dest)
        return true;

    set.insert(src);
    for (const auto &vertex : adjList.at(src))
    {
        if (!set.count(vertex))
        {
            if (helperSrcToDest(vertex, dest, set))
            {
                return true;
            }
        }
    }
    return false;
}

template <class T>
std::vector<T> Graph<T>::getShortestPathSrcToDest(const T &src, const T &dest)
{
    std::vector<T> res;
    std::unordered_set<T> visited;
    std::queue<T> q;
    std::unordered_map<T, T> parent;

    visited.insert(src);
    q.push(src);
    parent[src] = src;

    while (!q.empty())
    {
        const T &current = q.front();
        q.pop();

        if (current == dest)
            break;
        for (const auto &vertex : adjList.at(current))
        {
            if (!visited.count(vertex))
            {
                parent[vertex] = current;
                visited.insert(vertex);
                q.push(vertex);
            }
        }
    }

    if (!visited.count(dest))
    {
        return res;
    }

    for (T at = dest; at != src; at = parent[at])
    {
        res.push_back(at);
    }

    res.push_back(src);
    std::reverse(res.begin(), res.end());
    return res;
}

template <class T>
int Graph<T>::getNumberOfNodeAtGivenLevel(const T &start, int level) const
{
    std::vector<std::vector<T>> levels;
    std::queue<T> q;
    std::unordered_set<T> set;

    q.push(start);
    set.insert(start);
    levels.push_back({start});
    int row = 0;

    while (!q.empty())
    {
        int size = q.size();
        std::vector<T> currentLevel;

        row++;
        for (int i = 0; i < size; i++)
        {
            const T &current = q.front();
            q.pop();
            for (const auto &vertex : adjList.at(current))
            {

                if (!set.count(vertex))
                {
                    q.push(vertex);
                    set.insert(vertex);
                    currentLevel.push_back(vertex);
                }
            }
        }
        if (!currentLevel.empty())
            levels.push_back(currentLevel);

        if (row == level) {
            return levels[row].size();
        }
    }
    return -1;
}
template <class T>
void Graph<T>::helperGetAllPossibleWaysSrcToDest(
    const T& src,
    const T& dest,
    std::unordered_set<T>& visited,
    std::vector<T>& path,
    std::vector<std::vector<T>>& res) const
{
    visited.insert(src);
    path.push_back(src);

    if (src == dest) {
        res.push_back(path);
    } else {
        for (const auto& vertex : adjList.at(src)) {
            if (!visited.count(vertex)) {
                helperGetAllPossibleWaysSrcToDest(vertex, dest, visited, path, res);
            }
        }
    }


    path.pop_back();
    visited.erase(src);
}

template <class T>
std::vector<std::vector<T>> Graph<T>::getAllPossibleWaysSrcToDest(const T& src, const T& dest) const
{
    std::unordered_set<T> visited;
    std::vector<T> path;
    std::vector<std::vector<T>> res;

    helperGetAllPossibleWaysSrcToDest(src, dest, visited, path, res);
    return res;
}

