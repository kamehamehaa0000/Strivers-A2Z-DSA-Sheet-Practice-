#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// solution for only checking its following property or not
bool isParentSum(Node *root)
{
    int sum = 0;
    if (root == nullptr || root->left == NULL && root->right == NULL)
    {
        return true;
    }
    else
    {
        if (root->left != nullptr)
        {
            sum += root->left->data;
        }
        if (root->right != nullptr)
        {
            sum += root->right->data;
        }
        return ((root->data == sum) &&
                isParentSum(root->left) &&
                isParentSum(root->right));
    }
}

//------------------------------------------------------------------------
// solution for making the tree follow the property my modifying the tree

void changeTree(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    int child = 0;
    if (root->left)
    {
        child += root->left->val;
    }
    if (root->right)
    {
        child += root->right->val;
    }

    if (child >= root->val)
    {
        root->val = child;
    }
    else // If the sum is smaller, update the child with the current node's value.
    {
        if (root->left)
        {
            root->left->val = root->val;
        }
        else if (root->right)
        {
            root->right->val = root->val;
        }
    }
    // Recursively call the function on the left and right children.
    changeTree(root->left);
    changeTree(root->right);

    // Calculate total sum of values of the left and right children (if they exist).
    int totalSum = 0;
    if (root->left)
    {
        totalSum += root->left->val;
    }
    if (root->right)
    {
        totalSum += root->right->val;
    }
    // If either left or right child exists, update the current node's value with the total sum.
    if (root->left or root->right)
    {
        root->val = totalSum;
    }
}
