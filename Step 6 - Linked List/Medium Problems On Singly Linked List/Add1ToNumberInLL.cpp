/**
 * Definition for singly-linked list.

 */
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
/*Brute force using reversing the LL
Node *reverseLL(Node *head)
{
    if (head->next == nullptr || head == nullptr)
    {
        return head;
    }
    // Reverse the linked list starting from the second node (head->next).
    Node *newHead = reverseLL(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

Node *addOne(Node *head)
{
    head = reverseLL(head);
    Node *temp = head;
    int carry = 1;
    while (temp != nullptr)
    {
        temp->data = temp->data + carry;
        if (temp->data < 10)
        {
            carry = 0;
            break;
        }
        else
        {
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }
    if (carry == 1)
    {
        Node *newNode = new Node(1);
        head = reverseLL(head);
        newNode->next = head;
        head = newNode;
        return head;
    }
    head = reverseLL(head);
    return head;
}
*/
/*Optimal solution using recursion*/
int helper(Node *head)
{
    if (head == nullptr)
    {
        return 1; // Indicate a carry if the list ends
    }

    int carry = helper(head->next);
    head->data += carry;

    if (head->data < 10)
    {
        return 0; // No carry
    }
    else
    {
        head->data = 0; // Adjust current digit
        return 1;       // Indicate carry
    }
}

Node *addOne(Node *head)
{
    int carry = helper(head);
    if (carry == 1)
    {
        // If there's a carry after the recursive process,
        // create a new node with value 1 and attach it to the head.
        Node *newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
    return head;
}
