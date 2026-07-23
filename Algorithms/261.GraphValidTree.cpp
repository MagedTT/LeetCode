
// Problem Link: https://leetcode.com/problems/graph-valid-tree/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int inf = 1e9;

    typedef vector<vector<int>> graph;

    void add_edge(graph &graph, int from, int to)
    {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    bool bfs(graph &graph, int node, vector<int> &dist, vector<int> &parent)
    {
        queue<int> q;
        q.push(node);
        dist[node] = 0;

        for (int level = 0, sz = 1; !q.empty(); ++level, sz = (int)q.size())
        {
            while (sz--)
            {
                int cur = q.front();
                q.pop();

                for (auto &a : graph[cur])
                {
                    if (a == parent[cur])
                        continue;

                    if (dist[a] != inf)
                        return true;

                    dist[a] = level + 1;
                    parent[a] = cur;
                    q.push(a);
                }
            }
        }

        return false;
    }

public:
    bool validTree(int nodes, vector<vector<int>> &edges)
    {
        if ((int)edges.size() != (nodes - 1))
            return false;

        graph graph(nodes);
        for (auto &a : edges)
            add_edge(graph, a[0], a[1]);

        vector<int> parent(nodes, -1);
        vector<int> dist(nodes, inf);

        bool first = true;
        for (int i = 0; i < nodes; ++i)
            if (dist[i] == inf)
            {
                if (first)
                {
                    first = false;
                    if (bfs(graph, i, dist, parent))
                        return false;
                }
                else
                    return false;
            }

        return true;
    }
};

int main()
{
    return 0;
}