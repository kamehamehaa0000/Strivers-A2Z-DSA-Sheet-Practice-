#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

#include <bits/stdc++.h>
using namespace std;
BinaryTreeNode *markParents(BinaryTreeNode *root, unordered_map<BinaryTreeNode *, BinaryTreeNode *> &mpp, int start)
{
    queue<BinaryTreeNode *> q;
    q.push(root);
    BinaryTreeNode *res;

    while (!q.empty()) // bfs to store parents in mpp
    {
        BinaryTreeNode *node = q.front();
        if (node->data == start)
        {
            res = node;
        }
        q.pop();

        if (node->left)
        {
            mpp[node->left] = node;
            q.push(node->left);
        }
        if (node->right)
        {
            mpp[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}
int timeToBurnTree(BinaryTreeNode *root, int start)
{
    unordered_map<BinaryTreeNode *, BinaryTreeNode *> mpp; //{node : parent}
    BinaryTreeNode *startNode = markParents(root, mpp, start);
    unordered_map<BinaryTreeNode *, bool> visited;
    queue<BinaryTreeNode *> q;

    q.push(startNode);
    visited[startNode] = true;
    int currentLevel = 0;
    while (!q.empty())
    {
        int size = q.size();
        int fl = 0;
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode *node = q.front();
            q.pop();

            if (node->left && !visited[node->left])
            {
                fl = 1;
                q.push(node->left);
                visited[node->left] = true;
            }
            if (node->right && !visited[node->right])
            {
                fl = 1;
                q.push(node->right);
                visited[node->right] = true;
            }
            if (mpp[node] && !visited[mpp[node]])
            {
                fl = 1;
                q.push(mpp[node]);
                visited[mpp[node]] = true;
            }
        }
        if (fl)
        {
            currentLevel++;
        }
    }
    return currentLevel;
}
