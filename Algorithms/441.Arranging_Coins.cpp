// Problem Link: https://leetcode.com/problems/arranging-coins/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int arrangeCoins(int n)
    {
        int l = 0, r = n, ret = n;

        while (l <= r)
        {
            long long mid = l + (r - l) / 2;

            if (mid * (mid + 1) / 2 <= n)
                l = mid + 1, ret = mid;
            else
                r = mid - 1;
        }

        return ret;
    }
};

int main()
{
    return 0;
}