#include <bits/stdc++.h>
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

// recursive solution
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (!root)
    {
        return new TreeNode(val);
    }
    if (val > root->val)
    {
        root->right = insertIntoBST(root->right, val);
    }
    if (val < root->val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    return root;
}

// iterative approach
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (!root)
    {
        return new TreeNode(val);
    }
    TreeNode *prev = NULL;
    TreeNode *newRoot = root;
    while (root)
    {
        if (root->val < val)
        {
            prev = root;
            root = root->right;
        }
        else
        {
            prev = root;
            root = root->left;
        }
    }
    if (prev->val > val)
    {
        prev->left = new TreeNode(val);
    }
    else
    {
        prev->right = new TreeNode(val);
    }
    return newRoot;
}
