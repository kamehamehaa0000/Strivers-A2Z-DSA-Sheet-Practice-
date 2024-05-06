#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
        {
            return "";
        }
        string s = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) // bfs traversal
        {
            TreeNode *curNode = q.front();
            q.pop();
            if (curNode == nullptr) // Check if the current node is null and append "#" to the string
            {
                s += "#,";
            }
            else
            {
                s += to_string(curNode->val) + ",";
                // Push the left and right children to the queue for further traversal
                q.push(curNode->left);
                q.push(curNode->right);
            }
            return s;
        }
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
        {
            return nullptr;
        }
        stringstream s(data); // Use a stringstream to tokenize the serialized data
        string str;
        getline(s, str, ','); // Read the root value from the serialized data
        TreeNode *root = new TreeNode(stoi(str));

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            getline(s, str, ','); // Read the left value of the from the serialized data=
            if (str != "#")
            {
                TreeNode *leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ','); // read the right value
            if (str != "#")
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};