#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inOrder(TreeNode *node, vector<int> &answer)
{
    if (node == NULL)
    {
        return;
    }
    inOrder(node->left, answer);
    answer.push_back(node->val);
    inOrder(node->right, answer);
}
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    inOrder(root, ans);
    return ans;
}