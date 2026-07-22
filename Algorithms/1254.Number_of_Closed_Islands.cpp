// Problem Link: https://leetcode.com/problems/number-of-closed-islands/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, 1, 0, -1};

    bool isValid(vector<vector<int>> &grid, int i, int j)
    {
        return 0 <= i && i < (int)grid.size() && 0 <= j && j < (int)grid[0].size();
    }

    bool isValidIslandCell(vector<vector<int>> &grid, int &i, int &j)
    {
        for (int d = 0; d < 4; ++d)
        {
            if (!isValid(grid, i + di[d], j + dj[d]))
                return false;
        }

        return true;
    }

    void dfs(vector<vector<int>> &grid, bool &is_island, int i, int j)
    {
        if (!isValidIslandCell(grid, i, j))
        {
            is_island = false;
            return;
        }

        grid[i][j] = 1;

        for (int d = 0; d < 4; ++d)
        {
            if (!isValid(grid, i + di[d], j + dj[d]))
                continue;

            if (grid[i + di[d]][j + dj[d]])
                continue;

            dfs(grid, is_island, i + di[d], j + dj[d]);
        }
    }

public:
    int closedIsland(vector<vector<int>> &grid)
    {
        int rows = (int)grid.size(), cols = (int)grid[0].size(), ret = 0;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (!grid[i][j])
                {
                    bool is_island = true;
                    dfs(grid, is_island, i, j);
                    ret += is_island;
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