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
ListNode *deleteMiddle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    ListNode *temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    temp = head;
    int prev = 0;
    while (temp != nullptr)
    {
        prev++;
        if (prev == cnt / 2)
        {
            ListNode *delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}
ListNode *deleteMiddle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;
    while (fast != nullptr && fast->next != nullptr)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    // prev will point to node just before middle node(slow);
    ListNode *middle = slow;
    prev->next = slow->next;
    delete middle;
    return head;
}
