//Problem C:
#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100


typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;


void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow.\n");
        return;
    }
    s->items[++s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow.\n");
        return INT_MIN;
    }
    return s->items[s->top--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        return INT_MIN;
    }
    return s->items[s->top];
}


void removeMaxElement(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }

    Stack tempStack;
    initStack(&tempStack);
    int maxElement = INT_MIN;

    
    while (!isEmpty(s)) {
        int current = pop(s);
        if (current > maxElement) {
            maxElement = current;
        }
        push(&tempStack, current);
    }

    int removed = 0;
    while (!isEmpty(&tempStack)) {
        int current = pop(&tempStack);
        if (current == maxElement && !removed) {
            removed = 1;  
        } else {
            push(s, current);
        }
    }

    printf("Maximum element %d has been removed.\n", maxElement);
}


void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack);

    
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 5);
    push(&stack, 30);
    push(&stack, 15);

    printf("Original Stack:\n");
    display(&stack);

    removeMaxElement(&stack);

    printf("Stack after removing maximum element:\n");
    display(&stack);

    return 0;
}

