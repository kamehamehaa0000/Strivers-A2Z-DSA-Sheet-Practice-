#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
/* Brute force approach using stack
Node *reverseLinkedList(Node *head)
{

    Node *temp = head;
    stack<int> st;

    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}
*/
/*Optimal using iterative approach
Node *reverseLinkedList(Node *head)
{
    Node *current = head;
    Node *prev = nullptr;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    return head;
}*/
/* optimal using recursive approach*/
Node *reverseLinkedList(Node *head)
{ // base condition :
  // If the linked list is empty or has only one node,return the head as it is already reversed.
    if (head->next == nullptr || head == nullptr)
    {
        return head;
    }
    // Reverse the linked list starting from the second node (head->next).
    Node *newHead = reverseLinkedList(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
}
int main()
{
    // Create a linked list with
    // values 1, 3, 2, and 4
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}
