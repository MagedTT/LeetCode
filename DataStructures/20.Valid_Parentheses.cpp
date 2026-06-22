#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (auto &c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                st.push(c);
            else if (c == ')')
            {
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else
                    return false;
            }
            else if (c == '}')
            {
                if (!st.empty() && st.top() == '{')
                    st.pop();
                else
                    return false;
            }
            else if (c == ']')
            {
                if (!st.empty() && st.top() == '[')
                    st.pop();

                else
                    return false;
            }
        }
        return st.size() == 0;
    }
};

int main()
{
    Solution solution;

    bool valid = solution.isValid("{()}");
    bool valid2 = solution.isValid("{()}()(){}[]");
    bool valid3 = solution.isValid("()]");
    bool valid4 = solution.isValid("(]");

    cout << valid << ' ';
    cout << valid2 << ' ';
    cout << valid3 << ' ';
    cout << valid4 << ' ';

    return 0;
}