#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }

public:
    Node(int data1, Node *back1, Node *next1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
};
void printDLL(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    Node *head = new Node(40);
    Node *secondNode = new Node(50, head, nullptr);
    head->next = secondNode;
    printDLL(head);
    return 0;
}