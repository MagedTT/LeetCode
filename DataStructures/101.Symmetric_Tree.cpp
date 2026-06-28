// Problem Link: https://leetcode.com/problems/symmetric-tree/description/

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
    string parenthesize(TreeNode *node, bool mirror = false)
    {
        string ret = "(" + to_string(node->val);

        if (mirror)
        {
            if (node->left)
                ret += parenthesize(node->left, false);
            else
                ret += "()";

            if (node->right)
                ret += parenthesize(node->right, false);
            else
                ret += "()";
        }
        else
        {
            if (node->right)
                ret += parenthesize(node->right, true);
            else
                ret += "()";

            if (node->left)
                ret += parenthesize(node->left, true);
            else
                ret += "()";
        }

        ret += ")";

        return ret;
    }

    bool isSymmetric_using_parenthesizing(TreeNode *root)
    {
        if (!root || !root->left && !root->right)
            return true;
        if (!root->left && root->right || root->left && !root->right)
            return false;

        string left = parenthesize(root->left, true);
        string right = parenthesize(root->right, false);

        return left == right;
    }

    bool symmetric(TreeNode *left, TreeNode *right)
    {
        if (!left && right || !right && left)
            return false;

        if (!left && !right)
            return true;

        if (left->val != right->val)
            return false;

        return symmetric(left->left, right->right) && symmetric(left->right, right->left);
    }

    bool isSymmetric_Recursive(TreeNode *root)
    {
        if (!root || !root->left && !root->right)
            return true;
        if (!root->left && root->right || root->left && !root->right)
            return false;

        return symmetric(root->left, root->right);
    }
};
