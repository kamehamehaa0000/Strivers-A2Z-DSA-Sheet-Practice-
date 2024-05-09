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

// OPTIMAL
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int predecessor = -1, successor = -1;
    TreeNode *temp = root;

    while (temp != NULL)
    {
        if (key > temp->val)
        {
            // Updating predecessor.
            predecessor = temp->val;
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    temp = root;

    while (temp != NULL)
    {
        if (key >= temp->val)
        {
            temp = temp->right;
        }
        else
        {
            successor = temp->val; // Updating successor.
            temp = temp->left;
        }
    }
    return make_pair(predecessor, successor);
}

// Brute Force Finding inorder.

void inorder(TreeNode *root, vector<int> &inorderArray)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, inorderArray);
    inorderArray.push_back(root->val);
    inorder(root->right, inorderArray);
}

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // To store the inorder traversal of the BST.
    vector<int> inorderArray;
    inorder(root, inorderArray);
    int predecessor = -1, successor = -1;

    // Finding predecessor.
    for (int i = 0; i < inorderArray.size(); i++)
    {
        if (inorderArray[i] < key)
        {
            predecessor = inorderArray[i];
        }
    }
    // Finding successor.
    for (int i = inorderArray.size() - 1; i >= 0; i--)
    {
        if (inorderArray[i] > key)
        {
            successor = inorderArray[i];
        }
    }
    return {predecessor, successor};
}