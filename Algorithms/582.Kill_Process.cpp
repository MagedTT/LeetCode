// Problem Link: https://leetcode.com/problems/kill-process/description/

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef unordered_map<int, unordered_set<int>> graph;

void add_edge(graph &graph, int from, int to)
{
    graph[from].insert(to);
}

void dfs(graph &graph, int node, unordered_set<int> &visited)
{
    visited.insert(node);

    for (auto &a : graph[node])
    {
        if (!visited.count(a))
            dfs(graph, a, visited);
    }
}

vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill)
{
    graph graph;

    int sz = (int)pid.size();
    for (int i = 0; i < sz; ++i)
        add_edge(graph, ppid[i], pid[i]);

    unordered_set<int> visited;

    dfs(graph, kill, visited);

    return vector<int>(visited.begin(), visited.end());
}

int main()
{
    // Test-Case
    vector<int> pid{5234, 2234, 6234, 3234, 123123, 1234, 4234};
    vector<int> ppid{0, 5234, 2234, 2234, 5234, 5234, 1234};

    int k;
    cin >> k;

    vector<int> result = killProcess(pid, ppid, k);

    for (auto &a : result)
        cout << a << ' ';
    cout << '\n';
    return 0;
}