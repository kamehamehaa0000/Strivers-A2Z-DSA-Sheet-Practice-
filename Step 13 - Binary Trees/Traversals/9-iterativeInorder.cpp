#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return {};
    }

    vector<int> inorder;
    stack<TreeNode *> st;
    TreeNode *current = root;

    while (!st.empty() || current != nullptr)
    {
        // push the leftest nodes from root to leaf
        while (current != nullptr)
        {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        inorder.push_back(current->val);
        current = current->right;
    }

    return inorder;
}
