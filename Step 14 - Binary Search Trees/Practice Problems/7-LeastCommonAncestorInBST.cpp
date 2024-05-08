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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *a, TreeNode *b)
{
    if (!root || root == a || root == b)
    {
        return root;
    }
    if (a->val < root->val && b->val < root->val)
    {
        return lowestCommonAncestor(root->left, a, b);
    }
    else if (a->val > root->val && b->val > root->val)
    {
        return lowestCommonAncestor(root->right, a, b);
    }
    return root;
}