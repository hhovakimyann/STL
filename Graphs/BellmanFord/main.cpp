#include <iostream>
#include <vector>

std::vector<int> bellmanFord(std::vector<std::vector<int>>& edges,int v, int start) {
    std::vector<int> dist(v,std::numeric_limits<int>::max());
    dist[start] = 0;

    for(int i = 1; i <= v - 1; ++i) {
        for(const auto& edge : edges) {
            if(std::numeric_limits<int>::max() != dist[edge[0]] && dist[edge[0]] + edge[2] < dist[edge[1]]) {
                dist[edge[1]] = dist[edge[0]] + edge[2];
            }
        }
    }

    for(const auto& edge : edges) {
        if(std::numeric_limits<int>::max() != dist[edge[0]] && dist[edge[0]] + edge[2] < dist[edge[1]]) {
            std::cout << "The Graph have a negative cycle" << std::endl;
            return {};
        }
    }
    return dist;
}
int main () {
    int v = 5;
    std::vector<std::vector<int>> edges = {
        {1, 3, 2}, 
        {4, 3, -1},
        {2, 4, 1}, 
        {1, 2, 1},
        {0, 1, 5} 
    };


    std::vector<int> dist = bellmanFord(edges,v,0);

    for(int i : dist) {
        std::cout << i << " ";
    }
    std::cout << std::endl;


}