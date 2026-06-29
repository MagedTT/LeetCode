// Problem Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

#include <iostream>
#include <unordered_set>

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

    void preorder_traversal(TreeNode *root, vector<int> &v)
    {
        if (!root)
            return;

        v.push_back(root->val);

        if (root->left)
            preorder_traversal(root->left, v);

        if (root->right)
            preorder_traversal(root->right, v);
    }

    void answer(TreeNode *root, TreeNode *&ans, int root_value)
    {
        if (root->val == root_value)
        {
            ans = root;
        }

        if (root->left)
            answer(root->left, ans, root_value);

        if (root->right)
            answer(root->right, ans, root_value);
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<int> inorder;
        vector<int> preorder;

        inorder_traversal(root, inorder);
        preorder_traversal(root, preorder);

        int inorder_1 = 0;
        int inorder_2 = 0;

        for (int i = 0; i < (int)inorder.size(); ++i)
        {
            if (inorder[i] == p->val)
            {
                inorder_1 = i;
                break;
            }
        }

        for (int i = 0; i < (int)inorder.size(); ++i)
        {
            if (inorder[i] == q->val)
            {
                inorder_2 = i;
                break;
            }
        }

        if (inorder_1 > inorder_2)
            swap(inorder_1, inorder_2);

        unordered_set<int> s;
        for (int i = inorder_1; i <= inorder_2; ++i)
            s.insert(inorder[i]);

        int root_value = 0;
        for (int i = 0; i < (int)preorder.size(); ++i)
        {
            if (s.count(preorder[i]))
            {
                root_value = preorder[i];
                break;
            }
        }

        TreeNode *ans;

        answer(root, ans, root_value);

        return ans;
    }
};