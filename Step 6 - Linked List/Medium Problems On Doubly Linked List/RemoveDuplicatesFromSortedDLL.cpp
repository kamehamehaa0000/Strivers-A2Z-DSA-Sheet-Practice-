#include <bits/stdc++.h>
using namespace std;
//  List will be sorted
//  Definition of doubly linked list:
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

Node *removeDuplicates(Node *head)
{
    Node *temp = head;

    while (temp->next != nullptr)
    {
        if (temp->data == temp->next->data)
        {
            Node *delNode = temp->next;
            temp->next = temp->next->next;
            if (temp->next != nullptr)
            {
                temp->next->prev = temp;
            }
            delete delNode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}
