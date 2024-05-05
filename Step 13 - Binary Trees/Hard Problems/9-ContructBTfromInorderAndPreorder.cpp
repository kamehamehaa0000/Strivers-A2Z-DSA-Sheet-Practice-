#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        map<int, int> inMap; // to store indices of elements in the inorder traversal
        for (int i = 0; i < inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }
        TreeNode *root = solve(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
        return root;
    }

private:
    // helper function
    TreeNode *solve(vector<int> &preorder, int preStart, int preEnd,
                    vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap)
    {
        if (preStart > preEnd || inStart > inEnd)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];   // Find the index of the current root value in the inorder traversal
        int numsLeft = inRoot - inStart; // Calculate the number of elements in the left subtree

        // Recursively build the left subtree
        root->left = solve(preorder, preStart + 1, preStart + numsLeft,
                           inorder, inStart, inRoot - 1, inMap);

        // Recursively build the right subtree
        root->right = solve(preorder, preStart + numsLeft + 1, preEnd,
                            inorder, inRoot + 1, inEnd, inMap);

        return root;
    }
};