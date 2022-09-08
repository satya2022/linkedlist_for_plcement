#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    //constructor
    Node(int d){
        this->data = d;
        this->next =NULL;
    }
    ~Node(){
     int value = this->data;
     if(this->next!=NULL)
     {
        delete next;
        next=NULL;
        }
        cout<<"memory is free for this data"<<value<<endl;
    }
};
void insertNode(Node* &tail,int element,int d){
//when list is empty
if(tail==NULL){
   Node* newnode = new Node(d); 
   tail=newnode;
   newnode->next=newnode;
}
else{
    //non empthy list
    //assuming that the element is present in the list
    Node* curr=tail;
    while(curr->data!=element){
        curr=curr->next;
    }
    //element is found in the list
    Node* temp = new Node(d);
    temp->next=curr->next;
    curr->next=temp;
}
}

int getlength(Node* tail) {
 
 Node*str=tail;
   int len = 0;
   while(str->next != tail) {
       len++;
       str = str -> next;
   }
   return len;
}

Node* findMiddle(Node *tail) {
    int len = getlength(tail);
   int ans = (len/2);
   
   int cnt = 0;
   Node* temp = tail;
   while(cnt<ans) {
    temp = temp -> next;
     cnt++;
   }
   
   return temp;
}



Node* secondcirlinkedlist(Node* &tail,Node* &str1){
    Node* head2=str1;
    Node* str=tail;
     while(str->next != tail) {
       str = str -> next;
   }
  str->next = str1;
  return str1;

}

void printNode(Node* &tail){

    /*
    Node*temp=tail;
    //if we have single node
    cout<<tail->data<<" ";
    while(tail->next!=temp){
        cout<<" "<<temp->data<<" ";
        tail=tail->next;
    }
    */
    
//we can also do with do while loop
Node* temp=tail;
do{
    
   cout<<tail->data<<" ";
   tail=tail->next;

}while(tail !=temp);
cout<<endl;
    
}

int main(){
    Node* tail=NULL;
    insertNode(tail,5,3);
 
    insertNode(tail,3,5);

    insertNode(tail,5,7);

    insertNode(tail,7,9);

    insertNode(tail,5,6);

    insertNode(tail,9,10);
    printNode(tail);
    
    Node*str1=findMiddle(tail);
    cout<<"mid Node is"<<str1->data<<endl;
    cout<<"mid next Node is"<<" "<<str1->next->data<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    Node* printsecond=secondcirlinkedlist(tail,str1);
    printNode(printsecond);


    return 0;
}