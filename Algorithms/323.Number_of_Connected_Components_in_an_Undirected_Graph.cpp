// Problem Link: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef unordered_map<int, vector<int>> graph;

void add_edge(graph &graph, int from, int to)
{
    graph[from].push_back(to);
}

void dfs(graph &graph, int node, vector<bool> &visited)
{
    visited[node] = true;

    for (auto &a : graph[node])
        if (!visited[a])
            dfs(graph, a, visited);
}

class Solution
{
public:
    int countComponents(int nodes, vector<vector<int>> &edges)
    {
        graph graph;
        for (auto &a : edges)
            add_edge(graph, a[0], a[1]);

        vector<bool> visited(nodes);
        int ret = 0;
        for (int i = 0; i < nodes; ++i)
        {
            if (!visited[i])
            {
                ++ret;
                dfs(graph, i, visited);
            }
        }

        return ret;
    }
};

int main()
{
    int n = 5;
    vector<vector<int>> edges{{0, 1}, {1, 2}, {3, 4}};
    // vector<vector<int>> edges{{0, 1}, {1, 2}, {2, 3}, {3, 4}};

    Solution solution;

    int result = solution.countComponents(n, edges);

    cout << result << '\n';
    return 0;
}