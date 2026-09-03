// Problem Link: https://leetcode.com/problems/partition-equal-subset-sum/description/

#include <iostream>
#include <vector>

using namespace std;

int dp[201][10001];

class Solution
{
private:
    bool solve(int idx, int target, vector<int> &nums)
    {
        if (!target)
            return true;

        if (target < 0 || idx == (int)nums.size())
            return false;

        int &ret = dp[idx][target];
        if (ret != -1)
            return ret;

        if (solve(idx + 1, target, nums))
            return ret = true;

        return ret = solve(idx + 1, target - nums[idx], nums);
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto &a : nums)
            sum += a;

        if (sum & 1)
            return false;

        int target = sum / 2;
        memset(dp, -1, sizeof(dp));

        return solve(0, target, nums);
    }
};

int main()
{
    return 0;
}