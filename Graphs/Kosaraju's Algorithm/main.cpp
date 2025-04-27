#include <iostream>
#include <vector>
#include <stack>

class Graph {
private:
    std::vector<std::vector<int>> graph;
    int _v;
public:

    Graph(int v) : _v(v) , graph(v) {}
    
    void addEdge(int v, int u) {
        if (v < 0 || v >= _v || u < 0 || u >= _v) {
            throw std::out_of_range("Vertex index out of bounds");
        }
        graph[v].push_back(u);
    }
    void dfs(std::vector<bool>& visited, std::stack<int>& st, int vertex) {
        visited[vertex] = true;

        for(const int x : graph[vertex]) {
            if(!visited[x]) {
                dfs(visited,st,x);
            }
        }
        st.push(vertex);
    }
    std::vector<std::vector<int>> transpose() {
        std::vector<std::vector<int>> graphTranspose(_v);
        for(int i = 0; i < _v; i++) {
            for(const int v : graph[i]) {
                graphTranspose[v].push_back(i);
            }
        }
        return graphTranspose;
    }
    void dfs(std::vector<bool>&visited, std::vector<std::vector<int>>& graph,int vertex) {
        visited[vertex] = true;
        std::cout << vertex << " ";

        for(const int x : graph[vertex]) {
            if(!visited[x]) {
                dfs(visited,graph,x);
            }
        }
    }
    void kosarajuAlgorithm() {
        std::vector<bool> visited(_v, false);
        std::stack<int> st;

        for(int i = 0 ; i < _v ; i++) {
            for(const int x : graph[i]) {
                if(!visited[x]) {
                    dfs(visited,st,x);
                }
            }
        }

        std::vector<std::vector<int>> transposeGraph = transpose();
        std::fill(visited.begin(),visited.end(),false);

        while(!st.empty()) {
            int node = st.top();
            st.pop();

            if(!visited[node]) {
                dfs(visited,transposeGraph,node);
                std::cout << std::endl;
            }
        }
    }
};

int main () {
    Graph g(7);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,4);
    g.addEdge(6,5);

    g.kosarajuAlgorithm();
}