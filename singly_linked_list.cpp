#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    struct Node *next;
};

Node* createNode(int e)
{
    Node *newnode = new Node;
    newnode->data = e;
    newnode->next = NULL;
}

int size(Node* root)
{
    int count=0;
    Node *node = root;
    while (node != NULL)
    {
        count += 1;
        node = node->next;
    }
    return count;
}

bool isEmpty(Node *root)
{
    return (root == NULL);
}

int nthItem(Node *root, int n)
{
    Node *node = root;
    int i=0;
    while (i<n)
    {
        node = node->next;
        i++;
    }
    return node->data;
}

Node* pushFront(Node *root, int value)
{
    Node *newnode = createNode(value);
    newnode->next = root;
    root = newnode;
    return root;
}

Node* popFront(Node *root)
{
    int e;
    Node *delnode = root;
    root = root->next;
    e = delnode->data;
    free(delnode);
    cout<<"Popped item : "<<e<<endl;
    return root;
}

void pushBack(Node *root, int value)
{
    Node *newnode = createNode(value);
    Node *node = root;
    while (node->next != NULL)
    {
        node = node->next;
    }
    node->next = newnode;
}

int popBack(Node *root)
{
    int e;
    Node *node = root;
    Node *prev = NULL;
    while (node->next != NULL)
    {
        prev = node;
        node = node->next;
    }
    prev->next = NULL;
    e = node->data;
    free(node);
    return e;
}

int front(Node *root)
{
    if (isEmpty(root))
    return -1;
    else
    return root->data;
}

int back(Node *root)
{
    if (isEmpty(root))
    return -1;
    Node *node = root;
    while (node->next != NULL)
    {
        node = node->next;
    }
    return node->data;
}

Node* insert(Node *root, int index, int value)
{
    if (index == 0)
    {
        root = pushFront(root, value);
        return root;
    }
    Node *prev = NULL;
    Node *node = root;
    Node *newnode = createNode(value);
    for (int i=0; i<index; i++)
    {
        prev = node;
        node = node->next;
    }
    prev->next = newnode;
    newnode->next = node;
    return root;
}

Node* erase(Node *root, int index)
{
    if (index == 0)
    {
        Node *delnode = root;
        root = root->next;
        free(delnode);
        return root;
    }
    Node *node = root;
    Node *prev = NULL;
    for (int i=0; i<index; i++)
    {
        prev = node;
        node = node->next;
    }
    prev->next = node->next;
    free(node);
    return root;
}

int value_n_from_end(Node *root, int n)
{
    int l = size(root);
    int index = l-n;
    int item = nthItem(root, index);
    return item;
}

void removeValue(Node *root, int val)
{
    int k=0;
    Node *node = root;
    Node *prev = NULL;
    while (node->next != NULL)
    {
        if (node->data == val)
        {
            k = 1;
            break;
        }
        prev = node;
        node = node->next;
    }
    if (k==1)
    {
        prev->next = node->next;
        free(node);
    }
}

void printLinkedList(Node *root)
{
    Node *node = root;
    while (node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<endl;
}

int main()
{
    // Add reverse function also 

    Node *root = createNode(24);
    root->next = createNode(3);
    root->next->next = createNode(4);
    root->next->next->next = createNode(12);
    root->next->next->next->next = createNode(1);
    cout<<isEmpty(root)<<endl;
    printLinkedList(root);
    int s = size(root);
    cout<<"Size : "<<s<<endl;
    int item = nthItem(root, 3);
    cout<<"3rd item : "<<item<<endl;
    root = pushFront(root, 45);
    root = pushFront(root, 7);
    printLinkedList(root);
    root = popFront(root);
    printLinkedList(root);
    pushBack(root, 100);
    pushBack(root, 156);
    printLinkedList(root);
    cout<<popBack(root)<<endl;
    printLinkedList(root);
    cout<<front(root)<<endl;
    cout<<back(root)<<endl;
    root = insert(root, 4, 77);
    printLinkedList(root);
    root = insert(root, 0, 89);
    printLinkedList(root);
    root = insert(root, 8, 90);
    printLinkedList(root);
    root = erase(root, 5);
    printLinkedList(root);
    root = erase(root, 0);
    printLinkedList(root);
    erase(root, 7);
    printLinkedList(root);
    cout<<"Nth value from end for n = 3 : "<<value_n_from_end(root, 3)<<endl;
    removeValue(root, 67);
    printLinkedList(root);
    removeValue(root, 3);
    printLinkedList(root);
    return 0;
}