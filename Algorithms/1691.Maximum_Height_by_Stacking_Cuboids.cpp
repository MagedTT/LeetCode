// Problem Link: https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/

#include <iostream>
#include <vector>

using namespace std;

int dp[101];

bool cmp(const vector<int> &a, const vector<int> &b)
{
    if (a[0] == b[0])
    {
        if (a[1] == b[1])
            return a[2] < b[2];
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

class Solution
{
private:
    int LIS(int idx, vector<vector<int>> &cuboids)
    {
        if (idx == (int)cuboids.size())
            return 0;

        int &ret = dp[idx];
        if (ret != -1)
            return ret;

        ret = 0;
        for (int i = idx + 1; i < (int)cuboids.size(); ++i)
            if (cuboids[idx][0] <= cuboids[i][0] && cuboids[idx][1] <= cuboids[i][1] && cuboids[idx][2] <= cuboids[i][2])
                ret = max(ret, LIS(i, cuboids));

        ret += cuboids[idx][2];
        return ret;
    }

public:
    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (auto &a : cuboids)
            sort(a.begin(), a.end());

        sort(cuboids.begin(), cuboids.end(), cmp);

        memset(dp, -1, sizeof(dp));

        int ret = 0;
        for (int i = 0; i < (int)cuboids.size(); ++i)
            ret = max(ret, LIS(i, cuboids));

        return ret;
    }
};

int main()
{
    return 0;
}