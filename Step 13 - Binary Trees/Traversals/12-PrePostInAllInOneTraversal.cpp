#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>> preInPostTraversal(Node *root)
{

    if (root == NULL)
    {
        return {};
    }
    vector<int> pre, in, post;

    stack<pair<Node *, int>> st; // node : state(where 1-preorder,2-inorder,3-postorder)
    st.push({root, 1});          // Start with the root node and state 1 (preorder)

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        // If part of preorder
        if (it.second == 1)
        {
            pre.push_back(it.first->data); // Store the node's data in the preorder traversal
            it.second = 2;                 // Move to state 2 (inorder) for this node
            st.push(it);                   // Push the updated state back onto the stack

            // Push left child onto the stack for processing
            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }

        // If part of Inorder
        else if (it.second == 2)
        {

            in.push_back(it.first->data); // Store the node's data in the inorder traversal
            it.second = 3;                // Move to state 3 (postorder) for this node
            st.push(it);                  // Push the updated state back onto the stack

            // Push right child onto the stack for processing
            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }

        // If part of Postorder
        else
        {
            post.push_back(it.first->data); // Store the node's data in the postorder traversal
        }
    }
    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}
