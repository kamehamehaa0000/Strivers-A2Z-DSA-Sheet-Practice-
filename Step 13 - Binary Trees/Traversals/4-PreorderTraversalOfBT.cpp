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

void helper(TreeNode<int> *node, vector<int> &answer)
{
    if (node == NULL)
    {
        return;
    }
    answer.push_back(node->data);
    helper(node->left, answer);
    helper(node->right, answer);
}
vector<int> preOrder(TreeNode<int> *root)
{
    vector<int> answer;
    helper(root, answer);
    return answer;
}
