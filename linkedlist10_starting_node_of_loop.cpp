
//INSERTING AT ANY POSITION
#include<bits\stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
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

void insertAtTail(Node* &tail,int d){
    Node* temp= new Node(d);
    tail->next=temp;
    tail=temp;
}

void insertAtposition(Node* &tail,Node* &head,int position,int d){
    if(position==1){
        insertAtHead(head,d);
        return;
    }

    Node* temp=head;
int cnt=1;
while(cnt<position-1){
temp=temp->next;
cnt++;
}
//inserting at last position (whan poision is last)
if(temp->next==NULL){
    insertAtTail(tail,d);
    return;
}
//creating a node for d
Node* nodetoinsert= new Node(d);
nodetoinsert->next=temp->next;
temp->next=nodetoinsert;
}

/*
bool detectloop(Node* head){
    if(head==NULL) {
    return false;
    }
    map<Node*,bool>visited;
    Node* temp = head;
    while(temp!=NULL){
        //cycle is persent
        if(visited[temp]==true) {
            cout << "present on element"<<temp->data<<endl;
            return true;
        }
        visited[temp]=true;
        temp = temp->next;
        }
        return false;

    }

*/
Node* floydDetectLoop(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while(slow!=NULL&&fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow==fast){
            cout<<"persent at"<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}

Node* getstartingNode(Node* head){
    if (head==NULL)
    {
        return NULL;
    }
    Node* insertion=floydDetectLoop(head);
    Node* slow=head;
    while(slow!=insertion){
        slow=slow->next;
        insertion=insertion->next;
    }
    return slow;
    
}

void print(Node* &head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp= temp->next;
    }
}

int main(){
Node* node1 = new Node(7);
Node* head=node1;
Node* tail=node1;
insertAtTail(tail,6);
insertAtTail(tail,3);
insertAtTail(tail,9);
insertAtposition(tail,head,3,8);
insertAtposition(tail,head,3,4);
insertAtposition(tail,head,1,1);
insertAtposition(tail,head,7,12);
cout<<"head"<<head->data<<endl;
cout<<"tail"<<tail->data<<endl;
print(head);
tail->next = head->next;
cout<<"head"<<head->data<<endl;
cout<<"tail"<<tail->data<<endl;
// print(head);
if(floydDetectLoop(head)!=NULL){
    cout<<"cycle  is persent"<<endl;
}
else{
    cout<<"cycle is not persent"<<endl;
}

Node* begnigNode = getstartingNode(head);
cout<<"begnigNode is"<<begnigNode->data<<endl;

    return 0;
}