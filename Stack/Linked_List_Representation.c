#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void initStack(struct Stack* stack) {
    stack->top =NULL;
}

void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    int data = stack->top->data;
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

int peek(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->top->data;
}
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    printf("Top element is %d\n", peek(&stack));
    printf("Popped element is %d\n", pop(&stack));
    printf("Top element is %d\n", peek(&stack));

    return 0;
}
