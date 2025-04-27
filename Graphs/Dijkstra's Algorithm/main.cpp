#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <limits>
#include <exception>

class Graph
{
private:
    std::vector<std::vector<std::pair<int, double>>> graph;
    int _v;

public:
    Graph(int v) : _v(v), graph(v) {}

    void addEdge(int v, int u,double weight) {
        if (v < 0 || v >= _v || u < 0 || u >= _v)
        {
            throw std::out_of_range("Vertex index out of bounds");
        }
        graph[v].push_back(std::make_pair(u,weight));
    }

    std::vector<double> dijkstraAlgorithm(int start) {
        std::vector<double> dist(_v, std::numeric_limits<double>::max());
        dist[start] = 0.0;

        std::priority_queue<std::pair<double,int>, std::vector<std::pair<double,int>>, std::greater<std::pair<double,int>>> pq;
        pq.push({0.0,start});

        
        while(!pq.empty()) {
            auto [d,u] = pq.top();
            pq.pop();
            if(dist[u] < d) continue;
            for(const auto& [vertex, weight] : graph[u]) {
                if(dist[vertex] > dist[u] + weight) {
                    dist[vertex] = dist[u] + weight;
                    pq.push({dist[vertex],vertex});
                }
            }
        }
        return dist;
    }
}; 

int main() {
    {
        Graph g(5);
        g.addEdge(0, 1, 2.0);
        g.addEdge(0, 2, 4.0);
        g.addEdge(1, 2, 1.0);
        g.addEdge(1, 3, 7.0);
        g.addEdge(2, 4, 3.0);
        g.addEdge(3, 4, 1.0);

        auto distances = g.dijkstraAlgorithm(0);

        std::vector<double> expected = {0.0, 2.0, 3.0, 9.0, 6.0};

        for (size_t i = 0; i < expected.size(); ++i) {
            if (distances[i] != expected[i]) {
                std::cout << "Test 1 Failed at vertex " << i << ": Expected " << expected[i] << ", got " << distances[i] << "\n";
            }
        }
    }

    {
        Graph g(3);
        g.addEdge(0, 1, 5.0);

        auto distances = g.dijkstraAlgorithm(0);

        if (distances[0] != 0.0 || distances[1] != 5.0 || distances[2] != std::numeric_limits<double>::max()) {
            std::cout << "Test 2 Failed: Unexpected distances\n";
        }
    }

    {
        Graph g(1);

        auto distances = g.dijkstraAlgorithm(0);

        if (distances[0] != 0.0) {
            std::cout << "Test 3 Failed: Expected 0.0, got " << distances[0] << "\n";
        }
    }

    {
        bool exceptionThrown = false;
        Graph g(2);
        try {
            g.addEdge(0, 3, 1.0); 
        } catch (const std::out_of_range&) {
            exceptionThrown = true;
        }

        if (!exceptionThrown) {
            std::cout << "Test 4 Failed: Exception was not thrown for invalid edge\n";
        }
    }

    std::cout << "All tests completed.\n";
}
