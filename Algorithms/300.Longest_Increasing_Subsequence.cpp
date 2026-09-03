// Problem Link: https://leetcode.com/problems/longest-increasing-subsequence/description/

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 2500 + 1;

class Solution
{
private:
    int cache[MAX];
    int LIS(int idx, vector<int> &nums)
    {
        if (idx == (int)nums.size())
            return 0;

        int &ret = cache[idx];
        if (ret != -1)
            return ret;

        ret = 0;
        for (int i = idx + 1; i < (int)nums.size(); ++i)
            if (nums[idx] < nums[i])
                ret = max(ret, LIS(i, nums));

        ret += 1;
        return ret;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        memset(cache, -1, sizeof(cache));
        nums.insert(nums.begin(), INT_MIN);

        return LIS(0, nums) - 1;
    }
};

int main()
{
    return 0;
}