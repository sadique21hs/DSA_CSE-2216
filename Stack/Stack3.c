//Problem E:

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define STACK_SIZE 100


char stack[STACK_SIZE];
int top = -1;

void push(char ch) {
    if (top < STACK_SIZE - 1) {
        stack[++top] = ch;
    }
}

void pop_and_display() {
    if (top >= 0) {
        printf("%c", stack[top--]);
    }
}

int main() {
    char input[STACK_SIZE];

    printf("Enter a string: ");
    fgets(input, STACK_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0';  

    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            
            push(input[i]);
        } else if (isdigit(input[i])) {
            
            pop_and_display();
        }
        
    }

    return 0;
}

