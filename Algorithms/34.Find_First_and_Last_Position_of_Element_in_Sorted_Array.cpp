// Problem Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int find_lower(vector<int> &nums, int target)
    {
        int l = 0, r = (int)nums.size() - 1, position = -1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (target < nums[mid])
                r = mid - 1;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1, position = mid;
        }

        return position;
    }

    int find_upper(vector<int> &nums, int target)
    {
        int l = 0, r = (int)nums.size() - 1, position = -1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (target < nums[mid])
                r = mid - 1;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                l = mid + 1, position = mid;
        }

        return position;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        auto p = equal_range(nums.begin(), nums.end(), target);

        vector<int> ret;
        ret.push_back(find_lower(nums, target));
        ret.push_back(find_upper(nums, target));

        return ret;
    }
};

int main()
{
    return 0;
}