// Problem Link: https://leetcode.com/problems/heaters/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool possible(vector<int> &houses, vector<int> &heaters, int mid)
    {
        int housesSize = (int)houses.size();
        int heatersSize = (int)heaters.size();

        for (int i = 0, j = 0; i < heatersSize; ++i)
        {
            int left = heaters[i] - mid, right = heaters[i] + mid;

            while (j < housesSize && left <= houses[j] && houses[j] <= right)
            {
                ++j;
                if (j == housesSize)
                    return true;
            }
        }

        return false;
    }

    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int l = 0, r = 1e9 + 1, ret = 0;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (possible(houses, heaters, mid))
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