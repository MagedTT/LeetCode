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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void inorder_traversal(TreeNode *root, vector<int> &v)
    {
        if (!root)
            return;

        if (root->left)
            inorder_traversal(root->left, v);

        v.push_back(root->val);

        if (root->right)
            inorder_traversal(root->right, v);
    }

    TreeNode *build_bst(vector<int> &v, int l, int r)
    {
        if (l > r)
            return nullptr;

        int mid = l + (r - l) / 2;
        TreeNode *left = build_bst(v, l, mid - 1);
        TreeNode *right = build_bst(v, mid + 1, r);
        TreeNode *root = new TreeNode(v[mid], left, right);

        return root;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> v;

        inorder_traversal(root, v);

        TreeNode *ret = build_bst(v, 0, (int)v.size() - 1);

        return ret;
    }
};