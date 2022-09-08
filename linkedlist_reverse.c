#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* next;
};
/*
A static function in C is a function that has a scope that is limited to its object file. This means that the static function is only visible in its object file.
*/
static void reverse(struct Node**  head_ref){
struct Node* prev=NULL;
struct Node* current=*head_ref;
struct Node* next=NULL;

while(current!=NULL){
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
}
*head_ref=prev;

}

void push(struct Node** head_ref,int new_data){
struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
new_node->data=new_data;
new_node->next=(*head_ref);
(*head_ref)=new_node;
}

void printlist(struct Node* head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
}

int main(){
struct Node* head=NULL;
push(&head,20);
push(&head,4);
push(&head,15);
push(&head,85);

printf("given link list\n");
printlist(head);
reverse(&head);
printf("reverse link list  is=\n");
printlist(head);
getchar();

    return 0;
}