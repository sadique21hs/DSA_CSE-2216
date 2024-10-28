#include <stdio.h>
#include <string.h>
#define MEMORY_SIZE 8

int memory[MEMORY_SIZE];
int stack_top = -1;
int queue_front = -1, queue_rear = -1;
int current_size = 0;


void push(int x) {
    if (current_size >= MEMORY_SIZE) {
        printf("Discard Push %d - Memory Full\n", x);
        return;
    }
    memory[++stack_top] = x;
    current_size++;
}

void pop() {
    if (stack_top == -1) {
        printf("Discard Pop - Memory Empty\n");
        return;
    }
    stack_top--;
    current_size--;
}

void enqueue(int x) {
    if (current_size >= MEMORY_SIZE) {
        printf("Discard Enqueue %d - Memory Full\n", x);
        return;
    }
    if (queue_front == -1) queue_front = 0;
    queue_rear = (queue_rear + 1) % MEMORY_SIZE;
    memory[queue_rear] = x;
    current_size++;
}


void dequeue() {
    if (queue_front == -1) {
        printf("Discard Dequeue - Memory Empty\n");
        return;
    }
    if (queue_front == queue_rear) { 
        queue_front = queue_rear = -1;
    } else {
        queue_front = (queue_front + 1) % MEMORY_SIZE;
    }
    current_size--;
}


void display_memory() {
    if (current_size == 0) {
        printf("Memory is Empty\n");
    } else {
        printf("Memory status: ");
        if (queue_front != -1) {
            for (int i = queue_front; i != queue_rear; i = (i + 1) % MEMORY_SIZE) {
                printf("%d ", memory[i]);
            }
            printf("%d ", memory[queue_rear]); 
        }
        for (int i = 0; i <= stack_top; i++) {
            printf("%d ", memory[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, x;
    char operation[3];

    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", operation);

        if (strcmp(operation, "E") == 0) {
            scanf("%d", &x);
            enqueue(x);
        } else if (strcmp(operation, "D") == 0) {
            dequeue();
        } else if (strcmp(operation, "P") == 0) {
            scanf("%d", &x);
            push(x);
        } else if (strcmp(operation, "O") == 0) {
            pop();
        }
    }

    display_memory();

    return 0;
}

