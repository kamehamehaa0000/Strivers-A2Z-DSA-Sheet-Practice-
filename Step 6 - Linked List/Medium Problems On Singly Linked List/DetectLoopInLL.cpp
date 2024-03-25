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
/*Brute force - using hashing
bool hasCycle(ListNode *head)
{
    unordered_map<ListNode *, int> mpp;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        if (mpp.find(temp) != mpp.end())
        { // node already visited
            return true;
        }
        mpp[temp] = 1; // storing current node in hashmap
        temp = temp->next;
    }
    return false;
}*/

/*Optimal using tortoise and hare method*/
bool hasCycle(ListNode *head)
{
    if (head == nullptr)
    {
        return false;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        if (slow == fast)
        {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}