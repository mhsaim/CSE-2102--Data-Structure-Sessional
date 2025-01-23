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
void traverse(struct Node* head) {
    if(head==NULL) {
        printf("The circular linked list is empty.\n");
        return;
    }
    struct Node* temp=head;
    printf("Circular Linked List: ");
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp !=head);
    printf("\n");
}
struct Node* create(){
    struct Node* head=createNode(1);
    struct Node* second=createNode(2);
    struct Node* third=createNode(3);

    head->next=second;
    second->next=third;
    third->next=head;

    return head;
}
int main(){
    struct Node* head=create();
    traverse(head);

    return 0;
}
