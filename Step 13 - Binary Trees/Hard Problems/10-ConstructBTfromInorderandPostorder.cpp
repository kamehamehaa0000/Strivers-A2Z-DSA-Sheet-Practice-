#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// solution
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    map<int, int> mpp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mpp[inorder[i]] = i;
    }
    TreeNode *root = solve(inorder, 0, inorder.size() - 1,
                           postorder, 0, postorder.size() - 1, mpp);
    return root;
}
// helper function
TreeNode *solve(vector<int> &inorder, int inStart, int inEnd,
                vector<int> &postorder, int postStart, int postEnd, map<int, int> &mpp)
{
    if (inStart > inEnd || postStart > postEnd)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(postorder[postEnd]); // start from end
    int inRoot = mpp[postorder[postEnd]];
    int numsLeft = inEnd - inRoot;
    root->left = solve(inorder, inStart, inRoot - 1,
                       postorder, postStart, postEnd - numsLeft - 1, mpp);
    root->right = solve(inorder, inRoot + 1, inEnd,
                        postorder, postEnd - numsLeft, postEnd - 1, mpp);

    return root;
}
