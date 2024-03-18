#include <bits/stdc++.h>
using namespace std;

// Definition of doubly linked list:
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};
/* Brute Force
vector<pair<int, int>> findPairs(Node *head, int k)
{
    vector<pair<int, int>> ans;
    Node *temp = head;
    Node *temp2 ;
    while (temp != nullptr)
    {
        temp2 = temp->next;
        while (temp2 != nullptr && temp->data + temp2->data <= k )
        {
            if (temp->data + temp2->data == k)
            {
                ans.push_back({temp->data, temp2->data});
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    return ans;
}
*/
/*Optimised*/
vector<pair<int, int>> findPairs(Node *head, int k)
{
    vector<pair<int, int>> ans;
    Node *left = head;
    Node *right = head;
    while (right->next != nullptr)
    {
        right = right->next;
    }
    while (left->data < right->data) // since list is sorted
    {
        if (left->data + right->data == k)
        {
            ans.push_back({left->data, right->data});
            right = right->prev;
        }
        else if (left->data + right->data < k)
        {
            left = left->next;
        }
        else //(left->data + right->data > k)
        {
            right = right->prev;
        }
    }
    return ans;
}