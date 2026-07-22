// Problem Link: https://leetcode.com/problems/employee-importance/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};

typedef unordered_map<int, unordered_set<int>> graph;

void add_edge(graph &graph, int from, int to)
{
    graph[from].insert(to);
}

graph build_graph(vector<Employee *> &employees)
{
    graph graph;
    for (auto &employee : employees)
    {
        for (auto &subordinate : employee->subordinates)
        {
            add_edge(graph, employee->id, subordinate);
        }
    }

    return graph;
}

void dfs(graph &graph, int node, unordered_set<int> &visited)
{
    visited.insert(node);

    for (auto &a : graph[node])
    {
        if (!visited.count(a))
        {
            dfs(graph, a, visited);
        }
    }
}

class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        graph graph = build_graph(employees);

        unordered_set<int> visited;

        dfs(graph, id, visited);

        int ret = 0;
        for (auto &employee : employees)
        {
            if (visited.count(employee->id))
            {
                ret += employee->importance;
            }
        }

        return ret;
    }
};

int main()
{
    return 0;
}