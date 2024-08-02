#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of a node in the linked list
typedef struct Node {
    int count;
    char pixel;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int count, char pixel) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->count = count;
    newNode->pixel = pixel;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertNode(Node** head, int count, char pixel) {
    Node* newNode = createNode(count, pixel);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list representing a row
void printRow(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        for (int i = 0; i < temp->count; i++) {
            printf("%c", temp->pixel);
        }
        temp = temp->next;
    }
}

// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to free the linked list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int rows, cols;
    printf("Enter the rows and collum: ");
    scanf("%d %d", &rows, &cols);


    Node* image[rows];
    memset(image, 0, sizeof(image));


    char line[cols + 1];
    for (int i = 0; i < rows; i++) {
        scanf("%s", line);
        int j = 0;
        while (j < cols) {
            char pixel = line[j];
            int count = 1;
            while (j + 1 < cols && line[j + 1] == pixel) {
                j++;
                count++;
            }
            insertNode(&image[i], count, pixel);
            j++;
        }
    }

    for (int i = 0; i < rows; i++) {
        Node* reversedRow = reverseList(image[i]);
        printRow(reversedRow);
        printf("\n");
        freeList(reversedRow);
    }

    for (int i = 0; i < rows; i++) {
        freeList(image[i]);
    }

    return 0;
}
