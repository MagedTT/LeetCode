// Problem Link: https://leetcode.com/problems/sqrtx/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        double EPS = 1e-9;
        double l = EPS, r = 1e9 + 10.0;

        for (int i = 0; i < 100; ++i)
        {
            double mid = l + (r - l) / 2.0;

            if (mid <= x / mid)
                l = mid;
            else
                r = mid;
        }

        return (l + r) / 2;
    }
};

int main()
{
    return 0;
}