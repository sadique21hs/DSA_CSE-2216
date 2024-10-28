#include <stdio.h>
#define max_stack 10  // Define the maximum size of the stack

int stack[max_stack];  // Array to hold the stack elements
int top = -1;          // Initialize top to -1, indicating an empty stack

// Function to push an element onto the stack
void push(int x) {
    if (top == max_stack - 1) {
        printf("Overflow\n");
    } else {
        top++;
        stack[top] = x;
        printf("%d pushed to stack\n", x);
    }
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Underflow\n");
        return -1;
    } else {
        int popped_value = stack[top];
        top--;
        printf("%d popped from stack\n", popped_value);
        return popped_value;
    }
}

// Function to display all elements in the stack
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Main function to test stack operations
int main() {
    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();

    return 0;
}
