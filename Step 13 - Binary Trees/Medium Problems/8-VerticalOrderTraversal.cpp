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

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    // Map to store nodes based on vertical and level information
    map<int, map<int, multiset<int>>> nodes; // mpp{vertical,mpp{level,multiset{multinodes}}}

    queue<pair<TreeNode *, pair<int, int>>> todo; // pair{node*,pair{vertical,level}}

    todo.push({root, {0, 0}});

    // BFS traversal
    while (!todo.empty())
    {
        auto p = todo.front();
        todo.pop();

        TreeNode *temp = p.first; // current node
        int x = p.second.first;   // x -> vertical
        int y = p.second.second;  // y -> level

        nodes[x][y].insert(temp->val); // Insert the node value into the corresponding vertical and level in the map

        // Process left child
        if (temp->left)
        {
            // Move left in terms of vertical and Move down in terms of level
            todo.push({temp->left, {x - 1, y + 1}});
        }
        // Process right child
        if (temp->right)
        {
            // Move right in terms of vertical and Move down in terms of level
            todo.push({temp->right, {x + 1, y + 1}});
        }
    }

    // Prepare the final result vector by combining values from the map
    vector<vector<int>> ans;
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        { // Insert node values into the column vector
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}