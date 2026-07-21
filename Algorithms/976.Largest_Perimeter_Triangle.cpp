// Problem Link: https://leetcode.com/problems/largest-perimeter-triangle/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        int sz = (int)nums.size();

        sort(nums.rbegin(), nums.rend());

        for (int i = 0; i < sz - 2; ++i)
            if (nums[i] < nums[i + 1] + nums[i + 2])
                return nums[i] + nums[i + 1] + nums[i + 2];

        return 0;
    }
};

int main()
{
    return 0;
}