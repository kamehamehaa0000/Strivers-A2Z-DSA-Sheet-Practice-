#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

int findfloor(TreeNode *root, int key)
{
    int floor = -1;
    while (root != NULL)
    {
        if (root->data == key)
        {
            floor = root->data;
            return floor;
        }
        if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
}
