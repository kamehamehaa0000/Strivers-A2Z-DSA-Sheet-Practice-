#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// by reversing preOrder
vector<int> postOrderIterative(Node *root)
{
    vector<int> answer;
    stack<Node *> s;
    Node *current = root;
    s.push(current);

    while (!s.empty())
    {
        current = s.top();
        s.pop();
        answer.push_back(current->data);

        if (current->left)
        {
            s.push(current->left);
        }

        if (current->right)
        {
            s.push(current->right);
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

/* striver solution*/
vector<int> postOrderIterative(Node *root)
{
    if (root == nullptr)
    {
        return {};
    }

    vector<int> answer;
    stack<Node *> st;
    Node *current = root;
    st.push(current);

    while (current != nullptr || !st.empty())
    {
        if (current != nullptr)
        {
            st.push(current);
            current = current->left;
        }
        else
        {
            Node *temp = st.top()->right;
            // if we are at leafnode
            if (temp == nullptr)
            {
                temp = st.top();
                st.pop();
                answer.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    answer.push_back(temp->data);
                }
            }
            else
            {
                current = temp;
            }
        }
        return answer;
    }
}