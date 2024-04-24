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

vector<vector<int>> levelOrder(TreeNode *root)
{
    if (root == nullptr)
    {
        return {};
    }
    vector<vector<int>> ans;
    queue<TreeNode *> que;
    que.push(root);

    while (!que.empty())
    {
        int n = que.size();
        vector<int> levelAns(n);
        for (int i = 0; i < n; i++)
        {
            TreeNode *temp = que.front();
            que.pop();
            levelAns[i] = temp->val;
            if (temp->left)
            {
                que.push(temp->left);
            }
            if (temp->right)
            {
                que.push(temp->right);
            }
        }
        ans.push_back(levelAns);
    }

    // reverse ans for reverse level order Traversal
    // reverse(ans.begin(), ans.end());

    return ans;
}
