#include <bits/stdc++.h>
using namespace std;

// maximum number of nodes present on 'Nth' level in a binary tree.
int numberOfNodes(int N)
{
    return 1 << N - 1; // 2^n-1;
}

/*Theory of trees*/
/*# Types of Trees:
// Binary Tree: Each node has at most two children.
// Binary Search Tree (BST): Left child contains values less than node, right child contains greater values.
// AVL Tree: Self-balancing binary search tree with limited height differences.
// Red-Black Tree: Self-balancing tree with nodes colored red or black.

// Types of Binary Trees:
// Full Binary Tree: Every non-leaf node has two children.
// Complete Binary Tree: All levels are filled except possibly the last, filled left to right.
// Perfect Binary Tree: All internal nodes have two children, all leaves are at the same level.
// Degenerate Tree: Each parent has only one child, resembling a linked list.

// Related Terms:
// Internal Node: A node with at least one child.
// Subtree: A portion of a tree that is itself a tree.
// Height of a Tree: Length of the longest path from root to leaf.
// Depth of a Node: Length of the path from root to that node.
// Sibling Nodes: Nodes with the same parent.
// Ancestor Nodes: Nodes on the path from root to a node, excluding the node itself.
// Descendant Nodes: Nodes reachable from a node, including its children, grandchildren, etc.

*/