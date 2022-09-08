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

    // stape2-> cloneNode add in beetween orignal list

    Node *orignalNode = head;
    Node *cloneNode = cloneHead;
    while (orignalNode != NULL&&cloneNode != NULL)
    {
        Node* next = orignalNode->next;
        orignalNode->next=cloneNode;
        orignalNode = next;
        /////
        next=cloneNode->next;
        cloneNode->next=orignalNode;
        cloneNode=next;
    }
    //stape3->rendom pointer copy
    temp =head;
    while(temp != NULL){
        if(temp->next != NULL){
            if(temp->random != NULL){
                temp->next->random=temp->random->next;
            }
            else{
                temp->next=temp->random;
            }
      //temp->next->random=temp->random?temp->next->random->next:temp->random;

            temp=temp->next->next;           
        }
    }
    //stape4->revert changes done in stape2
    orignalNode=head;
    cloneNode=cloneHead;
    while(orignalNode != NULL&&cloneNode != NULL){
        orignalNode->next=cloneNode->next;
        orignalNode=orignalNode->next;
        if(orignalNode!= NULL){
            cloneNode->next=orignalNode->next;
        }
        cloneNode=cloneNode->next;
       
    }

    //return ans
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

/*
void print(Node *&head){
    Node *temp =head;
    while(temp!= NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}
*/

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
