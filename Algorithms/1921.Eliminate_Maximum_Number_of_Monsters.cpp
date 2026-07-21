// Problem Link: https://leetcode.com/problems/eliminate-maximum-number-of-monsters/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int sz = (int)dist.size();

        for (int i = 0; i < sz; ++i)
            dist[i] = ceil(dist[i] * 1.0 / speed[i]);

        sort(dist.begin(), dist.end());

        int ret = 0;
        for (int i = 0; i < sz; ++i)
        {
            if ((dist[i] - i) > 0)
                ret++;
            else
                break;
        }

        return ret;
    }
};

int main()
{
    return 0;
}