#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if(!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
int search(struct Node* head, int key) {
    struct Node* current=head;
    while(current !=NULL) {
        if(current->data==key) {
            return 1;
        }
        current=current->next;
    }
    return 0;
}
void printList(struct Node* head) {
    struct Node* temp=head;
    while(temp !=NULL) {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head=createNode(10);
    head->next=createNode(20);
    head->next->next=createNode(30);
    head->next->next->next=createNode(40);

    printList(head);

    int key=30;
    if(search(head,key)) {
        printf("Element %d found in the list.\n",key);
    }else{
        printf("Element %d not found in the list.\n",key);
    }

    key=50;
    if(search(head,key)) {
        printf("Element %d found in the list.\n",key);
    }else{
        printf("Element %d not found in the list.\n",key);
    }

    return 0;
}
