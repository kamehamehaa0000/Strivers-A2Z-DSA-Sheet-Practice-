#include <bits/stdc++.h>
using namespace std;
// defination of singly linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/* Brute Force*/
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }

    int cnt = 0;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    if (cnt - n == 0) // if head is the element to be removed
    {
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    temp = head;
    int prev = 0; // index of prev Node of Nth node
    ListNode *prevNode = nullptr;
    while (temp != nullptr)
    {
        prev++;
        if (prev == cnt - n)
        {
            ListNode *delNode = temp->next;
            prevNode = temp;
            prevNode->next = prevNode->next->next;
            delete delNode;
            break;
        }
        temp = temp->next;
    }

    return head;
}
/*Optimal solution*/
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *fast = head;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    if (fast == nullptr) // if head = nth element
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    ListNode *slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }
    // slow will point to prev node of nth element

    ListNode *delNode = slow->next; // nth node that will be deleted;
    slow->next = slow->next->next;

    delete delNode;
    return head;
}