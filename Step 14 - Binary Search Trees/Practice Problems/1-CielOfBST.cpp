#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

int findCeil(TreeNode *root, int key)
{
    int ceil = -1;

    while (root != NULL)
    {
        if (root->data == key)
        {
            ceil = root->data;
            return ceil;
        }
        if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}
