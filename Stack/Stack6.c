//Problem B:
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

void insertAtBottom(Stack *s, int item) {
    if (isEmpty(s)) {
        push(s, item);
    } else {
        int topElement = pop(s);
        insertAtBottom(s, item);
        push(s, topElement);
    }
}

void reverseStack(Stack *s) {
    if (!isEmpty(s)) {
        int topElement = pop(s);
        reverseStack(s);
        insertAtBottom(s, topElement);
    }
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
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    printf("Original Stack:\n");
    display(&stack);

    
    reverseStack(&stack);

    printf("Reversed Stack:\n");
    display(&stack);

    return 0;
}

