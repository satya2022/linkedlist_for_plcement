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
void insertAtHead(Node* &head,int d){
Node* temp=new Node(d);
temp->next = head;
head=temp;
}

Node* solve(Node* first,Node* second){
    //if only one element is persent in the first list, then
    if(first->next==NULL){
        first->next = second;
        return first;
    }
    Node* curr1 = first;
    Node* next1=curr1->next;
    Node* curr2=second;
    Node* next2=curr2->next;

    while(next1!=NULL&&next2!=NULL){
    if((curr2->data>=curr1->data)&&(curr2->data<=next1->data)){
       //add a node in between the first list
       curr1->next=curr2;
       next2=curr2->next;
       curr2->next=next1;
       curr1=curr2;
       curr2=next2;
         
    }
    else{
        //curr1 and next1 ko aage badhana parega
       curr1=next1;
       next1=next1->next;
       if(next1==NULL){
        curr1->next=curr2;
        return first;
       }
    }
}
return first;
}

Node* sortTwoList(Node* first,Node* second){
    if(first==NULL)
    {
        return second;
    }
    if(second==NULL)
    {
        return first;
    }
    if(first->data<=second->data){
        return solve(first,second);
    }
    else{
        return solve(second,first);
    }
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
    Node* first=node1;
    Node* second=NULL;
    insertAtHead(first,5);
    insertAtHead(first,3);
    insertAtHead(first,1);
    print(first);
    cout <<endl;
    cout<<"printin second node"<<endl;
    insertAtHead(second,5);
    insertAtHead(second,4);
    insertAtHead(second,2);
    print(second);
    cout<<endl;
    
Node* satya=sortTwoList(first,second);
print(satya);

    return 0;
}
