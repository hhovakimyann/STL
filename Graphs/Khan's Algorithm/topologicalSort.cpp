#include <iostream>
#include <vector>
#include <queue>

std::vector<int> topologicalSort(const std::vector<std::vector<int>> &graph)
{
    std::vector<int> inDegree(graph.size());
    for(int i = 0; i < graph.size(); ++i) {
        for(const int j: graph[i]) {
            ++inDegree[j];
        }
    }

    std::queue<int> q;
    for(int i = 0; i < inDegree.size(); ++i) {
        if(inDegree[i] == 0) {
            q.push(inDegree[i]);
        }
    }

    std::vector<int> res;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        res.push_back(node);
        for(const int j : graph[node]) {
            --inDegree[j];
            if(inDegree[j] == 0) {
                q.push(j);
            }
        }
    }
    return res.size() == graph.size() ? res : std::vector<int>();
}
int main()
{
    std::vector<std::vector<int>> graph = {
        {1, 2},
        {3},
        {3},
        {4},
        {}};

    std::vector<int> result = topologicalSort(graph);

    if (result.empty())
    {
        std::cout << "Graph has a cycle or is invalid.\n";
    } else
    {
        std::cout << "Topological Sort: ";
        for (int node : result)
        {
            std::cout << node << " ";
        }
        std::cout << "\n";
    }
}