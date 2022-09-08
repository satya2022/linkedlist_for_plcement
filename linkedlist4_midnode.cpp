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
int getlength(Node* head) {
 
   int len = 0;
   while(head != NULL) {
       len++;
       head = head -> next;
   }
   return len;
}

Node* findMiddle(Node *head) {
    int len = getlength(head);
   int ans = (len/2);
   
   int cnt = 0;
   Node* temp = head;
   while(cnt<ans) {
    temp = temp -> next;
     cnt++;
   }
   
   return temp;
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
   insertAtHead(head,5);
   insertAtHead(head,8);
   print(head);
   cout<<endl;
  Node* curr=findMiddle(head);
   cout<<curr->data<<endl;
  

    return 0;
}