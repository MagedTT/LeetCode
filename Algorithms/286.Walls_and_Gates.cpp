// Problem Link: https://leetcode.com/problems/walls-and-gates/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, 1, 0, -1};

    bool isValid(vector<vector<int>> &rooms, int i, int j)
    {
        return 0 <= i && i < (int)rooms.size() && 0 <= j && j < (int)rooms[0].size();
    }

public:
    void wallsAndGates(vector<vector<int>> &rooms)
    {
        queue<pair<int, int>> q;
        int rows = (int)rooms.size();
        int cols = (int)rooms[0].size();

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (!rooms[i][j])
                    q.push({i, j});

        for (int level = 0, sz = (int)q.size(); !q.empty(); ++level, sz = (int)q.size())
        {
            while (sz--)
            {
                int cur_i = q.front().first;
                int cur_j = q.front().second;
                q.pop();

                for (int d = 0; d < 4; ++d)
                {
                    int ni = cur_i + di[d];
                    int nj = cur_j + dj[d];

                    if (!isValid(rooms, ni, nj) || rooms[ni][nj] != INT_MAX)
                        continue;

                    if (rooms[ni][nj] == INT_MAX)
                        rooms[ni][nj] = level + 1, q.push({ni, nj});
                }
            }
        }
    }
};

int main()
{
    vector<vector<int>> rooms = {{INT_MAX, -1, 0, INT_MAX},
                                 {INT_MAX, INT_MAX, INT_MAX, -1},
                                 {INT_MAX, -1, INT_MAX, -1},
                                 {0, -1, INT_MAX, INT_MAX}};

    Solution solution;

    solution.wallsAndGates(rooms);

    for (auto &a : rooms)
    {
        for (auto &b : a)
            cout << b << ' ';
        cout << '\n';
    }

    return 0;
}