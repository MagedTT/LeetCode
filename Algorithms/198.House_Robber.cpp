// Problem Link: https://leetcode.com/problems/house-robber/description/

#include <iostream>
#include <vector>

using namespace std;

int dp[101];

class Solution
{
private:
    int solve(int idx, vector<int> &nums)
    {
        if (idx >= (int)nums.size())
            return 0;

        int &ret = dp[idx];
        if (ret != -1)
            return ret;

        ret = 0;
        for (int i = idx + 2; i < (int)nums.size(); ++i)
            ret = max(ret, solve(i, nums));

        ret += nums[idx];
        return ret;
    }

public:
    int rob(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));

        int ret = 0;
        for (int i = 0; i < (int)nums.size(); ++i)
            ret = max(ret, solve(i, nums));

        return ret;
    }
};

int main()
{
    return 0;
}