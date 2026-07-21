// Problem Link: https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int sum = 0, sz = (int)nums.size();
        for (int &a : nums)
            sum += a;

        if (nums[0] >= 0)
        {
            if (k & 1)
                return sum - 2 * nums[0];
            return sum;
        }

        for (int i = 0; i < sz; ++i)
        {
            if (!k || nums[i] >= 0)
                break;

            sum += -2 * nums[i], nums[i] *= -1, --k;
        }

        if (k & 1)
        {
            int mn = -1;
            for (int &a : nums)
                if (mn == -1 || mn > a)
                    mn = a;

            sum -= 2 * mn;
        }

        return sum;
    }
};

int main()
{
    return 0;
}