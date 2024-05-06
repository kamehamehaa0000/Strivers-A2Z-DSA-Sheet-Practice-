#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// approach 1 - using recursion

class Solution
{
public:
    TreeNode *prev = NULL;
    void flatten(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        // right left null
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

// approach 2 - Iterative Approach - Using Stack
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();

            if (cur->right != NULL)
            {
                st.push(cur->right);
            }
            if (cur->left != NULL)
            {
                st.push(cur->left);
            }
            if (!st.empty())
            {
                cur->right = st.top();
            }
            cur->left = NULL;
        }
    }
};

// approach 3
/*The algorithm can be described as:

1. At a node(say cur) if there exists a left child, we will find the rightmost node in the left subtree(say prev).
2. We will set prev’s right child to cur’s right child,
3. We will then set cur’s right child to it’s left child.
4. We will then move cur to the next node by assigning cur it to its right child
5. We will stop the execution when cur points to NULL.*/

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *current = root;
        while (current)
        {
            if (current->left)
            {
                TreeNode *pre = current->left;
                while (pre->right)
                {
                    pre = pre->right;
                }
                pre->right = current->right;
                current->right = current->left;
                current->left = NULL;
            }
            current = current->right;
        }
    }
};