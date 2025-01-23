#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=newNode;
    return newNode;
}
void insertEnd(struct Node** head, int data) {
    struct Node* newNode=createNode(data);

    if(*head==NULL)
    {
        *head=newNode;
    } else {
        struct Node* temp= *head;
        while (temp->next != *head) {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next= *head;
    }
}

int search(struct Node* head, int key) {
    if(head==NULL)
    {
        return 0;
    }
    struct Node* temp=head;
    do{
        if(temp->data==key) {
            return 1;
        }
        temp=temp->next;
    } while(temp !=head);
    return 0;
}

int main(){
    struct Node* head=NULL;

    insertEnd(&head,10);
    insertEnd(&head,20);
    insertEnd(&head,30);
    insertEnd(&head,40);

    int key= 20;
    if (search(head,key)) {
        printf("Element %d found in the list.\n",key);
    } else {
        printf("Element %d not found in the list.\n",key);
    }
    return 0;
}
