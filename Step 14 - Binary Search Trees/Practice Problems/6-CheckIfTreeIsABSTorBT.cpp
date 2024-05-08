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

// solution 1
void solve(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    solve(root->left, ans);
    ans.push_back(root->val);
    solve(root->right, ans);
}
bool isValidBST(TreeNode *root)
{
    vector<int> inOrder;
    solve(root, inOrder);
    for (int i = 0; i < inOrder.size() - 1; i++)
    {
        if (inOrder[i] >= inOrder[i + 1])
        {
            return false;
        }
    }
    return true;
}

// solution 2
bool isValidBST(TreeNode *root, long long min_val = LONG_MIN,
                long long max_val = LONG_MAX)
{
    if (!root)
    {
        return true;
    }
    if (root->val <= min_val || root->val >= max_val)
    {
        return false;
    }
    return isValidBST(root->left, min_val, root->val) &&
           isValidBST(root->right, root->val, max_val);
}