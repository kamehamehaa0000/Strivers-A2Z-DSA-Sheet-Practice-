#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// path to node x from root
bool getPath(TreeNode *root, vector<int> &arr, int x)
{
    if (root = NULL)
    {
        return false;
    }
    arr.push_back(root->val);
    if (root->val == x)
    {
        return true;
    }
    if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
    {
        return true;
    }
    arr.pop_back();
    return false;
}

vector<int> solve(TreeNode *A, int B)
{
    vector<int> arr;
    if (A == NULL)
    {
        return arr;
    }
    getPath(A, arr, B);
    return arr;
}

// path to leaf node from root;

// 1. using dfs
void depthForSearchSolution(TreeNode *root, vector<string> &result, string curr)
{
    if (!root)
    {
        return;
    }
    curr += to_string(root->val) + " ";
    if (!root->left && !root->right)
    {
        result.push_back(curr.substr(0, curr.size() - 1));
    }
    // If left child is not NULL, traverse on the left side.
    if (root->left)
    {
        depthForSearchSolution(root->left, result, curr);
    }
    // If right child is not NULL, traverse on the right side.
    if (root->right)
    {
        depthForSearchSolution(root->right, result, curr);
    }
    return;
}

vector<string> allRootToLeaf(TreeNode *root)
{
    vector<string> result;
    depthForSearchSolution(root, result, "");
    return result;
}

// 1. using bfs
vector<string> allRootToLeaf(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }
    queue<pair<TreeNode *, string>> bfs;
    vector<string> result;
    string str = to_string(root->val) + " ";
    bfs.push({root, str});

    pair<TreeNode *, string> curr;

    while (!bfs.empty())
    {
        curr = bfs.front();
        bfs.pop();
        // If the left and right child of current node is NULL, store the paths in the result array.
        if (!curr.first->left && !curr.first->right)
        {
            result.push_back(curr.second.substr(0, curr.second.size() - 1));
        }
        if (curr.first->left)
        {
            bfs.push({curr.first->left, curr.second + to_string(curr.first->left->val) + " "});
        }
        if (curr.first->right)
        {
            bfs.push({curr.first->right, curr.second + to_string(curr.first->right->val) + " "});
        }
    }
    return result;
}