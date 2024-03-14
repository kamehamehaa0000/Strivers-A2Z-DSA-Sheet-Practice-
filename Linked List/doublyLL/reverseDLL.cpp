#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
Node *convertArr2DLL(vector<int> arr)
{

    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

/* Brute Force Approach - Using Stack
Node *reverseDLL(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    stack<int> st;
    Node *temp = head;
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while (temp != NULL)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}
*/

/*Optimal approach*/
Node *reverseDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *current = head;
    Node *prev = nullptr;
    // idea is to swap prev with next and make next the new current
    while (current != nullptr)
    {
        prev = current->back;
        current->back = current->next;
        current->next = prev;

        current = current->back; // to go to next since we swapped the next with back
    }
    head = prev->back;
    return head;
}
int main()
{
    vector<int> arr = {12, 5, 8, 7, 4};
    Node *head = convertArr2DLL(arr);
    print(head);
    cout << endl;
    head = reverseDLL(head);
    print(head);
}
