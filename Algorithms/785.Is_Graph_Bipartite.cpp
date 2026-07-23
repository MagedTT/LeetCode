// Problem Link: https://leetcode.com/problems/is-graph-bipartite/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    bool isValid = true;

    void dfs(vector<vector<int>> &graph, int node, vector<int> &visited, int flag)
    {
        visited[node] = flag;

        for (auto &a : graph[node])
        {
            if (visited[a])
            {
                if (visited[a] == flag)
                {
                    isValid = false;
                    return;
                }
            }
            else
            {
                if (flag == INT_MIN)
                    dfs(graph, a, visited, INT_MAX);
                else
                    dfs(graph, a, visited, INT_MIN);
            }
        }
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> visited((int)graph.size());

        for (int i = 0; i < (int)graph.size(); ++i)
        {
            if (visited[i] != INT_MIN && visited[i] != INT_MAX)
            {
                isValid = true;
                dfs(graph, i, visited, INT_MIN);

                if (!isValid)
                    return false;
            }
        }

        return isValid;
    }
};

int main()
{
    return 0;
}