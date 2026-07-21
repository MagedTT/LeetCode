// Problem Link: https://leetcode.com/problems/minimum-absolute-difference/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());

        vector<vector<int>> ret;

        int mn = -1, sz = (int)arr.size();
        for (int i = 1; i < sz; ++i)
            if (mn == -1 || mn > arr[i] - arr[i - 1])
                mn = arr[i] - arr[i - 1];

        for (int i = 1; i < sz; ++i)
            if ((arr[i] - arr[i - 1]) == mn)
                ret.push_back({arr[i - 1], arr[i]});

        return ret;
    }
};

int main()
{
    return 0;
}