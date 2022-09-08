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
bool checkPalindrom(vector<int>arr){
    int n=arr.size();
    int s=0;
    int e=n-1;
    while (s<=e)
    {
        if(arr[s]!=arr[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
    
}

// function to cheak whether the list is palindrom 
bool isPalindrom(Node* &head){
    vector<int>arr;
    Node* temp = head;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    return checkPalindrom(arr);
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
    cout<<isPalindrom(head)<<endl;


}