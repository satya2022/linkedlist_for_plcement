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

Node* reverse1(Node* &head){
//base case
if(head==NULL||head->next==NULL){
    return head;
}
Node* chotahead=reverse1(head->next);
head->next->next=head;
head->next=NULL;

return chotahead;
}

Node* reverselinkedlist(Node* head){

return reverse1(head);
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
   //hare we retuen chotahead(it mean last)
   //now we have to print(head=chotahead)
   head= reverselinkedlist(head);
   print(head);

    return 0;
}