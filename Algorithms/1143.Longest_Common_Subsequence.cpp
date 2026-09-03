// Problem Link: https://leetcode.com/problems/longest-common-subsequence/description/

#include <iostream>

using namespace std;

const int MAX = 1000 + 1;

class Solution
{
private:
    int cache[MAX][MAX];
    int LCS(int idx1, int idx2, string &text1, string &text2)
    {
        if (idx1 == (int)text1.size() || idx2 == (int)text2.size())
            return 0;

        int &ret = cache[idx1][idx2];
        if (ret != -1)
            return ret;

        int match = 0, mismatch = 0;
        if (text1[idx1] == text2[idx2])
            match = 1 + LCS(idx1 + 1, idx2 + 1, text1, text2);

        mismatch = max(LCS(idx1 + 1, idx2, text1, text2), LCS(idx1, idx2 + 1, text1, text2));

        return ret = max(match, mismatch);
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        memset(cache, -1, sizeof(cache));

        return LCS(0, 0, text1, text2);
    }
};

int main()
{
    return 0;
}