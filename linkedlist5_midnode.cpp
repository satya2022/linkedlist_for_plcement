#include<bits\stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
       this->data = data;
       this->next =NULL;
    }
};
void insertAtHead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next =head; 
    head=temp;

}
Node* findmidNode(Node* &head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    if(head->next->next==NULL){
        return head->next;
    }
    Node* fast = head->next;
    Node* slow = head;
    while(fast!=NULL){
        fast= fast->next;
        if(fast!=NULL){
            fast= fast->next;
            slow=slow->next; ;
        }
    }
    return slow;
    return slow->next;
}
Node* midNode(Node* &head){
  return findmidNode(head);
}

void print(Node* &head){
    Node* temp = head;
     while(temp !=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
     }
    
}
int main(){
    Node* node1=new Node(9);
    Node* head=node1;
    insertAtHead(head,5);
    insertAtHead(head,7);
    insertAtHead(head,6);
    insertAtHead(head,3);
    insertAtHead(head,2);
    print(head);
   Node*curr= midNode(head);
   cout<<"mid_node: "<<curr->data<<endl;

    return 0;
}