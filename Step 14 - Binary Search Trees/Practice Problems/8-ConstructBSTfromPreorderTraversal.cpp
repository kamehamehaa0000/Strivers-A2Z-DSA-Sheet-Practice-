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

// solution 1 -  find inorder by sorting preorder then use both to create a unique BT

// solution -2 using range
TreeNode *build(vector<int> &preorder, int &i, int bound)
{
    if (i == preorder.size() || preorder[i] > bound)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(preorder[i++]); // root
    root->left = build(preorder, i, root->val);   // left
    root->right = build(preorder, i, bound);      // right
    return root;
}

TreeNode *preOrderTree(vector<int> &preOrder)
{
    int i = 0;
    return build(preOrder, i, INT_MAX);
}
