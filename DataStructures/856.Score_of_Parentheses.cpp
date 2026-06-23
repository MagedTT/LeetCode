// Problem Link: https://leetcode.com/problems/score-of-parentheses/description/

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        stack<int> st;
        st.push(0);

        for (char &c : s)
        {
            if (c == '(')
                st.push(0);
            else
            {
                int inner_expression = st.top();
                st.pop();

                if (inner_expression == 0)
                    inner_expression = 1;
                else
                    inner_expression *= 2;

                int parent_expression = st.top();
                st.pop();

                st.push(parent_expression + inner_expression);
            }
        }

        return st.top();
    }
};

int main()
{
    return 0;
}