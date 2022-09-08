// DELATE NODE AT ANY POSITION
#include <bits\stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
  
};


void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

Node* uniqueSortedList(Node* head){
    //empty list
    if(head==NULL) {
        return NULL;
        }
    //non empty list
    Node* curr = head;

    while(curr!=NULL) {
     if((curr->next!=NULL)&&curr->data==curr->next->data) 
     {
        //curr->next=curr->next->next;//logig is that but code will be rong
        Node* next_next=curr->next->next;
       Node* NodeTodelete=curr->next;
       delete (NodeTodelete);
       curr->next=next_next;
     }
     //not equal 
     else{
         curr = curr->next;
     }
    }  
    return head; 
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head, 7);
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 4);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    insertAtHead(head, 6);
    insertAtHead(head, 7);
    insertAtHead(head, 8);
    insertAtHead(head, 9);
 
    print(head);
    cout << endl;
    head=uniqueSortedList(head);
    print(head);
    return 0;
}