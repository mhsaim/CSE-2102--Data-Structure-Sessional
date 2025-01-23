#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if(*head == NULL) {
        newNode->next=newNode;
        *head=newNode;
    }else{
        struct Node* temp= *head;
        while temp->next != *head) {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next= *head;
        *head=newNode;
    }
}
void printList(struct Node* head) {
    if(head==NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do{
        printf("%d -> ",temp->data);
        temp =temp->next;
    }while (temp !=head);
    printf("(head)\n");
}
int main(){
    struct Node* head = NULL;
    insertAtBeginning(&head,10);
    insertAtBeginning(&head,20);
    insertAtBeginning(&head,30);

    printf("Circular Linked List: ");
    printList(head);

    return 0;
}
