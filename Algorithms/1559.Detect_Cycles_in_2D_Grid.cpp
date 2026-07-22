// Problem Link: https://leetcode.com/problems/detect-cycles-in-2d-grid/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, 1, 0, -1};
    bool flag = false;

    bool isValid(vector<vector<char>> &grid, int i, int j)
    {
        return 0 <= i && i < (int)grid.size() && 0 <= j && j < (int)grid[0].size();
    }

    void dfs(vector<vector<char>> &grid, int i, int j, int parent_i, int parent_j, char &c, vector<vector<bool>> &visited)
    {
        if (flag)
            return;

        if (visited[i][j])
        {
            flag = true;
            return;
        }

        visited[i][j] = true;

        for (int d = 0; d < 4; ++d)
        {
            int ni = i + di[d];
            int nj = j + dj[d];

            if (!isValid(grid, ni, nj) || grid[ni][nj] != c || ni == parent_i && nj == parent_j)
                continue;

            dfs(grid, ni, nj, i, j, c, visited);
        }
    }

public:
    bool containsCycle(vector<vector<char>> &grid)
    {
        int rows = (int)grid.size(), cols = (int)grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols));

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (!visited[i][j])
                {
                    flag = false;
                    dfs(grid, i, j, -1, -1, grid[i][j], visited);
                    if (flag)
                        return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    return 0;
}