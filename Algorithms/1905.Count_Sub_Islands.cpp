// Problem Link: https://leetcode.com/problems/count-sub-islands/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, 1, 0, -1};

    bool isValid(int i, int j, int rows, int cols)
    {
        return 0 <= i && i < rows && 0 <= j && j < cols;
    }

    void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, bool &is_island, int i, int j)
    {
        grid2[i][j] = 0;

        if (!grid1[i][j])
            is_island = false;

        for (int d = 0; d < 4; ++d)
        {
            int ni = i + di[d];
            int nj = j + dj[d];

            if (!isValid(ni, nj, (int)grid1.size(), (int)grid1[0].size()) || !grid2[ni][nj])
                continue;

            dfs(grid1, grid2, is_island, ni, nj);
        }
    }

public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int rows = (int)grid1.size(), cols = grid1[0].size(), ret = 0;

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid2[i][j])
                {
                    bool is_island = true;
                    dfs(grid1, grid2, is_island, i, j);
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