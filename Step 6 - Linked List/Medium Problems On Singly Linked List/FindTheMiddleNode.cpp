#include <bits/stdc++.h>
using namespace std;

/* Definition for singly-linked list.*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*Brute force - finding length and then going to len/2 element
ListNode *middleNode(ListNode *head)
{
    int len = 0;
    ListNode *temp = head;
    while (temp)
    {
        len++;
        temp = temp->next;
    }

    temp = head;

    for (int i = 0; i < len / 2; i++)
    {
        temp = temp->next;
    }
    return temp;
}*/

/*Optimal method turtoise hare method*/
ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
