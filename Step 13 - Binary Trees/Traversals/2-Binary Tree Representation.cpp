#include <bits/stdc++.h>
using namespace std;

// Tree implementation
class TreeNode
{

    int nodeData;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        nodeData = data;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int data, TreeNode *left1, TreeNode *right1)
    {
        nodeData = data;
        left = left1;
        right = right1;
    }
};

// linked codingninja

// node defination
class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

// array to Binary tree;

/*solution 1 using recursion*/

Node *createtree(vector<int> &arr, int index)
{

    // Base case: If index is out of range, or if the element is -1 (indicating a null node)
    if (index >= arr.size() || arr[index] == -1)
    {
        return nullptr;
    }

    Node *root = new Node(arr[index]);

    // Recursively create left and right subtrees
    root->left = createtree(arr, 2 * index + 1);
    root->right = createtree(arr, 2 * index + 2);

    return root;
}

Node *createTree(vector<int> &arr)
{
    return createtree(arr, 0);
}

/*Solution2 using queue*/
Node *createTree(vector<int> &arr)
{
    queue<Node *> q;
    Node *root = new Node(arr[0]);
    q.push(root);

    int i = 0;
    while (!q.empty() && i < 3)
    {
        Node *t = q.front();
        q.pop();

        Node *left = new Node(arr[2 * i + 1]);
        t->left = left;
        q.push(left);

        Node *right = new Node(arr[2 * i + 2]);
        t->right = right;
        q.push(right);
        i++;
    }
    return root;
}
