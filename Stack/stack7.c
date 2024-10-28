//Problem A:
#include <stdio.h>
#include <stdlib.h>


#define MAX_CARDS 52


typedef struct {
    int items[MAX_CARDS];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->rear < q->front;
}

void enqueue(Queue *q, int value) {
    q->items[++q->rear] = value;
}

int dequeue(Queue *q) {
    return q->items[q->front++];
}

int front(Queue *q) {
    return q->items[q->front];
}


void simulateCardGame(int n) {
    Queue deck;
    initQueue(&deck);

    
    for (int i = 1; i <= n; i++) {
        enqueue(&deck, i);
    }

    printf("Discarded cards: ");
    int first = 1;

    
    while (deck.rear > deck.front) { 
        if (!first) printf(", ");
        first = 0;

        
        printf("%d", dequeue(&deck));

        
        int topCard = dequeue(&deck);
        enqueue(&deck, topCard);
    }

    printf("\nRemaining card: %d\n", front(&deck));
}


int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        simulateCardGame(n);
    }
    return 0;
}
