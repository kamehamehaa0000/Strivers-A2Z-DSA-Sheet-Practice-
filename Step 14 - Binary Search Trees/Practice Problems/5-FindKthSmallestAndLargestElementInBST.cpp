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

// kth smallest - brute force
void inorder(TreeNode *node, vector<int> &arr)
{
    if (!node)
    {
        return;
    }
    inorder(node->left, arr);
    arr.push_back(node->val);
    inorder(node->right, arr);
    return;
}
int kthSmallest(TreeNode *root, int k)
{
    vector<int> arr;
    inorder(root, arr);
    int kLargest = arr[arr.size() - k];
    int kSmallest = arr[k - 1];
    return kSmallest;
    // return kLargest;
}

/* optimal solution with O(1) space complexity*/
void inorder(TreeNode *node, int &counter, int k, int &kSmallest) // for ksmallest
{
    if (!node || counter >= k)
    {
        return;
    }
    inorder(node->left, counter, k, kSmallest);
    counter++;        // Increment counter after visiting left subtree
    if (counter == k) // Check if current node is the Kth smallest
    {
        kSmallest = node->val;
        return;
    }
    inorder(node->right, counter, k, kSmallest);
}
void reverseInorder(TreeNode *node, int &counter, int k, int &kLargest) // for klargest
{
    if (!node || counter >= k)
    {
        return;
    }
    reverseInorder(node->right, counter, k, kLargest);
    counter++;        // Increment counter after visiting right subtree
    if (counter == k) // Check if current node is the Kth largest
    {
        kLargest = node->val;
        return;
    }
    reverseInorder(node->left, counter, k, kLargest);
}
pair<int, int> findKth(TreeNode *root, int k)
{
    int kSmallest = INT_MIN, kLargest = INT_MIN;
    int counter = 0; // Counter to track visited nodes

    inorder(root, counter, k, kSmallest);       // Find Kth smallest element
    counter = 0;                                // Reset counter for Kth largest element
    reverseInorder(root, counter, k, kLargest); // Find Kth largest element
    return make_pair(kSmallest, kLargest);
}