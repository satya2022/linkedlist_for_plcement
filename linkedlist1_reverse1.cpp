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
void reverselinkedlist(Node* &head){
Node* prev=NULL;
Node* next=NULL;
Node* curr=head;
while(curr!=NULL){
  next=curr->next;
  curr->next=prev;
  prev=curr;
  curr=next;
}
head=prev;
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int main(){
   Node* node1=new Node(6);
   Node* head=node1;
   insertAtHead(head,4);
   insertAtHead(head,1);
   insertAtHead(head,2);
   insertAtHead(head,3);
   print(head);
   cout<<endl;
   reverselinkedlist(head);
   print(head);

    return 0;
}