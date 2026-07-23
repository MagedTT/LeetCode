// Problem Link: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
    void add_edge(unordered_map<int, vector<pair<int, pair<int, int>>>> &graph, int from, int to)
    {
        graph[from].push_back({to, {from, to}});
        graph[to].push_back({from, {from, to}});
    }

    void dfs(unordered_map<int, vector<pair<int, pair<int, int>>>> &graph, int node, unordered_set<int> &visited, int &ret)
    {
        visited.insert(node);

        for (auto &a : graph[node])
        {
            if (!visited.count(a.first))
            {
                ret += node == a.second.first;
                dfs(graph, a.first, visited, ret);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        --n;
        unordered_map<int, vector<pair<int, pair<int, int>>>> graph;
        for (int i = 0; i < n; ++i)
            add_edge(graph, connections[i][0], connections[i][1]);

        int ret = 0;
        unordered_set<int> visited;

        dfs(graph, 0, visited, ret);

        return ret;
    }
};

int main()
{
    return 0;
}