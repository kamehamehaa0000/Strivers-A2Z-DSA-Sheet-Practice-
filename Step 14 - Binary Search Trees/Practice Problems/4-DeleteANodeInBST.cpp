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

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left, *right;
    BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
    BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
    BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
};

// using recursion
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
    {
        return NULL;
    }
    if (root->val < key)
    {
        root->right = deleteNode(root->right, key);
    }
    else if (root->val > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else // root->val == key
    {
        if (!root->right && !root->left) // Leaf node.
        {
            return NULL;
        }
        else if (!root->right) // Node doesn't have a right subtree.
        {
            return root->left;
        }
        else if (!root->left) // Node doesn't have a left subtree.
        {
            return root->right;
        }
        else
        { // Find the minimum value in the right Subtree(successor).
            TreeNode *temp = root->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            // link minimum value node's left (in the rightsubtree) to key node(root)'s left node
            temp->left = root->left;
            return root->right;
        }
    }
    return root;
}
