#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> preorder;
    TreeNode *curr = root;
    while (curr != NULL)
    {
        // if cur does not have a left push curr to ans and move cur to cur's right
        if (curr->left == NULL)
        {
            preorder.push_back(curr->val);
            curr = curr->right;
        }
        // if cur has left
        else
        {
            TreeNode *prev = curr->left;
            // find rightmost node of left subtree
            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }
            // if rightmost node is not connected to cur , connect it ,push curr to ans and move cur to cur's left
            if (prev->right == NULL)
            {
                prev->right = curr;
                preorder.push_back(curr->val);
                curr = curr->left;
            }
            // if rightmost node is already connected to cur , remove connection move cur to cur's right
            else
            {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preorder;
}