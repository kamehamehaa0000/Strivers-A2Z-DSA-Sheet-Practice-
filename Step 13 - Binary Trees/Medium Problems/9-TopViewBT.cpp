#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T dat)
    {
        this->data = dat;
        left = NULL;
        right = NULL;
    }
};

// using preOrderTraversal
void applyPreOrder(TreeNode<int> *root, int line, int level, map<int, pair<int, int>> &visited)
{
    if (root == NULL)
    {
        return;
    }
    auto x = visited.find(line);
    // Check whether the current horizontal distance is already visited or not?
    // If visited then is previous visited element has greater level.
    if (x == visited.end() || (x->second).second > level)
    {
        visited[line] = {root->data, level}; // add current line to visited map
    }
    applyPreOrder(root->left, line - 1, level + 1, visited);  // Go for left subtree with one less horizontal distance and one more level.
    applyPreOrder(root->right, line + 1, level + 1, visited); // Go for right subtree with one more horizontal distance and one more level.
}

vector<int> getTopView(TreeNode<int> *root)
{
    map<int, pair<int, int>> visited; // {line:{node,level}}
    applyPreOrder(root, 0, 0, visited);
    vector<int> topView;
    for (auto view : visited)
    {
        topView.push_back(view.second.first);
    }
    return topView;
}

// USING LEVEL ORDER TRAVERSAL

vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> mp;                    //{line,node}
    queue<pair<TreeNode<int> *, int>> q; // {pair{node,verticalPosition}}

    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode<int> *Node = it.first;
        int line = it.second;
        if (mp.find(line) == mp.end())
        {
            mp[line] = Node->data;
        }
        if (Node->left != NULL)
        {
            q.push({Node->left, line - 1});
        }
        if (Node->right != NULL)
        {
            q.push({Node->right, line + 1});
        }
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}