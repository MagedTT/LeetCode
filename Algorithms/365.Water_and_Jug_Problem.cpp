// Problem Link: https://leetcode.com/problems/water-and-jug-problem/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canMeasureWater(int x, int y, int target)
    {
        if (x == y && x == target && x == 1)
            return true;

        if ((x + y) < target)
            return false;

        if ((x + y) == target)
            return true;

        if (x == y)
        {
            if ((x + y) % target == 0 && (x + y) < target)
                return true;

            return false;
        }

        if (x > y)
            swap(x, y);

        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<vector<bool>> visited(1e3 + 1, vector<bool>(1e3 + 1));

        visited[0][0] = true;

        while (!q.empty())
        {
            int cur_x = q.front().first;
            int cur_y = q.front().second;
            int cur_x_holder = cur_x;
            int cur_y_holder = cur_y;
            q.pop();

            if ((cur_x + cur_y) == target)
                return true;

            cur_x = cur_x_holder;
            cur_y = 0;
            if (!visited[cur_x][cur_y])
            {
                visited[cur_x][cur_y] = true;
                q.push({cur_x, cur_y});
            }

            cur_x = 0;
            cur_y = cur_y_holder;
            if (!visited[cur_x][cur_y])
            {
                visited[cur_x][cur_y] = true;
                q.push({cur_x, cur_y});
            }

            cur_x = x;
            cur_y = cur_y_holder;
            if (!visited[cur_x][cur_y])
            {
                visited[cur_x][cur_y] = true;
                q.push({cur_x, cur_y});
            }

            cur_x = cur_x_holder;
            cur_y = y;
            if (!visited[cur_x][cur_y])
            {
                visited[cur_x][cur_y] = true;
                q.push({cur_x, cur_y});
            }

            cur_x = cur_x_holder;
            cur_y = cur_y_holder;
            int temp = y - cur_y;

            cur_y += cur_x;
            if (cur_y > y)
                cur_y = y;

            if (temp >= cur_x)
                cur_x = 0;
            else
                cur_x -= temp;

            if (!visited[cur_x][cur_y])
            {
                visited[cur_x][cur_y] = true;
                q.push({cur_x, cur_y});
            }

            cur_x = cur_x_holder;
            cur_y = cur_y_holder;
            temp = x - cur_x;
            cur_x += cur_y;

            if (cur_x > x)
                cur_x = x;

            if (temp >= cur_y)
                cur_y = 0;
            else
                cur_y -= temp;

            if (!visited[cur_x][cur_y])
            {
                visited[cur_x][cur_y] = true;
                q.push({cur_x, cur_y});
            }
        }

        return false;
    }
};

int main()
{
    return 0;
}