#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void deleteNode(struct Node** head_ref, int position) {
    if(*head_ref==NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp= *head_ref;

    if(position==0)
    {
        *head_ref=temp->next;
        free(temp);
        return;
    }
    for(int i=0; temp!=NULL && i<position-1;i++)
    {
        temp=temp->next;
    }
    if(temp==NULL || temp->next==NULL) {
        printf("Position is out of range.\n");
        return;
    }
    struct Node* next=temp->next->next;

    free(temp->next);
    temp->next=next;
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=new_data;
    new_node->next= *head_ref;
    *head_ref=new_node;
}
void printList(struct Node* node) {
    while(node !=NULL) {
        printf("%d -> ",node->data);
        node=node->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head=NULL;
    push(&head,50);
    push(&head,40);
    push(&head,30);
    push(&head,20);
    push(&head,10);

    printf("Original Linked List:\n");
    printList(head);

    deleteNode(&head,2);

    printf("Linked List after deletion:\n");
    printList(head);

    return 0;
}
