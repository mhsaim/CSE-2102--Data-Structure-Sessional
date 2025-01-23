#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Node* newNode(int data) {
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data =data;
    temp->next =NULL;
    return temp;
}

void initQueue(struct Queue* q) {
    q->front=NULL;
    q->rear=NULL;
}

int isEmpty(struct Queue* q) {
    return (q->front==NULL);
}
void enqueue(struct Queue* q, int data) {
    struct Node* temp=newNode(data);
    if (isEmpty(q)) {
        q->front=q->rear=temp;
    } else {
        q->rear->next=temp;
        q->rear=temp;
    }
    printf("%d enqueued\n",data);
}
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node* temp=q->front;
    int data=temp->data;
    q->front=q->front->next;

    if (q->front==NULL) {
        q->rear=NULL;
    }
    free(temp);
    printf("%d dequeued\n",data);
    return data;
}
int front(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    dequeue(&q);

    display(&q);

    printf("Front element: %d\n",front(&q));

    return 0;
}
