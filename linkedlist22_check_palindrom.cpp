#include<bits\stdc++.h>
using namespace std;
class Node{
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
    Node* temp = new Node(data);
    temp->next = head;
    head=temp;
}

Node* getMid(Node* &head){
    Node* fast = head->next;
    Node* slow = head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;
}

Node* reverse(Node* &head){
    Node* curr= head;
    Node* prev= NULL;
    Node* next= NULL;

    while(curr!=NULL){
        next= curr->next;
        curr->next= prev;
        prev= curr;
        curr=next;
    }
    return prev;
    }

bool isplindrome(Node *&head){
    if(head==NULL|| head->next==NULL){
        return true;
    }
    //stape1=find middle node
    Node* middle = getMid(head);
    //stape2=reverse middle next all node
    Node* temp = middle->next;
    middle->next =reverse(temp);
    //stape3=compare both half
    Node* head1=head;
    Node* head2=middle->next;
    while(head2!=NULL){
        if(head1->data!=head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    /*stape4=repet stape2*/
    // temp=middle->next;
    // middle->next=reverse(temp);
    return true;
    }

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int main(){
    Node* node1=new Node(1);
    Node* head=node1;
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    print(head);
    cout<<endl;
    Node* str=getMid(head);
    cout<<isplindrome(head);

}