// Problem Link: https://leetcode.com/problems/asteroid-collision/description/

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;

        for (int &a : asteroids)
        {
            if (a > 0 || st.empty())
                st.push(a);

            else if (st.top() < 0)
                st.push(a);

            else
            {
                bool flag = false;
                while (st.size())
                {
                    if (st.top() == -a)
                    {
                        st.pop();
                        flag = true;
                        break;
                    }

                    else if (st.top() > -a)
                    {
                        flag = true;
                        break;
                    }

                    else if (st.top() > 0 && st.top() < -a)
                    {
                        st.pop();
                    }

                    else
                        break;
                }

                if (!flag)
                    st.push(a);
            }
        }

        asteroids.clear();

        while (st.size())
        {
            asteroids.push_back(st.top());
            st.pop();
        }

        reverse(asteroids.begin(), asteroids.end());

        return asteroids;
    }
};