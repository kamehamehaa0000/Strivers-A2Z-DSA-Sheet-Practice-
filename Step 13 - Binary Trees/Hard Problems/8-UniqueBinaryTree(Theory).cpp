#include <bits/stdc++.h>
using namespace std;
// preorder-1 inorder-2 postorder-3
bool uniqueBinaryTree(int a, int b)
{
    // If one travesal is inorder and other is not, then return 'true'.
    if ((a == 2 && b != 2) || (a != 2 && b == 2))
    {
        return true;
    }
    return false;
}
/* theory

To determine if it is possible to construct a unique binary tree from the given pair of traversals, we can leverage the properties of different traversal types.

If the given pair includes both preorder and inorder traversals, it is possible to construct a unique binary tree. This is because the preorder traversal provides the root of the tree, and the inorder traversal helps determine the left and right subtrees.
If the given pair includes both inorder and postorder traversals, it is also possible to construct a unique binary tree. In this case, the postorder traversal provides the root of the tree, and the inorder traversal helps determine the left and right subtrees.
If the given pair includes both preorder and postorder traversals, it is not possible to construct a unique binary tree. This is because the combination of these two traversals does not provide enough information to determine the exact structure of the tree.


*/