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
        onStack[vertex] = true;
        ids[vertex] = low_links[vertex] = ++id;
        st.push(vertex);

        for(const int i : graph[vertex]) {
            if(ids[i] == -1) {
                tarjanHelper(i);
            }
            if(onStack[i]) {
                low_links[vertex] = std::min(low_links[vertex],low_links[i]);
            }
        }
        if(ids[vertex] == low_links[vertex]) {
            std::vector<int> scc;
            while(1) {
                int node = st.top();
                st.pop();
                onStack[node] = false;
                scc.push_back(node);
                if(node == vertex) break;
            }
            sccs.push_back(scc);
        }
    }

    void tarjanAlgorithm() {
        onStack.assign(_v,false);
        ids.assign(_v,-1);
        low_links.assign(_v,-1);
        for(int i = 0; i < _v; ++i) {
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
