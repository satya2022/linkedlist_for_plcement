#include <bits\stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *random;
    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

Node *copyList(Node *&head)
{
    // stape1-> create a clone list
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // stape2-> create a map

    unordered_map<Node *, Node *> oldToNewNode;
    Node *orignalNode = head;
    Node *cloneNode = cloneHead;
    while (orignalNode != NULL)
    {
        oldToNewNode[orignalNode] = cloneNode;
        orignalNode = orignalNode->next;
        cloneNode = cloneNode->next;
    }
    orignalNode = head;
    cloneNode = cloneHead;
    while (orignalNode != NULL)
    {
        cloneNode->random = oldToNewNode[orignalNode->random];
        orignalNode = orignalNode->next;
        cloneNode = cloneNode->next;
    }
    return cloneHead;
}

void printRandom(Node *head)
{
    while (head != NULL)
    {
        cout << " head data: " << head->data << " ";
        if (head->random != NULL)
        {
            cout << " head random data" << head->random->data << endl;
        }
        else
        {
            cout << " head random data: NULL";
        }
        head = head->next;
        cout << endl;
    }
}

void print(Node *&head){
    Node *temp =head;
    while(temp!= NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

int main()
{
    // Creating a linked list with random pointer
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;

    // Print the original list
    cout << "The original linked list:\n";
    printRandom(head);

    // Function call
    Node *str = copyList(head);

    cout << "The cloned linked list:\n";
    printRandom(str);

    return 0;
}
