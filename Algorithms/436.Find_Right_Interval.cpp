// Problem Link: https://leetcode.com/problems/find-right-interval/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int most_left(vector<pair<int, int>> &v, int &target)
    {
        int l = 0, r = (int)v.size() - 1, position = -1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (target <= v[mid].first)
                r = mid - 1, position = v[mid].second;
            else
                l = mid + 1;
        }

        return position;
    }
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        vector<pair<int, int>> v;
        int sz = (int)intervals.size();
        for (int i = 0; i < sz; ++i)
            v.push_back(make_pair(intervals[i][0], i));

        sort(v.begin(), v.end());

        for (auto &a : v)
            cout << a.first << ' ' << a.second << '\n';

        vector<int> ret;
        for (auto &a : intervals)
            ret.push_back(most_left(v, a[1]));

        return ret;
    }
};

int main()
{
    return 0;
}