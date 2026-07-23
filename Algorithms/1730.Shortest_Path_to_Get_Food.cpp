// Problem Link: https://leetcode.com/problems/shortest-path-to-get-food/description/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
private:
    const int inf = 1e9;
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, 1, 0, -1};

    bool isValid(vector<vector<char>> &grid, int i, int j)
    {
        return 0 <= i && i < (int)grid.size() && 0 <= j && j < (int)grid[0].size();
    }

    int bfs(vector<vector<char>> &grid, int i, int j)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 'X';

        for (int level = 0, sz = 1; !q.empty(); ++level, sz = (int)q.size())
        {
            while (sz--)
            {
                int cur_i = q.front().first, cur_j = q.front().second;
                q.pop();

                for (int d = 0; d < 4; ++d)
                {
                    int ni = cur_i + di[d];
                    int nj = cur_j + dj[d];

                    if (!isValid(grid, ni, nj) || grid[ni][nj] == 'X')
                        continue;

                    if (grid[ni][nj] == '#')
                    {
                        return level + 1;
                    }

                    grid[ni][nj] = 'X';
                    q.push({ni, nj});
                }
            }
        }

        return -1;
    }

public:
    int getFood(vector<vector<char>> &matrix)
    {
        int ret = 0;
        for (int i = 0; i < (int)matrix.size(); ++i)
        {
            for (int j = 0; j < (int)matrix[0].size(); ++j)
            {
                if (matrix[i][j] == '*')
                {
                    ret = bfs(matrix, i, j);
                    break;
                }
            }
        }

        return ret;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> matrix(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];
    }

    Solution solution;
    int result = solution.getFood(matrix);

    cout << result << '\n';

    return 0;
}

/*

5 4
X X X X X
X * X O X
X O X # X
X X X X X

5 8
X X X X X X X X
X * O X O # O X
X O O X O O X X
X O O O O # O X
X X X X X X X X

*/