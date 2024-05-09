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

class BSTIterator
{
public:
    stack<TreeNode *> st;
    void pushAll(TreeNode *node)
    {
        while (node != nullptr)
        {
            st.push(node);
            node = node->left;
        }
    }

    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        pushAll(temp->right); // if temp has right push all left node to stack
        return temp->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};

// BST iterator - before

class BSTIterator
{
public:
    stack<TreeNode *> st;
    void pushAllLeft(TreeNode *node)
    {
        while (node != nullptr)
        {
            st.push(node);
            node = node->right;
        }
    }
    BSTIterator(TreeNode *root)
    {
        pushAllLeft(root);
    }

    int before()
    {
        TreeNode *temp = st.top();
        st.pop();
        pushAllLeft(temp->left);
        return temp->val;
    }
    bool hasBefore()
    {
        return st.empty();
    }
};

// merge two bst solution
void inorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> ans;
    inorder(root1, ans);
    inorder(root2, ans);
    sort(ans.begin(), ans.end());
    return ans;
}