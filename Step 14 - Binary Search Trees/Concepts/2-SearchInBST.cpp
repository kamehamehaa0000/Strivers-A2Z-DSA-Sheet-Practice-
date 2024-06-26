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

TreeNode *searchBST(TreeNode *root, int val)
{
    while (root != nullptr)
    {
        if (root->val == val)
        {
            return root;
        }

        else if (root->val < val)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return root;
}