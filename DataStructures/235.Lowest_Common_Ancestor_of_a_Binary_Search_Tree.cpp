// Problem Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

#include <iostream>

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
    // Solution Iterative
    TreeNode *lowestCommonAncestor_iterative(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int mn = min(p->val, q->val);
        int mx = max(p->val, q->val);

        while (true)
        {
            if (root->val < mn)
                root = root->right;
            else if (root->val > mx)
                root = root->left;
            else
                return root;
        }

        return nullptr;
    }

    // Solution Recursive
    TreeNode *lowestCommonAncestor_Recursive(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor_Recursive(root->left, p, q);

        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor_Recursive(root->right, p, q);

        return root;
    }
};