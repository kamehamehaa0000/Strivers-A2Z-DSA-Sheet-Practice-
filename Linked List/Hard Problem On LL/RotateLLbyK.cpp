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
// approach that first that came to my mind
ListNode *rotateRight(ListNode *head, int k)
{

    if (!head || k == 0)
        return head;

    int length = 1;
    ListNode *temp = head;
    while (temp->next)
    {
        length++;
        temp = temp->next;
    }
    temp = nullptr;

    k = k % length; // Effective rotation steps cause multiple of length will result in original config

    for (int i = 0; i < k; i++)
    {
        ListNode *prev = nullptr;
        temp = head;
        while (temp->next)
        {
            prev = temp;
            temp = temp->next;
        }
        temp->next = head;
        head = temp;
        prev->next = nullptr;
    }
    return head;
}
// Approach 2 - better
ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || k == 0)
        return head;

    int length = 1;
    ListNode *tail = head;
    while (tail->next)
    {
        length++;
        tail = tail->next;
    }
    if (k % length == 0)
    {
        return head;
    }
    k = k % length;
    tail->next = head;
    ListNode *temp = head;
    int cnt = 1;
    while (temp != nullptr)
    {

        if (cnt == length - k)
        {
            break;
        }
        cnt++;
        temp = temp->next;
    }

    head = temp->next;
    temp->next = nullptr;
    return head;
}