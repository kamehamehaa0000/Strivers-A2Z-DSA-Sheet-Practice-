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

TreeNode *first, *second, *pre;

void correctTree(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    correctTree(root->left);
    if (pre && pre->val > root->val)
    {
        if (!first)
        {
            first = pre;
        }
        second = root;
    }
    pre = root;
    correctTree(root->right);
}

TreeNode *FixBST(TreeNode *root)
{
    first = NULL, second = NULL, pre = NULL;
    correctTree(root);
    swap(first->val, second->val);
    return root;
}