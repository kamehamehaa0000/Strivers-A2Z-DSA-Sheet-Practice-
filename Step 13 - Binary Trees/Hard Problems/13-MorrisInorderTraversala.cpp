#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
vector<int> getInorder(TreeNode *root)
{
    vector<int> inorder;
    TreeNode *cur = root;
    while (cur != NULL)
    {
        // if curr does not have a left , add cur to ans and move cur to right
        if (cur->left == NULL)
        {
            inorder.push_back(cur->val);
            cur = cur->right;
        }
        // if has left
        else
        {
            TreeNode *prev = cur->left;
            // find rightmost node on left subtree
            while (prev->right && prev->right != cur)
            {
                prev = prev->right;
            }
            // if rightmost is not connected to cur then connect and point cur to left of cur
            if (prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            // if rightmost is already connected to cur , remove the connection and push cur val to ans and move cur to cur's right
            else
            {
                prev->right = NULL;
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return inorder;
}
