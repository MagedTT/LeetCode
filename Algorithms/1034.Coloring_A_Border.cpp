// Problem Link: https://leetcode.com/problems/coloring-a-border/description/

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

    bool isBorder(vector<vector<int>> &grid, int i, int j, int oldColor)
    {
        int rows = (int)grid.size();
        int cols = (int)grid[0].size();

        for (int d = 0; d < 4; ++d)
        {
            int ni = i + di[d];
            int nj = j + dj[d];

            if (ni < 0 || ni >= rows || nj < 0 || nj >= cols)
                return true;

            if (isValid(grid, ni, nj))
            {
                if (grid[ni][nj] != oldColor && grid[ni][nj] != -1 && grid[ni][nj] != 2000)
                    return true;
            }
        }

        return false;
    }

    void dfs(vector<vector<int>> &grid, int oldColor, int row, int col)
    {
        if (isBorder(grid, row, col, oldColor))
            grid[row][col] = -1;
        else
            grid[row][col] = 2000;

        for (int d = 0; d < 4; ++d)
        {
            int ni = row + di[d];
            int nj = col + dj[d];

            if (!isValid(grid, ni, nj) || grid[ni][nj] != oldColor || grid[ni][nj] == -1 || grid[ni][nj] == 2000)
                continue;

            dfs(grid, oldColor, ni, nj);
        }
    }

public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color)
    {
        int oldColor = grid[row][col];

        dfs(grid, grid[row][col], row, col);

        for (auto &a : grid)
            for (auto &b : a)
                if (b == -1)
                    b = color;
                else if (b == 2000)
                    b = oldColor;

        return grid;
    }
};

int main()
{
    return 0;
}