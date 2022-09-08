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

bool iscircular(Node* &tail){
//empty list
if(tail==NULL){
    return true;
}
Node* temp = tail->next;
while (temp!=NULL&&temp!=tail){
    temp=temp->next;
}
if(temp==tail){
    return true;
}
return false;
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
    printNode(tail);
 
    insertNode(tail,3,5);
    printNode(tail);

    insertNode(tail,5,7);
    printNode(tail);


   if(iscircular(tail)){
    cout << "linkedlist is circular" << endl;
   }
   else{
    cout << "linkedlist is not circular" << endl;
   }
    return 0;
}