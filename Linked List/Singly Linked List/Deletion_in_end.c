#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if(!newNode)
    {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void deleteLastNode(struct Node** head) {
    if(*head==NULL) {
        printf("List is already empty.\n");
        return;
    }

    struct Node* temp = *head;
    if(temp->next==NULL) {
        free(temp);
        *head=NULL;
        printf("Last node deleted. List is now empty.\n");
        return;
    }
    while(temp->next->next !=NULL) {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;

    printf("Last node deleted successfully.\n");
}
void printList(struct Node* head) {
    struct Node* temp=head;
    while(temp !=NULL) {
        printf("%d -> ",temp->data);
        temp =temp->next;
    }
    printf("NULL\n");
}
int main(){
    struct Node* head=NULL;

    head=createNode(10);
    head->next=createNode(20);
    head->next->next=createNode(30);

    printf("Initial list: ");
    printList(head);

    deleteLastNode(&head);

    printf("After deleting the last node: ");
    printList(head);

    deleteLastNode(&head);

    printf("After deleting another node: ");
    printList(head);

    deleteLastNode(&head);

    printf("Final list: ");
    printList(head);

    return 0;
}
