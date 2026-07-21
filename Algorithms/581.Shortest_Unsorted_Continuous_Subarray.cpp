// Problem Link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

#include <iostream>
#include <vector>

using namespace std;

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

int main()
{
    return 0;
}