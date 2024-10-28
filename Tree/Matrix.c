//Problem G:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100


typedef struct Node {
    char type;
    int row;
    int col;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void initializeQueue(Queue* q) {
    q->front = q->rear = NULL;
}

int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, char type, int row, int col) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type;
    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

void dequeueAll(Queue* q, const char* title) {
    printf("%s\n", title);
    while (!isQueueEmpty(q)) {
        Node* temp = q->front;
        printf("%c %d %d\n", temp->type, temp->row, temp->col);
        q->front = q->front->next;

        if (q->front == NULL) {
            q->rear = NULL;
        }
        free(temp);
    }
}

void processBoard(int rows, int cols, char board[MAX_ROWS][MAX_COLS]) {
    Queue blades, vampires;
    initializeQueue(&blades);
    initializeQueue(&vampires);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char cell = board[i][j];
            if (cell == 'A' || cell == 'B' || cell == 'C') {
                enqueue(&blades, cell, i, j);
            } else if (cell == 'M' || cell == 'N' || cell == 'O') {
                enqueue(&vampires, cell, i, j);
            }
        }
    }

    dequeueAll(&blades, "Blade information:");
    dequeueAll(&vampires, "Vampire information:");
}

int main() {
    int rows, cols;
    char board[MAX_ROWS][MAX_COLS];

    scanf("%d %d", &rows, &cols);
    getchar(); 

    
    for (int i = 0; i < rows; i++) {
        fgets(board[i], MAX_COLS, stdin);
    }

    
    processBoard(rows, cols, board);

    return 0;
}

