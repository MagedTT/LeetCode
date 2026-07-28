// Problem Link: https://leetcode.com/problems/sliding-puzzle/description/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
private:
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, 1, 0, -1};

    bool isValid(int &i, int &j)
    {
        return 0 <= i && i < 2 && 0 <= j && j < 3;
    }

public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        unordered_set<string> visited;
        queue<string> q;

        string str = "";
        for (auto &a : board)
            for (auto &b : a)
                str += (b + '0');

        q.push(str);

        for (int level = 0, sz = (int)q.size(); !q.empty(); ++level, sz = (int)q.size())
        {

            while (sz--)
            {
                string cur = q.front();
                q.pop();

                if (cur == "123450")
                    return level;

                int idx = 0;
                for (int i = 0; i < 6; ++i)
                {
                    if (cur[i] == '0')
                    {
                        idx = i;
                        break;
                    }
                }

                int cur_i = idx / 3;
                int cur_j = idx % 3;

                for (int d = 0; d < 4; ++d)
                {
                    int ni = cur_i + di[d];
                    int nj = cur_j + dj[d];

                    if (!isValid(ni, nj))
                        continue;

                    int idx2 = ni * 3 + nj;

                    swap(cur[idx], cur[idx2]);

                    if (cur == "123450")
                        return level + 1;

                    if (!visited.count(cur))
                    {
                        visited.insert(cur);
                        q.push(cur);
                    }

                    swap(cur[idx], cur[idx2]);
                }
            }
        }

        return -1;

        return 0;
    }
};

int main()
{
    return 0;
}