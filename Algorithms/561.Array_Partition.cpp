// Problem Link: https://leetcode.com/problems/array-partition/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int ret = 0, sz = (int)nums.size();

        for (int i = 0; i < sz; i += 2)
            ret += nums[i];

        return ret;
    }
};

int main()
{
    return 0;
}