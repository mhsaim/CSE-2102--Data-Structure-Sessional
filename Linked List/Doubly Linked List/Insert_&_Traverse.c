#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;n
};
struct Node* createNode(int value) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode=createNode(value);
    if(*head==NULL){
        *head=newNode;
    }else{
        newNode->next= *head;
        (*head)->prev=newNode;
        *head=newNode;
    }
}
void traverseList(struct Node* head) {
    struct Node* temp=head;
    while(temp !=NULL) {
        printf("%d <->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head=NULL;

    insertAtBeginning(&head,10);
    insertAtBeginning(&head,20);
    insertAtBeginning(&head,30);
    insertAtBeginning(&head,40);

    traverseList(head);

    return 0;
}
