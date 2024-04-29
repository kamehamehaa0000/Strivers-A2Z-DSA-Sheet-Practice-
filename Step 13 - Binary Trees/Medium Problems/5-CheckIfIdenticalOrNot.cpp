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
bool isSameTree(TreeNode *node1, TreeNode *node2)
{
    // If both nodes are NULL, they are identical
    if (node1 == NULL && node2 == NULL)
    {
        return true;
    }
    // If only one of the nodes is NULL, they are not identical
    if (node1 == NULL || node2 == NULL)
    {
        return false;
    }
    // traverse and if traversal is same then identical
    return ((node1->val == node2->val) &&
            isSameTree(node1->left, node2->left) &&
            isSameTree(node1->right, node2->right));
}