#include<bits\stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    //construct
    Node(int data){
        this->data = data;
        this->next =NULL;
    }
};
void insertAtHead(Node* &head,int data){
    Node*temp = new Node(data);
    temp->next =head;
    head=temp;
}

void insertAtTail(Node* &tail,Node* &curr){
 tail->next =curr;
 tail=curr;
}
Node* sortlist(Node* &head){
    //create dummy node
    Node* zerohead=new Node(-1);
    Node* zerotail=zerohead;
    Node* onehead=new Node(-1);
    Node* onetail=onehead;
    Node* twohead=new Node(-1);
    Node* twotail=twohead;

    Node* curr=head;
    while(curr!=NULL){
        int value=curr->data;
        if(value==0){
            insertAtTail(zerotail,curr);
        }
     else if(value==1){
        insertAtTail(onetail,curr);
     }
     else if(value==2){
        insertAtTail(twotail,curr);
     }
     curr=curr->next;
    }

    if(onehead->next!=NULL){
        zerotail->next=onehead->next;
    }
    else{
        zerotail->next=twohead->next;
    }
    onetail->next=twohead->next;
    twotail->next=NULL;

    //setou head 
    head=zerohead->next;
    // delete dummy node
    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}

//remove dublicate node from sorted linkedlist
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
void print(Node* head){
    Node* temp = head;
    while(temp!= NULL){
      cout<<temp->data<<endl;
      temp=temp->next;
    }
}
int main(){
    Node* node1 = new Node(0);
    Node* head=node1;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,0);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,2);
    print(head);
    cout <<endl;
    Node* str=sortlist(head);
    print(str);
    cout << endl;
    head=uniqueSortedList(head);
    print(head);
}