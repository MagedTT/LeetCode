// Problem Link: https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);

        bool no_more_allowed = false;

        while (!q.empty())
        {
            int sz = (int)q.size();

            while (sz--)
            {
                TreeNode *cur = q.front();
                q.pop();

                if (cur->left)
                {
                    if (no_more_allowed)
                        return false;
                    else
                        q.push(cur->left);
                }
                else
                    no_more_allowed = true;
                if (cur->right)
                {
                    if (no_more_allowed)
                        return false;
                    else
                        q.push(cur->right);
                }
                else
                    no_more_allowed = true;
            }
        }

        return true;
    }
};