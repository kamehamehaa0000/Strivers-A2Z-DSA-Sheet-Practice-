#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
/*Brute Force
Node *copyRandomList(Node *head)
{
    unordered_map<Node *, Node *> mpp; //{ orginal:copy}
    Node *temp = head;

    // creating copy nodes but they are not connected to eachother
    while (temp != nullptr)
    {
        Node *newNode = new Node(temp->val);

        mpp[temp] = newNode;

        temp = temp->next;
    }
    // linking the copy nodes
    temp = head;
    Node *copyNode;
    while (temp != nullptr)
    {
        Node *copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp = temp->next;
    }
    return mpp[head];
}*/
/*optimal*/
Node *copyRandomList(Node *head)
{
    // place copy node inbetween nodes
    Node *temp = head;
    while (temp != NULL)
    {
        Node *newNode = new Node(temp->val);
        newNode->next = temp->next;
        temp->next = newNode;

        temp = temp->next->next;
    }
    // link the random pointer
    temp = head;
    while (temp != nullptr)
    {
        if (temp->random != nullptr)
        {
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }
    // link the next poiner
    Node *dummy = new Node(-1);
    temp = head;
    Node *tempDummy = dummy;
    Node *fast;
    while (temp != nullptr)
    {
        fast = temp->next->next;
        tempDummy->next = temp->next; // separating the copy node from original
        temp->next = fast;
        tempDummy = tempDummy->next;
        temp = temp->next; // or fast i.e next of temp in original Linked List
    }
    return dummy->next;
}
