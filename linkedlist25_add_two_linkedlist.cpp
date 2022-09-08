#include<bits\stdc++.h>
using namespace std;
class Node{
    public:
    int data; 
    Node* next;
    //constructor
    Node(int data){
        this->data = data;
        this->next =NULL;
    }
};
void insertAtHead(Node* &head,int data){
    Node* temp=new Node(data);
    temp->next =head;
    head=temp;
}

Node* reverse(Node* &head){
    Node* curr=head;
    Node* prev=NULL;
    Node* next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
void insertAtTail(Node* &head,Node* &tail,int val) {
    Node* temp =new Node(val);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}


Node* add(Node* first, Node* second){
int carry=0;
Node* ansHead=NULL;
Node* ansTail=NULL;
while(first!=NULL||second!=NULL||carry!=0){
    int val1=0;
    if(first!=NULL){
        val1=first->data;
    }
    int val2=0;
    if(second!=NULL){
        val2=second->data;
    }
    int sum=carry+val1+val2;
    int digit=sum%10;

    //create node add and in answer linkedlist
    insertAtTail(ansHead, ansTail, digit);

    carry=sum/10;
    if(first!=NULL){
    first=first->next;
    }
    if(second!=NULL){
    second=second->next;
    }
}
return ansHead;
}



Node* addTwoList(Node* first, Node* second){
//stape1=reverse input linkedlist
first=reverse(first);
second=reverse(second);
//stape=add two linkedlist
Node* ans=add(first,second);
//stape3=reverse added linkedlist
ans=reverse(ans);
return ans;
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }

}


int main(){
    Node* node1= new Node(4);
    Node* first=node1;
    Node* second=NULL;
    insertAtHead(first,2);
    insertAtHead(first,1);
    print(first);
    cout<<endl;
    insertAtHead(second,8);
    insertAtHead(second,7);
    insertAtHead(second,6);
    insertAtHead(second,5);
    print(second);
    cout<<endl;
   Node *str=addTwoList(first,second);
   print(str);

   

}