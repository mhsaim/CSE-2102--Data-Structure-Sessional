#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX-1) {
        printf("Stack Overflow\n");
    } else {
        stack[top++]=value;
        printf("Pushed %d\n", value);
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}


int isEmpty() {
    return top == -1;
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);

    printf("Top element is %d\n", peek());
    printf("Popped element is %d\n", pop());
    printf("Top element after pop is %d\n", peek());

    return 0;
}
