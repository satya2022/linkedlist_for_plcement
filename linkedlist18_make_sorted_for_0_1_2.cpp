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

Node* sortlist(Node* &head){
    int zerocount=0;
    int onecount=0;
    int twocount=0;
    Node* temp=head;

    while(temp!=NULL){

        if(temp->data==0){
            zerocount++;
        }
        else if(temp->data==1){
            onecount++;
        }
       else if(temp->data==2){
            twocount++;
        }
      
        temp=temp->next;
       
    }
    temp=head;
    while(temp!=NULL){
    if(zerocount!=0){
        temp->data=0;
        zerocount--;
    }
    else if(onecount!=0){
        temp->data=1;
        onecount--;
    }
    else if(twocount!=0){
        temp->data=2;
        twocount--;
    }
          temp=temp->next;

    }
    return head;
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int main(){
   Node* node1=new Node(0);
   Node* head=node1;
   insertAtHead(head,1);
   insertAtHead(head,0);
   insertAtHead(head,1);
   insertAtHead(head,2);
   insertAtHead(head,2);
   insertAtHead(head,1);
   print(head);
   cout<<endl;

   Node* str=sortlist(head);
   print(str);


    return 0;
}