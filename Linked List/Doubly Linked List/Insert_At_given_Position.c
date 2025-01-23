#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
void insertAfter(struct Node* prev_node, int new_data) {
    if(prev_node==NULL)
    {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=new_data;

    new_node->next=prev_node->next;
    prev_node->next=new_node;
    new_node->prev=prev_node;

    if(new_node->next != NULL) {
        new_node->next->prev=new_node;
    }
}

void printList(struct Node* node) {
    while(node != NULL) {
        printf("%d ",node->data);
        node=node->next;
    }
    printf("\n");
}
struct Node* newNode(int data) {
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->next=NULL;
    node->prev=NULL;
    return node;
}

int main() {
    struct Node* head=newNode(10);
    head->next=newNode(20);
    head->next->prev=head;

    head->next->next=newNode(30);
    head->next->next->prev=head->next;

    printf("Original list: \n");
    printList(head);

    insertAfter(head->next,25);

    printf("List after inserting 25 after the second node: \n");
    printList(head);

    return 0;
}
