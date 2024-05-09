#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// solution 1 : find inorder traversal and apply array 2sum solution on it
#include <stack>

// Optimised approach using BSTiterator

class BSTiterator
{

public:
    stack<TreeNode *> s;
    bool reverse = true; // if true then it is for before()
    BSTiterator(TreeNode *root, bool isRev)
    {
        reverse = isRev;
        pushAll(root);
    }

    void pushAll(TreeNode *node)
    {
        while (node)
        {
            s.push(node);
            if (reverse)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
    }

    bool hasNext()
    {
        return !s.empty();
    }

    int next()
    {

        TreeNode *nxt = s.top();
        s.pop();
        if (reverse)
        {
            pushAll(nxt->left);
        }
        else
        {
            pushAll(nxt->right);
        }
        return nxt->val;
    }
};
class Solution
{
public:
    bool pairSumBst(TreeNode *root, int k)
    {
        if (!root)
        {
            return false;
        }

        BSTiterator l(root, false);
        BSTiterator r(root, true);

        int i = l.next();
        int j = r.next();

        while (i < j)
        {
            if (i + j == k)
            {
                return true;
            }
            else if (i + j < k)
            {
                i = l.next();
            }
            else
            {
                j = r.next();
            }
        }
        return false;
    }
};