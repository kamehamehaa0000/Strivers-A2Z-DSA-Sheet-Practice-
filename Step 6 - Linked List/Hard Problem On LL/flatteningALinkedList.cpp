#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr){};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};
/*Brute force
Node *flattenLinkedList(Node *head)
{
    if (!head)
    {
        return nullptr;
    }

    vector<int> arr;

    Node *temp = head;
    Node *temp2 = temp;
    while (temp != nullptr)
    {
        Node *temp2 = temp;
        while (temp2 != nullptr)
        {
            arr.push_back(temp2->data);
            temp2 = temp2->child;
        }
        temp = temp->next;
    }

    sort(arr.begin(), arr.end());

    Node *newHead = new Node(arr[0]);
    Node *current = newHead;
    for (size_t i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        current->child = newNode;
        current = newNode;
    }

    return newHead;
}
*/

/*optimal*/

Node *merge(Node *a, Node *b)
{
    Node *dummy = new Node(-1);
    Node *res = dummy;
    while (a != nullptr && b != nullptr)
    {
        if (a->data < b->data)
        {
            res->child = a;
            res = a;
            a = a->child;
        }
        else
        {
            res->child = b;
            res = b;
            b = b->child;
        }
        res->next = nullptr;
    }
    if (a != nullptr)
    {
        res->child = a;
    }
    else
    {
        res->child = b;
    }
    if (dummy->child != nullptr)
    {
        dummy->child->next = nullptr;
    }
    return dummy->child;
}

Node *flattenLinkedList(Node *head)
{
    if (!head || head->next == nullptr)
    {
        return head;
    }

    Node *mergedHead = flattenLinkedList(head->next);
    head = merge(head, mergedHead);
    return head;
}