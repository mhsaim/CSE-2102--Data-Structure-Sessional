#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
void reverse(struct Node** head) {
    struct Node* temp=NULL;
    struct Node* current=*head;

    while(current !=NULL) {
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }

    if(temp !=NULL)
    {
        *head=temp->prev;
    }
}
void printList(struct Node* node) {
    while(node !=NULL) {
        printf("%d ",node->data);
        node=node->next;
    }
    printf("\n");
}
void connect(struct Node** head, int new_data) {
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    struct Node* last= *head;
    new_node->data=new_data;
    new_node->next=NULL;

    if(*head==NULL)
    {
        new_node->prev=NULL;
        *head=new_node;
        return;
    }

    while(last->next !=NULL) {
        last=last->next;
    }

    last->next=new_node;
    new_node->prev=last;
}
int main(){
    struct Node* head=NULL;

    connect(&head,10);
    connect(&head,20);
    connect(&head,30);
    connect(&head,40);

    printf("Original List: ");
    printList(head);

    reverse(&head);

    printf("Reversed List: ");
    printList(head);

    return 0;
}
