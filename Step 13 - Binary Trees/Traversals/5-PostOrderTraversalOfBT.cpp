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

void postOrder(TreeNode *node, vector<int> &answer)
{
    if (node == NULL)
    {
        return;
    }
    postOrder(node->left, answer);
    postOrder(node->right, answer);
    answer.push_back(node->val);
}
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    postOrder(root, ans);
    return ans;
}