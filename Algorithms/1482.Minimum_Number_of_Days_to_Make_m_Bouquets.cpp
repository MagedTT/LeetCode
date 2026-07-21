// Problem Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool possible(vector<int> v, int days, int m, int k)
    {
        int sz = (int)v.size();
        for (int &a : v)
            a -= days;

        int k_temp = k;
        for (int i = 0; i < sz; ++i)
        {
            if (v[i] <= 0)
                --k_temp;
            else
                k_temp = k;

            if (!k_temp)
            {
                k_temp = k;
                --m;
            }

            if (!m)
                return true;
        }

        return !m;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {

        if (((int)bloomDay.size() + k - 1) / k < m)
            return -1;

        int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end()), ret = -1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (possible(bloomDay, mid, m, k))
                r = mid - 1, ret = mid;
            else
                l = mid + 1;
        }

        return ret;
    }
};

int main()
{
    return 0;
}