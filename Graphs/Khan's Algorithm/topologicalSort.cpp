#include <iostream>
#include <vector>
#include <queue>

std::vector<int> topologicalSort(const std::vector<std::vector<int>> &graph)
{
    std::vector<int> inDegree(graph.size());

    for (int i = 0; i < graph.size(); i++)
    {
        for (int j : graph[i])
        {
            ++inDegree[j];
        }
    }

    std::vector<int> res;
    std::queue<int> q;

    for (int i = 0; i < graph.size(); i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        res.push_back(vertex);

        for (int j : graph[vertex])
        {
            --inDegree[j];
            if (inDegree[j] == 0)
            {
                q.push(j);
            }
        }
    }

    if (res.size() != graph.size())
    {
        return {};
    }

    return res;
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