#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverse(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *newHead = reverse(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
ListNode *findKthNode(ListNode *temp, int k)
{
    k -= 1;
    while (temp != nullptr && k > 0)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head;
    ListNode *kthNode;
    ListNode *nextNode = nullptr;
    ListNode *prevNode = nullptr;

    while (temp != nullptr)
    {
        ListNode *kthNode = findKthNode(temp, k);
        if (kthNode == nullptr) // if there is no kthNode
        {
            if (prevNode)
            {
                prevNode->next = temp;
            }
            break;
        }
        nextNode = kthNode->next; // remembering the next node after kth node
        kthNode->next = nullptr;  // seperating the current k nodes linked list
        reverse(temp);            // will reverse the current list of k nodes and return kthnode as newHead
        if (temp == head)
        {
            head = kthNode;
        }
        else
        {
            prevNode->next = kthNode;
        }
        prevNode = temp;
        temp = nextNode;
    }
    return head;
}
