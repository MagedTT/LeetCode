// Problem Link: https://leetcode.com/problems/flood-fill/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, 1, 0, -1};

    bool isValid(int i, int j, int rows, int cols)
    {
        return 0 <= i && i < rows && 0 <= j && j < cols;
    }

    void dfs(vector<vector<int>> &image, int sr, int sc, vector<vector<bool>> &visited, int oldColor, int newColor)
    {
        image[sr][sc] = newColor;
        visited[sr][sc] = true;

        for (int d = 0; d < 4; ++d)
        {
            int ni = sr + di[d];
            int nj = sc + dj[d];

            if (!isValid(ni, nj, (int)image.size(), (int)image[0].size()) ||
                image[ni][nj] != oldColor ||
                visited[ni][nj])
                continue;

            dfs(image, ni, nj, visited, oldColor, newColor);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        vector<vector<bool>> visited((int)image.size(), vector<bool>((int)image[0].size()));
        dfs(image, sr, sc, visited, image[sr][sc], color);

        return image;
    }
};

int main()
{
    return 0;
}