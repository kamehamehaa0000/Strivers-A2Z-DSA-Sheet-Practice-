#include <bits/stdc++.h>
using namespace std;
// with class
class Node
{
public:
    int data;   // data in the node which could be of any type
    Node *next; // pointer to next
    // constructor
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1) // for last node
    {
        data = data1;
        next = nullptr;
    }
};
// with struct
//  struct Node
//  {
//      int data;
//      Node *next;
//      Node(int data1, Node *next1)
//      {
//          data = data1;
//          next = next1;
//      }
//  };
int main()
{
    // ways to create node
    Node x = Node(43, nullptr); // here x is a variable not a pointer pointing to memory location
    Node *y = &x;               // here y is pointer to x node
    cout << x.data << endl;     // for this approach you can access the object's element by a dot
    cout << y->data << endl;
    // another easy way to create node

    Node *n = new Node(12, nullptr); // here n points to the memory location of node
    cout << n->data;                 // for this you have to use -> to access the data
}