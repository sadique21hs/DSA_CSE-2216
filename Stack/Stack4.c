//Problem D:
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} Queue;

typedef struct {
    Queue queue1;
    Queue queue2;
} Stack;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(Queue *q) {
    return (q->front == -1);
}

int isQueueFull(Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}

void enqueue(Queue *q, int value) {
    if (isQueueFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = 0;
    }
    q->items[++q->rear] = value;
}

int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

void initStack(Stack *s) {
    initQueue(&s->queue1);
    initQueue(&s->queue2);
}

void push(Stack *s, int value) {
    enqueue(&s->queue1, value);
    printf("%d pushed to stack.\n", value);
}

int pop(Stack *s) {
    if (isQueueEmpty(&s->queue1)) {
        printf("Stack is empty.\n");
        return -1;
    }

    
    while (s->queue1.front != s->queue1.rear) {
        enqueue(&s->queue2, dequeue(&s->queue1));
    }

    
    int poppedValue = dequeue(&s->queue1);
    printf("%d popped from stack.\n", poppedValue);

    
    Queue temp = s->queue1;
    s->queue1 = s->queue2;
    s->queue2 = temp;

    return poppedValue;
}


void display(Stack *s) {
    if (isQueueEmpty(&s->queue1)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = s->queue1.front; i <= s->queue1.rear; i++) {
        printf("%d ", s->queue1.items[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack);

    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

