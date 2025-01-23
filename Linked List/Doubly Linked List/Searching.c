#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* createNode(int value) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
struct Node* search(struct Node* head, int key) {
    struct Node* temp=head;
    while(temp !=NULL) {
        if(temp->data==key) {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}
void printList(struct Node* head) {
    struct Node* temp=head;
    while(temp !=NULL) {
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head=createNode(10);
    struct Node* second=createNode(20);
    struct Node* third=createNode(30);

    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;

    printf("Doubly Linked List: ");
    printList(head);

    int searchKey=20;
    struct Node* foundNode=search(head,searchKey);

    if(foundNode !=NULL){
        printf("Found the value %d in the list.\n",foundNode->data);
    }
    else{
        printf("Value %d not found in the list.\n",searchKey);
    }

    return 0;
}
