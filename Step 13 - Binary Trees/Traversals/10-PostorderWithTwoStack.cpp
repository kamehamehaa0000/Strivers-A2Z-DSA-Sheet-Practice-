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

vector<int> postOrder(Node *root)
{
    if (root == NULL)
    {
        return {};
    }

    vector<int> postorder;
    stack<Node *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();

        st2.push(root);

        // Push left child onto st1 if exists
        if (root->left != NULL)
        {
            st1.push(root->left);
        }
        // Push right child onto st1 if exists
        if (root->right != NULL)
        {
            st1.push(root->right);
        }
    }

    while (!st2.empty())
    {
        postorder.push_back(st2.top()->data);
        st2.pop();
    }

    return postorder;
}