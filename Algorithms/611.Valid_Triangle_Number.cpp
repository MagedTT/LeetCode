// Problem Link: https://leetcode.com/problems/valid-triangle-number/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int find_first(vector<int> &v, int &n, int l, int target)
    {
        int r = n - 1, position = n;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (target <= v[mid])
                r = mid - 1, position = mid;

            else if (v[mid] < target)
                l = mid + 1;
        }

        return position;
    }

    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int n = (int)nums.size(), ret = 0;
        for (int i = 0; i < n - 2; ++i)
        {
            for (int j = i + 1; j < n - 1 && nums[i] != 0; ++j)
            {
                int position = find_first(nums, n, j + 1, nums[i] + nums[j]);

                ret += position - j - 1;
            }
        }

        return ret;
    }
};

int main()
{
    return 0;
}