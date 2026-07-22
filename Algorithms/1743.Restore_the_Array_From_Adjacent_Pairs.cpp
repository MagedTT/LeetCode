// Problem Link: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
private:
    void add_edge(unordered_map<int, vector<int>> &graph, int from, int to)
    {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    void dfs(unordered_map<int, vector<int>> &graph, int node, vector<int> &ret, unordered_set<int> &visited)
    {
        visited.insert(node);
        ret.push_back(node);

        for (auto &a : graph[node])
        {
            if (!visited.count(a))
            {
                dfs(graph, a, ret, visited);
            }
        }
    }

public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        unordered_map<int, vector<int>> graph;

        for (auto &a : adjacentPairs)
            add_edge(graph, a[0], a[1]);

        int node = -1;
        for (auto &a : graph)
            if (a.second.size() == 1)
                node = a.first;

        unordered_set<int> visited;
        vector<int> ret;

        dfs(graph, node, ret, visited);

        return ret;
    }
};

int main()
{
    return 0;
}