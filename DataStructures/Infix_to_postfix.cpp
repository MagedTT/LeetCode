// Problem Link: https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1?page=2&category%255B%255D=Stack&query=category%255B%255DStackpage2category%255B%255DStack

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    int precedence(char &c)
    {
        if (c == '^')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        return 0;
    }
    string infixToPostfix(string &s)
    {
        // code here
        stack<char> st;
        st.push('#');

        string postfix = "";

        s += '-';

        for (char &c : s)
        {
            if ('0' <= c && c <= '9' || 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z')
                postfix += c;

            else if (c == '(')
                st.push(c);
            else if (c == ')')
            {
                while (st.top() != '(')
                {
                    postfix += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (precedence(st.top()) >= precedence(c) && c != '^')
                {
                    postfix += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        return postfix;
    }
};
