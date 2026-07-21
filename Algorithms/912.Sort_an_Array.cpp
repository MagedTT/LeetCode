// Problem Link: https://leetcode.com/problems/sort-an-array/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int mn = -1, mx = -1;

        for (int &a : nums)
        {
            if (mn == -1 || mn > a)
                mn = a;

            if (mx == -1 || mx < a)
                mx = a;
        }

        if (mn < 0)
            mn *= -1;

        if (mx < 0)
            mx *= -1;

        vector<int> freq(mn + mx + 1);

        for (int &a : nums)
            freq[a + mn]++;

        vector<int> ret;
        for (int i = 0; i < mn + mx + 1; ++i)
        {
            for (int j = 0; j < freq[i]; ++j)
                ret.push_back(i - mn);
        }

        return ret;
    }
};

int main()
{
    return 0;
}