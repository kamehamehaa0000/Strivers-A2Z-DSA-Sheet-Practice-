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

// longest path between 2 nodes is diameter of a BT

class Solution
{
public:
    int diameter = 0;
    int calculateHeight(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        diameter = max(diameter, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        calculateHeight(root);
        return diameter;
    }
};
