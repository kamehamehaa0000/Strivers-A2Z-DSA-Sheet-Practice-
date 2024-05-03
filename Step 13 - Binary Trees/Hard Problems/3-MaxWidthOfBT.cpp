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

int widthOfBinaryTree(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    int ans = 0;
    queue<pair<TreeNode *, int>> q; //{node : index }
    q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();         // no. of nodes at the current level
        int mmin = q.front().second; // position of the front node in the current level
        int first, last;

        for (int i = 0; i < size; i++) // Process each node in the current level
        {
            // Calculate current position relative to the minimum position in the level
            int currentIndex = q.front().second - mmin;
            TreeNode *node = q.front().first;

            q.pop();

            // If this is the first node in the level,update the 'first' variable
            if (i == 0)
            {
                first = currentIndex;
            }

            // If this is the last node in the level, update the 'last' variable
            if (i == size - 1)
            {
                last = currentIndex;
            }

            if (node->left)
            {
                q.push({node->left, (long long)currentIndex * 2 + 1});
            }
            if (node->right)
            {
                q.push({node->right, (long long)currentIndex * 2 + 2});
            }
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}

/*
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {

        if (!root)
        {
            return 0;
        }
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        int ans = 0;
        while (!q.empty())
        {
            int size = q.size();
            int mn = q.front().second;
            int first, last;

            for (int i = 0; i < size; i++)
            {
                int currentIndex = q.front().second - mn;
                TreeNode *node = q.front().first;
                q.pop();
                if (i == 0)
                    first = currentIndex;
                if (i == size - 1)
                    last = currentIndex;
                if (node->left)
                {
                    q.push({node->left, (long long)currentIndex * 2 + 1});
                }
                if (node->right)
                {
                    q.push({node->right, (long long)currentIndex * 2 + 2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};
*/