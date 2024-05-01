#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Brute force approach
vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;
    if (!root)
    {
        return ans;
    }
    queue<Node *> q; // Use a queue to perform level order traversal
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        // Process each node in the current level
        for (int i = 0; i < size; i++)
        {
            Node *top = q.front();
            level.push_back(top->data);
            q.pop();
            if (top->left != NULL) // Enqueue the left child if it exists
            {
                q.push(top->left);
            }
            if (top->right != NULL) // Enqueue the right child if it exists
            {
                q.push(top->right);
            }
        }
        ans.push_back(level); // Add the current level to the result
    }

    return ans;
}

vector<int> rightsideView(Node *root)
{
    vector<int> res;
    vector<vector<int>> levelTraversal = levelOrder(root);
    // Iterate through each level and add the last element to the result
    for (auto level : levelTraversal)
    {
        res.push_back(level.back());
    }
    return res;
}

vector<int> leftsideView(Node *root)
{
    vector<int> res;
    vector<vector<int>> levelTraversal = levelOrder(root);
    // Iterate through each level and add the first element to the result
    for (auto level : levelTraversal)
    {
        res.push_back(level.front());
    }
    return res;
}

/* Optimal solution*/

// right side view
// reverse preorder (root right left)
void recursionRight(Node *root, int level, vector<int> &res)
{
    if (root == NULL)
    {
        return;
    }
    if (res.size() == level)
    {
        res.push_back(root->data);
        recursionRight(root->right, level + 1, res);
        recursionRight(root->left, level + 1, res);
    }
}

vector<int> rightsideView(Node *root)
{
    vector<int> res;
    recursionRight(root, 0, res);
    return res;
}

// left side view
// preorder(root left right)
void recursionLeft(Node *root, int level, vector<int> &res)
{
    if (root == NULL)
    {
        return;
    }
    if (res.size() == level)
    {
        res.push_back(root->data);
    }
    recursionLeft(root->left, level + 1, res);  // left child with an increased level
    recursionLeft(root->right, level + 1, res); // right child with an increased level
}

vector<int> leftsideView(Node *root)
{
    vector<int> res;
    recursionLeft(root, 0, res);
    return res;
}
