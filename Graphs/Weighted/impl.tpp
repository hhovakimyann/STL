#include "include.hpp"

template <class T>
Graph<T>::Graph(int vertex_num) : _v(vertex_num), graph(_v) {
    static_assert(std::is_integral<T>::value, "Graph vertex type must be an integer type!");
}

template <class T>
void Graph<T>::addEdge(const T& v, const T& u, double weight) { 
    if (v >= _v || u >= _v || v < 0 || u < 0) {
        throw std::out_of_range("Vertex index out of range");
    }
    graph[v].push_back(std::make_pair(u, weight));
}


template <class T>
void Graph<T>::printGraph() const {
    std::vector<bool> visited(_v, false);
    for(int i = 0; i < _v; i++) {
        if(!visited[i]) {
            helpPrintGraph(visited,i);
        }
    }
}
template <class T>
void Graph<T>::helpPrintGraph(std::vector<bool>& visited,const T& vertex) const {
    visited[vertex] = true;
    std::cout << vertex << " ";

    for(const T& x : graph[vertex]) {
        if(!visited[x]) {
            helpPrintGraph(visited,x);
        }
    }
}
template <class T>
void Graph<T>::printLevels() const {
    std::vector<bool> visited(_v,false);
    for(int i = 0 ; i < _v; i++) {
        if(!visited[i]) {
            helpPrintLevels(visited,i);
        }
    }
}
template <class T>
void Graph<T>::helpPrintLevels(std::vector<bool>& visited, const T& vertex) const {
    std::queue<T> q;
    visited[vertex] = true;
    q.push(vertex);

    while(!q.empty()) {
        T& node = q.front();
        q.pop();
        std::cout << x << " ";
        for(const T& x : graph[node]) {
            if(!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }

    std::cout << std::endl;

}

template <class T>
int Graph<T>::getNumComponents() const {
    std::vector<bool> visited(_v, false);
    int count = 0;
    for(int i = 0; i < _v; i++) {
        if(!visited[i]) {
            helperGetNumberComponents(visited,i);
            count++;
        }
    }
    return count;
}
template <class T>
void Graph<T>::helperGetNumberComponents(std::vector<bool>& visited, const T& vertex) const {
    visited[vertex] = true;
    for(const T& x : graph[vertex]) {
        if(!visited[vertex]) {
            helperGetNumberComponents(visited,vertex);
        }
    }
} 

template <class T>
bool Graph<T>::canReachFromSourceToDest(const T& src, const T& dest) const {
    std::vector<bool> visited(_v, false);
    return helperCanReachFromSrcToDest(src,dest,visted);
}
template <class T>
bool Graph<T>::helperCanReachFromSrcToDest(const T& src, const T& dest, std::vector<bool>& visited) const {
    if(src == dest) {
        return true;
    }

    visited[src] = true;
    for(const T& x : graph[src]) {
        if(!visited[x]) {
            if(helperCanReachFromSrcToDest(x,dest,visited)) {
                return true;
            }
        }
    }

    return false;
}
template <class T>
std::vector<T> Graph<T>::getShortestPathSrcToDest(const T& src, const T& dest) const {
    std::vector<double> dist(_v,std::numeric_limits<double>::infinity());
    std::vector<int> prev(-1); 
    
    std::priority_queue<std::pair<double,T>, std::vector<std::pair<double,T>,std::greater<std::pair<double,T>>> qp;

    dist[srcIdx] = 0.0;
    pq.push(0.0,srcIdx);

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        qp.pop();

        if(d > dist[u]) continue;

        for(const auto& [v, weight] : graph[u]) {
            if(dist[v] + weight  < dist[u]) {
                dist[v] = dist[u] + weight;
                prev[u] = v;
                pq.push(dist[v],v);
            }
        }
    }

    std::vector<T> path;
    if (dist[dest] == std::numeric_limits<double>::infinity()) {
        return {};
    }

    for(T at = dest; at != src; at = prev[at]) {
        path.push_back(at);
    }

    path.push_back(src);
    std::reverse(path.begin(), path.end());
    return path;
}
