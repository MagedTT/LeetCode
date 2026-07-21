// Problem Link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

#include <iostream>
#include <vector>

using namespace std;

// O(n log n) solution
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int min_idx = -1, max_idx = -1, sz = (int)nums.size();
        vector<int> v;

        for (int &a : nums)
            v.push_back(a);

        sort(v.begin(), v.end());

        for (int i = 0; i < sz; ++i)
        {
            if (v[i] != nums[i])
            {
                min_idx = i;
                break;
            }
        }

        for (int i = sz - 1; i >= 0; --i)
        {
            if (v[i] != nums[i])
            {
                max_idx = i;
                break;
            }
        }

        return min_idx == -1 ? 0 : max_idx - min_idx + 1;
    }
};
// another O(n) Solution
int findUnsortedSubarray(vector<int> &nums)
{
    int min_idx = -1, max_idx = -1, mn = -1, mx = -1, sz = (int)nums.size();

    for (int i = 0; i < sz; ++i)
    {
        if (mx == -1 || mx < nums[i])
            mx = nums[i];

        if (mx > nums[i])
            max_idx = i;
    }

    for (int i = sz - 1; i >= 0; --i)
    {
        if (mn == -1 || mn > nums[i])
            mn = nums[i];

        if (nums[i] > mn)
            min_idx = i;
    }

    return min_idx == -1 ? 0 : max_idx - min_idx + 1;
}

int main()
{
    return 0;
}