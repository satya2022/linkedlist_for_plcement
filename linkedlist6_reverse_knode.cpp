#include<bits\stdc++.h>
using namespace std;
class Node {
    public:
int data; 
Node* next;
//constrector
Node(int data){
this->data = data;
this->next = NULL;
}
};

void insertAtHead(Node* &head,int d) {
Node* temp =new Node(d);
temp->next = head;
head=temp;
}


void print(Node* &head){
Node *temp = head;
while(temp!=NULL){
    cout<<temp->data<<endl;
    temp = temp->next;
}
}


Node* reverseKNode(Node* head,int k) {
    //base case for
    if(head==NULL){
        return NULL;
    }
    //step 1 =reverse k node
    int cnt=0;
    Node* prev = NULL;
    Node* next = NULL;
    Node* curr = head;
   //first one node first we wave to reverse
    while(curr!=NULL&&cnt<k){
      next=curr->next;
      curr->next=prev;
      prev=curr;
      curr=next;
      cnt++;

    }
    //step2=recursion dakh lega aage
    if(next!=NULL){
        head->next=reverseKNode(next,k);
    }
    //step3= return head of reversed list
    return prev;
}


int main(){
    Node* node1=new Node(9);
    Node* head=node1;
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,5);
    insertAtHead(head,6);
    print(head);
    cout <<endl;
    Node* str=reverseKNode(head,2);
    print(str);

    return 0;
}