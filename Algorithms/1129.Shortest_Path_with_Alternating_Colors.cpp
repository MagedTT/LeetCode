// Problem Link: https://leetcode.com/problems/shortest-path-with-alternating-colors/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    const int INF = 1e9;
    const int RED = 0;
    const int BLUE = 1;
    void add_edge(vector<vector<pair<int, int>>> &graph, int from, int to, int color)
    {
        graph[from].push_back({to, color});
    }

public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<vector<pair<int, int>>> graph(n);

        for (auto &a : redEdges)
            add_edge(graph, a[0], a[1], RED);

        for (auto &a : blueEdges)
            add_edge(graph, a[0], a[1], BLUE);

        vector<int> ret(n, -1);
        ret[0] = 0;

        queue<pair<int, int>> q;
        q.push({0, RED});
        q.push({0, BLUE});

        vector<vector<int>> dist(n, vector<int>(2, INF));

        dist[0][RED] = 0;
        dist[0][BLUE] = 0;

        for (int level = 0, sz = (int)q.size(); !q.empty(); ++level, sz = (int)q.size())
        {
            while (sz--)
            {
                int cur = q.front().first;
                int color = q.front().second;
                q.pop();

                for (auto &a : graph[cur])
                {
                    if (color != a.second && dist[a.first][a.second] == INF)
                    {
                        q.push({a.first, a.second});
                        dist[a.first][a.second] = level + 1;

                        if (ret[a.first] == -1)
                            ret[a.first] = level + 1;
                    }
                }
            }
        }

        return ret;
    }
};

int main()
{
    return 0;
}