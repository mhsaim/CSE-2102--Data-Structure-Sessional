#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode=createNode(data);

    if(*head==NULL)
    {
        *head=newNode;
        newNode->next= *head;
    }else{
        struct Node* temp= *head;
        while(temp->next != *head) {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next= *head;
    }
}
void display(struct Node* head) {
    if(head==NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp=head;
    do{
        printf("%d -> ",temp->data);
        temp=temp->next;
    } while(temp !=head);
    printf("(head)\n");
}

int main(){
    struct Node* head=NULL;

    insertAtEnd(&head,10);
    insertAtEnd(&head,20);
    insertAtEnd(&head,30);

    printf("Circular Linked List:\n");
    display(head);

    return 0;
}
