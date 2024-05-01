#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    vector<int> bottomView(TreeNode<int> *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        map<int, int> mpp;                   // {line,node->data}
        queue<pair<TreeNode<int> *, int>> q; // {node,line}
        q.push({root, 0});

        // BFS traversal
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            TreeNode<int> *node = it.first;
            int line = it.second;

            // Update the map
            mpp[line] = node->data;

            // Process left child
            if (node->left != NULL)
            {
                q.push({node->left, line - 1});
            }

            // Process right child
            if (node->right != NULL)
            {
                q.push({node->right, line + 1});
            }
        }

        // Transfer values from the map to the result vector
        for (auto it : mpp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};
