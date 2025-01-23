#include<stdio.h>
#define MAX 5

int queue[MAX];
int front= -1, rear= -1;

void enqueue(int value) {
    if (rear==MAX-1) {
        printf("Queue is full!\n");
    } else {
        if (front== -1) {
            front=0;
        }
        rear++;
        queue[rear]=value;
        printf("%d enqueued\n",value);
    }
}

void dequeue() {
    if (front== -1 || front>rear) {
        printf("Queue is empty!\n");
    } else {
        printf("%d dequeued\n",queue[front]);
        front++;
    }
}
void peek() {
    if (front== -1 || front>rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    peek();

    dequeue();
    dequeue();

    peek();

    return 0;
}
