#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};
typedef struct Node node;
node *head=NULL;

void first_element(int data)
{
    node *newnode=malloc(sizeof(node));
    newnode->data=data;
    newnode->link=NULL;
    head=newnode;

}
void insert_in_begining(int data)
{
    node *newnode=malloc(sizeof(node));
    newnode->data=data;
    newnode->link=head;
    head=newnode;
}

void traversal()
{
    node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
}

int main()
{
    first_element(7);
    insert_in_begining(5);
    insert_in_begining(4);
    insert_in_begining(3);
    traversal();

    return 0;
}
