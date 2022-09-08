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
while(first!=NULL&&second!=NULL){
    int sum=carry+first->data+second->data;
    int digit=sum%10;

    //create node add and in answer linkedlist
    insertAtTail(ansHead, ansTail, digit);

    carry=sum/10;
    first=first->next;
    second=second->next;
}
while(first!=NULL){
    int sum=carry+first->data;
    int digit=sum%10;
    //create node and add in answer linkedlist
    insertAtTail(ansHead, ansTail, digit);
    carry=sum/10;
    first=first->next;
}
while(second!=NULL){
    int sum=carry+second->data;
    int digit=sum%10;
    //create node and add in answer linkedlist
    insertAtTail(ansHead, ansTail, digit);
    carry=sum/10;
    second=second->next;
}
//carry bach gya kya

while(carry!=0){
    int sum=carry;
    int digit=sum%10;
    //create node and add in answer linkedlist
    insertAtTail(ansHead, ansTail, digit);
    carry=sum/10;
}

return ansHead;

}

Node* addTwoList(Node* first, Node* second){
//stape1=reverse input linkedlist
first=reverse(first);
second=reverse(second);
//stape2=add two linkedlist
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
    Node*str=addTwoList(first,second);
    print(str);

}