#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

// types of traversal in tree
// 1. DFS -> a. inorder (left root right) (all 3 starts from extreme left and right subtree )
//           b. pre-order (root left right)
//           c. post-order (left right root)
//

// 2 DFS -> level order traversal

/*dfs*/

/*recursive solution*/
void inOrder(TreeNode *node, vector<int> &answer)
{
    if (node == NULL)
    {
        return;
    }
    inOrder(node->left, answer);  // Visit left subtree.
    answer.push_back(node->data); // Add data of node to answer.
    inOrder(node->right, answer); // Visit right subtree.
}

void preOrder(TreeNode *node, vector<int> &answer) // root left right
{
    if (node == NULL)
    {
        return;
    }
    answer.push_back(node->data);  // Add data of node to answer.
    preOrder(node->left, answer);  // Visit left subtree.
    preOrder(node->right, answer); // Visit right subtree.
}

void postOrder(TreeNode *node, vector<int> &answer) // left right root
{
    if (node == NULL)
    {
        return;
    }
    postOrder(node->left, answer);  // Visit left subtree.
    postOrder(node->right, answer); // Visit right subtree.
    answer.push_back(node->data);   // Add data of node to answer.
}

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    vector<int> inOrderAns, preOrderAns, postOrderAns;
    inOrder(root, inOrderAns);
    preOrder(root, preOrderAns);
    postOrder(root, postOrderAns);

    return {inOrderAns, preOrderAns, postOrderAns};
}

/*-----------------------------------------------------*/

/*iterative solution*/

void inOrderIterative(TreeNode *root, vector<int> &answer)
{
    stack<TreeNode *> s;
    TreeNode *current = root;

    while (current != nullptr || !s.empty())
    {
        while (current != nullptr)
        {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        answer.push_back(current->data);
        current = current->right;
    }
}

void preOrderIterative(TreeNode *root, vector<int> &answer)
{
    stack<TreeNode *> s;
    s.push(root);

    while (!s.empty())
    {
        TreeNode *node = s.top();
        answer.push_back(node->data);
        s.pop();

        if (node->right != nullptr)
        {
            s.push(node->right);
        }

        if (node->left != nullptr)
        {
            s.push(node->left);
        }
    }
}

void postOrderIterative(TreeNode *root, vector<int> &answer)
{
    stack<TreeNode *> s;
    TreeNode *current = root;
    s.push(current);

    while (!s.empty())
    {
        current = s.top();
        s.pop();
        answer.push_back(current->data);

        if (current->left)
        {
            s.push(current->left);
        }

        if (current->right)
        {
            s.push(current->right);
        }
    }
    reverse(answer.begin(), answer.end());
}

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return {};
    }

    vector<int> inOrderAns, preOrderAns, postOrderAns;
    inOrderIterative(root, inOrderAns);
    preOrderIterative(root, preOrderAns);
    postOrderIterative(root, postOrderAns);

    return {inOrderAns, preOrderAns, postOrderAns};
}
