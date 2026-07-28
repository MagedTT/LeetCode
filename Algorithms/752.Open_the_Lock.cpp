// Problem Link: https://leetcode.com/problems/open-the-lock/description/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
private:
    char next(char ch)
    {
        int n = ch - '0';
        n++;

        if (n > 9)
            return '0';

        return n + '0';
    }

    char prev(char ch)
    {
        int n = ch - '0';

        n--;

        if (n < 0)
            return '9';

        return n + '0';
    }

public:
    int openLock(vector<string> &deadends, string target)
    {
        if (target == "0000")
            return 0;

        for (string &str : deadends)
            if (str == "0000")
                return -1;

        unordered_set<string> st;
        for (string &str : deadends)
            st.insert(str);

        queue<string> q;
        q.push("0000");

        int cnt = 0;
        for (int level = 0, sz = 1; !q.empty(); ++level, sz = (int)q.size())
        {
            while (sz--)
            {
                string cur = q.front();
                q.pop();

                if (cur == target)
                    return level;

                for (int i = 0; i < 4; ++i)
                {
                    ++cnt;
                    string temp = cur;
                    temp[i] = next(temp[i]);

                    if (!st.count(temp))
                    {
                        if (temp == target)
                            return level + 1;

                        q.push(temp);
                        st.insert(temp);
                    }

                    temp[i] = prev(temp[i]);
                    temp[i] = prev(temp[i]);

                    if (!st.count(temp))
                    {
                        if (temp == target)
                            return level + 1;

                        q.push(temp);
                        st.insert(temp);
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    return 0;
}