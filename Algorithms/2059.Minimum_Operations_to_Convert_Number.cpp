// Problem Link: https://leetcode.com/problems/minimum-operations-to-convert-number/description/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums, int start, int goal)
    {
        unordered_set<int> visited;
        queue<int> q;
        q.push(start);
        visited.insert(start);

        for (int level = 0, sz = 1; !q.empty(); ++level, sz = (int)q.size())
        {
            while (sz--)
            {
                int cur = q.front();
                q.pop();

                if (cur == goal)
                    return level;

                if (cur < 0 || cur > 1000)
                    continue;

                for (int &num : nums)
                {
                    if ((cur + num) == goal || (cur - num) == goal || (cur ^ num) == goal)
                        return level + 1;

                    if (0 <= cur + num && cur + num <= 1000)
                    {
                        if (!visited.count(cur + num))
                        {
                            visited.insert(cur + num);
                            q.push(cur + num);
                        }
                    }

                    if (0 <= cur - num && cur - num <= 1000)
                    {
                        if (!visited.count(cur - num))
                        {
                            visited.insert(cur - num);
                            q.push(cur - num);
                        }
                    }

                    if (0 <= (cur ^ num) && (cur ^ num) <= 1000)
                    {
                        if (!visited.count(cur ^ num))
                        {
                            visited.insert(cur ^ num);
                            q.push(cur ^ num);
                        }
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    return 0;
}