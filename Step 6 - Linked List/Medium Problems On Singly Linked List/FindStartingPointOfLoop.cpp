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
/*Brute force using hashing*/
ListNode *detectCycle(ListNode *head)
{
    unordered_map<ListNode *, int> mpp;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        if (mpp.find(temp) != mpp.end())
        {
            return temp;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return nullptr;
}
/*Optimal using tortoise hare algo*/

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow) // detects loop
        {
            // find starting point
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // or fast cause both will point to start of loop
        }
    }
    return nullptr;
}