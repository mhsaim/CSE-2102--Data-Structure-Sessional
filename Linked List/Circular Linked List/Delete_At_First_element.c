#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void deleteFirst(struct Node** head) {
    if(*head==NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp= *head;
    if((*head)->next== *head) {
        free(*head);
        *head = NULL;
    }else{
        struct Node* last= *head;
        while(last->next != *head) {
            last=last->next;
        }
        *head=(*head)->next;
        last->next= *head;
        free(temp);
    }
    printf("First element deleted successfully.\n");
}

void printList(struct Node* head) {
    if(head==NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp=head;
    do{
        printf("%d -> ",temp->data);
        temp=temp->next;
    }while(temp !=head);
    printf("(head)\n");
}
void insertEnd(struct Node** head, int data) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    struct Node* last= *head;

    newNode->data=data;
    newNode->next= *head;

    if(*head==NULL) {
        *head=newNode;
        newNode->next= *head;
    }else{
        while(last->next != *head) {
            last=last->next;
        }
        last->next=newNode;
    }
}

int main(){
    struct Node* head=NULL;

    insertEnd(&head,10);
    insertEnd(&head,20);
    insertEnd(&head,30);

    printf("Original Circular Linked List:\n");
    printList(head);

    deleteFirst(&head);

    printf("Circular Linked List after deleting the first element:\n");
    printList(head);

    return 0;
}
