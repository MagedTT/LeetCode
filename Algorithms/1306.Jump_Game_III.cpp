// Problem Link: https://leetcode.com/problems/jump-game-iii/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        vector<int> visited((int)arr.size(), false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            int next = cur + arr[cur];
            int prev = cur - arr[cur];

            if (0 <= next && next < (int)arr.size())
            {
                if (!arr[next])
                    return true;

                if (!visited[next])
                {
                    visited[next] = true;
                    q.push(next);
                }
            }

            if (0 <= prev && prev < (int)arr.size())
            {
                if (!arr[prev])
                    return true;

                if (!visited[prev])
                {
                    visited[prev] = true;
                    q.push(prev);
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