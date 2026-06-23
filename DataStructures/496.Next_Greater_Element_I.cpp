// Problem Link: https://leetcode.com/problems/next-greater-element-i/description/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> st;

        vector<int> freq(10001, -1);

        for (int i = 0; i < nums2.size(); ++i)
        {
            if (i == 0)
                st.push(nums2[i]);
            else
            {
                while (true)
                {
                    if (!st.empty() && st.top() < nums2[i])
                    {
                        freq[st.top()] = nums2[i];
                        st.pop();
                    }

                    else
                    {
                        st.push(nums2[i]);
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < nums1.size(); ++i)
            nums1[i] = freq[nums1[i]];

        return nums1;
    }
};