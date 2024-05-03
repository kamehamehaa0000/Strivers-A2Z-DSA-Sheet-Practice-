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

// brute force
class Solution
{
public:
    void inorder(TreeNode *root, int &count)
    {
        if (root == NULL)
        {
            return;
        }
        count++;
        inorder(root->left, count);
        inorder(root->right, count);
    }
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int count = 0;
        inorder(root, count);
        return count;
    }
};

// optimal

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        if (lh == rh) // if completely filled bt
        {
            return (1 << lh) - 1; // 2^h - 1 = total nodes in a perfect binary tree
        }
        // If the last level is not completely filled
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findHeightLeft(TreeNode *node) // Function to find the left height of a tree
    {
        int height = 0;
        while (node) // Traverse left child until reaching the leftmost leaf
        {
            height++;
            node = node->left;
        }
        return height;
    }

    int findHeightRight(TreeNode *node) // Function to find the right height of a tree
    {
        int height = 0;
        while (node) // Traverse right child until reaching the rightmost leaf
        {
            height++;
            node = node->right;
        }
        return height;
    }
};
