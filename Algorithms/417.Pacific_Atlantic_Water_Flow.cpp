// Problem Link: https://leetcode.com/problems/pacific-atlantic-water-flow/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, 1, 0, -1};

    bool isValid(int &i, int &j, int &rows, int &cols)
    {
        return 0 <= i && i < rows && 0 <= j && j < cols;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int rows = (int)heights.size(), cols = (int)heights[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> first(rows, vector<bool>(cols));
        vector<vector<bool>> second(rows, vector<bool>(cols));

        for (int i = 0; i < rows; ++i)
            q.push({i, 0}), first[i][0] = true;

        for (int j = 0; j < cols; ++j)
            q.push({0, j}), first[0][j] = true;

        while (!q.empty())
        {
            int cur_i = q.front().first;
            int cur_j = q.front().second;
            q.pop();

            for (int d = 0; d < 4; ++d)
            {
                int ni = cur_i + di[d];
                int nj = cur_j + dj[d];

                if (!isValid(ni, nj, rows, cols) || first[ni][nj] || heights[cur_i][cur_j] > heights[ni][nj])
                    continue;

                first[ni][nj] = true;
                q.push({ni, nj});
            }
        }

        for (int i = 0; i < rows; ++i)
            q.push({i, cols - 1}), second[i][cols - 1] = true;

        for (int j = 0; j < cols; ++j)
            q.push({rows - 1, j}), second[rows - 1][j] = true;

        while (!q.empty())
        {
            int cur_i = q.front().first;
            int cur_j = q.front().second;
            q.pop();

            for (int d = 0; d < 4; ++d)
            {
                int ni = cur_i + di[d];
                int nj = cur_j + dj[d];

                if (!isValid(ni, nj, rows, cols) || second[ni][nj] || heights[cur_i][cur_j] > heights[ni][nj])
                    continue;

                second[ni][nj] = true;
                q.push({ni, nj});
            }
        }

        vector<vector<int>> ret;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (first[i][j] && second[i][j])
                    ret.push_back({i, j});

        return ret;
    }
};

int main()
{
    return 0;
}