// Problem Link: https://leetcode.com/problems/next-greater-element-ii/description/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int nums_size = nums.size();
        int v_size = nums_size * 2;
        vector<int> v(v_size);

        for (int i = 0; i < nums_size; ++i)
            v[i] = nums[i];

        for (int i = nums_size, idx = 0; i < v_size && idx < nums_size; ++i, ++idx)
            v[i] = nums[idx];

        stack<int> st;

        for (int i = 0; i < v_size; ++i)
        {
            while (!st.empty() && v[st.top()] < v[i])
            {
                v[st.top()] = v[i];
                st.pop();
            }

            st.push(i);
        }

        while (st.size())
        {
            v[st.top()] = -1;
            st.pop();
        }

        for (int i = 0; i < nums_size; ++i)
            nums[i] = v[i];

        return nums;
    }
};