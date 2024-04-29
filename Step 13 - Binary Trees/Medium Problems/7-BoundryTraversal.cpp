#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void leftBoundary(TreeNode<int> *root, vector<int> &ans)
{
    // if node is leaf node,exclude it
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    ans.push_back(root->data);
    // if it has left child
    if (root->left != NULL)
    {
        leftBoundary(root->left, ans);
    }
    // if it does not have left child
    else
    {
        leftBoundary(root->right, ans);
    }
}

void rightBoundary(TreeNode<int> *root, vector<int> &ans)
{
    // if node is leaf node , exclude it
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    // if right node is present
    if (root->right != NULL)
    {
        rightBoundary(root->right, ans);
    }
    // if right node is not present
    else
    {
        rightBoundary(root->left, ans);
    }

    ans.push_back(root->data);
}

// visit leaf node
void leafNodes(TreeNode<int> *root, vector<int> &ans)
{ // inorder traversal cause we want leaf node from left to right
    if (root == NULL)
    {
        return;
    }
    // if node is leaf node add to ans
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    leafNodes(root->left, ans);
    leafNodes(root->right, ans);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    ans.push_back(root->data);

    // Traverse left boundary
    leftBoundary(root->left, ans);

    // Traverse for leaf nodes
    leafNodes(root->left, ans);
    leafNodes(root->right, ans);

    // Traverse right boundary
    rightBoundary(root->right, ans);

    return ans;
}