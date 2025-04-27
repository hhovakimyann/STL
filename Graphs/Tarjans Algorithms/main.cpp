#include <iostream>
#include <vector>
#include <stack>

class Graph {
private:
    std::vector<std::vector<int>> graph;
    int _v;

private:
    std::vector<std::vector<int>> sccs;
    std::vector<int> ids;
    std::vector<int> low_links;
    std::vector<bool> onStack;
    std::stack<int> st;
    int id = 0;
public:
    Graph(int vertex) : _v(vertex), graph(vertex) {}

    void addEdge(int vertex, int u) {
        if (vertex < 0 || vertex >= _v || u < 0 || u >= _v) {
            throw std::out_of_range("Vertex index out of bounds");
        }

        graph[vertex].push_back(u);
    }

    void tarjanHelper(int vertex) {
        ids[vertex] = low_links[vertex] = id++;
        onStack[vertex] = true;
        st.push(vertex);
        for(const int x : graph[vertex]) {
            if(ids[x] == -1) {
                tarjanHelper(x);
                low_links[vertex] = std::min(low_links[vertex], low_links[x]);
            }
            if(onStack[x]) {
                low_links[vertex] = std::min(low_links[x], ids[x]);
            }
        }

        if(ids[vertex] == low_links[vertex]) {
            std::vector<int> scc;
            while(1) {
                int node = st.top();
                st.pop();
                scc.push_back(node);
                onStack[node] = false;
                if(vertex == node) break;
            } 
            sccs.push_back(scc);
        }
    }

    void tarjanAlgorithm() {
        ids.assign(_v,-1);
        low_links.assign(_v,-1);
        onStack.assign(_v,false);
        for(int i = 0; i < _v; i++) {
            if(ids[i] == -1) {
                tarjanHelper(i);
            }
        }
    } 

    void printSccs() {
        for(int i = 0; i < sccs.size(); i++) {
            for(const int x : sccs[i]) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph g(7);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,4);
    g.addEdge(6,5);

    g.tarjanAlgorithm();
    g.printSccs();
}
