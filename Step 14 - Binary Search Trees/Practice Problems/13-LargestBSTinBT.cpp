#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// smallest of right subtree and largest of left subtree

class NodeValue
{
public:
    int maxNode;
    int minNode;
    int maxSize;
    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};
class Solution
{
public:
    NodeValue helper(Node *root)
    {
        if (!root)
        {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        auto left = helper(root->left);
        auto right = helper(root->right);
        if (left.maxNode < root->data && root->data < right.minNode)
        {
            return NodeValue(min(root->data, left.minNode),
                             max(root->data, right.maxNode),
                             left.maxSize + right.maxSize + 1);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

    int largestBst(Node *root)
    {
        return helper(root).maxSize;
    }
};