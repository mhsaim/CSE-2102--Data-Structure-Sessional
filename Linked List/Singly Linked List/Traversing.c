#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void traverseLinkedList(struct Node* head) {
    struct Node* current=head;
    while(current !=NULL) {
        printf("%d -> ",current->data);
        current =current->next;
    }
    printf("NULL\n");
}
struct Node* createNode(int data) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

int main(){
    struct Node* head=createNode(1);
    struct Node* second=createNode(2);
    struct Node* third=createNode(3);

    head->next=second;
    second->next=third;

    printf("Linked List: ");
    traverseLinkedList(head);

    free(head);
    free(second);
    free(third);

    return 0;
}
