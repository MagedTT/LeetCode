// Problem Link: https://leetcode.com/problems/most-profit-assigning-work/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int min_difficulty = -1, max_difficulty = -1, sz = (int)difficulty.size();

        vector<pair<int, int>> v;

        for (int i = 0; i < sz; ++i)
            v.emplace_back(difficulty[i], profit[i]);

        sort(v.begin(), v.end());
        min_difficulty = v[0].first;
        max_difficulty = v[sz - 1].first;

        vector<int> values;

        values.push_back(0);

        for (int i = 1; i < min_difficulty; ++i)
            values.push_back(0);

        for (int i = 1; i < sz; ++i)
            for (int j = v[i - 1].first; j < v[i].first; ++j)
                values.push_back(v[i - 1].second);

        int mx_profit_so_far = -1;
        for (auto &a : values)
        {
            if (mx_profit_so_far == -1 || mx_profit_so_far < a)
                mx_profit_so_far = a;

            if (a < mx_profit_so_far)
                a = mx_profit_so_far;
        }

        mx_profit_so_far = max(mx_profit_so_far, v[sz - 1].second);

        for (int i = max_difficulty; i <= 100000; ++i)
            values.push_back(mx_profit_so_far);

        int ret = 0;
        for (int &a : worker)
            ret += values[a];
        return ret;
    }
};

int main()
{
    return 0;
}