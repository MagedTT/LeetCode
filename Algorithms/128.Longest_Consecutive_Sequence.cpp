// Problem Link: https://leetcode.com/problems/longest-consecutive-sequence/description/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (!(int)nums.size())
            return 0;

        set<int> s;
        for (auto &a : nums)
            s.insert(a);

        int ret = 0, cnt = 0, last_value = INT_MIN;
        for (const auto &a : s)
        {
            if (last_value == INT_MIN)
                last_value = a;
            else
            {
                if (a - last_value == 1)
                    ++cnt;
                else
                {
                    ret = max(ret, cnt + 1);
                    cnt = 0;
                }

                last_value = a;
            }
        }

        return max(ret, cnt + 1);
    }
};

int main()
{
    return 0;
}