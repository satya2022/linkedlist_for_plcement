#include<bits\stdc++.h>
using namespace std;
class Node {
    public:
       int data;
       Node* next;
       //constructor
       Node(int data){
        this->data = data;
        this->next = NULL;
       }
};


void insertAtHead(Node* &head,int data){
  Node*temp=new Node(data);
  temp->next = head;
  head=temp;

}

void insertAtTail(Node* &tail,Node* curr){
    tail->next = curr;
    tail=curr;
}

Node* sortAtHead(Node* &head){
    Node* zerohead=new Node(-1);
    Node* zerotail=zerohead;
    Node* onehead=new Node(-1);
    Node* onetail=onehead;
    Node* twohead=new Node(-1);
    Node* twotail=twohead;

    Node* curr=head;
    while(curr!=NULL) {
        int value=curr->data;
        if(value==0) {
            insertAtTail(zerotail,curr);
        }
        else if(value==1) {
            insertAtTail(onetail,curr);

        }
        else if(value==2) {
            insertAtTail(twotail,curr);
        }
        curr=curr->next;
    }
    //marge 3 sublist

    //is list non empthy
    if(onehead->next!=NULL){
        zerotail->next=onehead->next;
    }
    else{
        zerotail->next=twohead->next;
    }
    onetail->next=twohead->next;
    twotail->next=NULL;

    //setup  head 
    head=zerohead->next;
    //delete dummy node
    delete zerohead;
    delete onehead;
    delete twohead;

    return head;

}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int main(){
   Node* node1=new Node(0);
   Node* head=node1;
   insertAtHead(head,1);
   insertAtHead(head,0);
   insertAtHead(head,1);
   insertAtHead(head,2);
   insertAtHead(head,2);
   insertAtHead(head,1);
   print(head);
   cout<<endl;

   Node* str=sortAtHead(head);
   print(str);


    return 0;
}