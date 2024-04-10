#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    class Node
    {
    public:
        int key;
        int data;
        Node *next;
        Node *prev;

        Node(int key1, int data1)
        {
            key = key1;
            data = data1;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    unordered_map<int, Node *> mpp;
    int size;
    LRUCache(int capacity)
    {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *newNode)
    {
        Node *temp = head->next;
        newNode->prev = head;
        newNode->next = temp;
        head->next = newNode;
        temp->prev = newNode;
    }
    void deleteNode(Node *delNode)
    {
        Node *back = delNode->prev;
        Node *front = delNode->next;
        back->next = front;
        front->prev = back;
    }

    int get(int key)
    {
        if (mpp.find(key) != mpp.end())
        {
            Node *temp = mpp[key];
            int value = temp->data;
            mpp.erase(key);
            deleteNode(temp);
            addNode(temp);
            mpp[key] = head->next; // changing the node address in the hashmap
            return value;
        }

        return -1;
    }

    void put(int key, int value)
    {
        // if key already present in mpp
        if (mpp.find(key) != mpp.end())
        {
            Node *existing = mpp[key];
            mpp.erase(key);
            deleteNode(existing);
        }
        // if cache is full
        if (mpp.size() == size)
        { // remove least recent node
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        // if not above condition simply insert the node after head
        Node *newNode = new Node(key, value);
        addNode(newNode);
        mpp[key] = head->next;
    }
};