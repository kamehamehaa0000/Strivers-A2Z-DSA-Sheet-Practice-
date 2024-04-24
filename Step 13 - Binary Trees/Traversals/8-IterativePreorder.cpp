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
    if (root == nullptr)
    {
        return {};
    }

    vector<int> preorder;

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        root = st.top();
        st.pop();

        preorder.push_back(root->val);
        // add right first
        if (root->right != nullptr)
        {
            st.push(root->right);
        }
        // then add left
        if (root->left != nullptr)
        {
            st.push(root->left);
        }
    }

    return preorder;
}
