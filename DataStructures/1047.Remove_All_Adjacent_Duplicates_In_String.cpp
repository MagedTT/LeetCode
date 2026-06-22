// Problem Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;

        for (char &c : s)
        {
            if (st.empty())
                st.push(c);
            else if (st.top() != c)
                st.push(c);
            else
                st.pop();
        }

        string ret = "";

        while (!st.empty())
        {
            ret += st.top();
            st.pop();
        }

        reverse(ret.begin(), ret.end());

        return ret;
    }
};