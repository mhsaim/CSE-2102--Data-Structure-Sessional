#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if(!newNode)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void insertAfterPosition(struct Node** head, int position, int data) {
    struct Node* newNode=createNode(data);
    if(*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp= *head;
    for(int i=0; i<position;i++) {
        if (temp==NULL)
        {
            printf("Position out of bounds.\n");
            free(newNode);
            return;
        }
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    printf("Node with data %d inserted after position %d.\n", data, position);
}
void displayList(struct Node* head) {
    struct Node* temp=head;
    while(temp !=NULL) {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    struct Node* head=NULL;
    struct Node* second=NULL;
    struct Node* third=NULL;
    head=createNode(1);
    second=createNode(2);
    third=createNode(3);
    head->next=second;
    second->next=third;

    printf("Original list:\n");
    displayList(head);

    int position=1;
    int newData=99;
    insertAfterPosition(&head, position, newData);

    printf("List after insertion:\n");
    displayList(head);

    return 0;
}
