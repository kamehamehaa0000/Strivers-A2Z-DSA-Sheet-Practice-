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
Node *convertArrToLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp; // or mover = mover->next;
    }
    return head;
}
void printLL(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data;
        temp = temp->next;
    }
}
// deletion of head;
Node *deleteHeadNode(Node *head)
{
    if (head == nullptr) // if LL is empty
    {
        return head;
    }
    Node *temp = head;
    head = head->next;
    delete temp; // freed the prev head stored in temp

    return head;
}
// delete last node
Node *deleteTailNode(Node *head)
{
    if (head == nullptr || head->next == nullptr) // if has one node or is empty
    {
        delete head;
        return nullptr;
    }
    Node *temp = head;
    while (temp->next->next != nullptr) // finding second last element
    {
        temp = temp->next;
    }
    delete temp->next;    // delete last element
    temp->next = nullptr; // make second last the last element
    return head;
}
// delete kth element
Node *deleteKthNode(Node *head, int k)
{
    if (head == nullptr) // if LL is empty
    {
        return head;
    }
    if (k == 1) // if k is head node
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    Node *prev = nullptr;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next; // make prev node of kth node point to k+1th node
            delete temp;                   // delete the kth node
            break;
        }
        prev = temp;       // make temp the prev
        temp = temp->next; // move temp to next node
    }
    return head;
}
// delete from value of node or data  of node
Node *deleteNodeByValue(Node *head, int el)
{
    if (head == nullptr) // if LL is empty
    {
        return head;
    }
    if (head->data == el) // if k is head node
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    Node *prev = nullptr;

    while (temp != nullptr)
    {
        if (temp->data == el)
        {
            prev->next = prev->next->next; // make prev node of kth node point to k+1th node
            delete temp;                   // delete the kth node
            break;
        }
        prev = temp;       // make temp the prev
        temp = temp->next; // move temp to next node
    }
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertArrToLL(arr);
    head = deleteHeadNode(head);       // removing head; 2 3 4 5
    head = deleteTailNode(head);       // removing tail node; // 2 3 4
    head = deleteKthNode(head, 2);     // removing 2nd node // 2 4
    head = deleteNodeByValue(head, 4); // removing node with data 4 // 2
    // Traversal and length of LL
    printLL(head);
}
