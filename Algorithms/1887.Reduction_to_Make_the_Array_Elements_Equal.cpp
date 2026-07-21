// Problem Link: https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        int ret = 0, sz = (int)nums.size();

        sort(nums.rbegin(), nums.rend());

        for (int i = 1; i < sz; ++i)
            if (nums[i - 1] != nums[i])
                ret += i;

        return ret;
    }
};

int main()
{
    return 0;
}