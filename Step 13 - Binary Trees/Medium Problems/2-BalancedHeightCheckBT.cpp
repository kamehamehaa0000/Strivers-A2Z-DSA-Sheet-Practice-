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

// code 1
int helper(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = helper(root->left);
    if (lh == -1)
    {
        return -1;
    }
    int rh = helper(root->right);
    if (rh == -1)
    {
        return -1;
    }
    if (abs(lh - rh) > 1)
    {
        return -1;
    }
    return max(lh, rh) + 1;
}
bool isBalanced(TreeNode *root)
{
    return helper(root) != -1;
}

// code 2

int height(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (abs(height(root->left) - height(root->right)) > 1)
    {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}