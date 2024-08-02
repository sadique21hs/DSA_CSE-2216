#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List
{
    int data;
    struct List *prev;
    struct List *next;
};
typedef struct List Node;

Node* dummy;

Node* createNode(int data)
{
    Node *newNode;
    newNode =malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void initializeList()
{
    dummy = createNode(0);
    dummy->next = dummy;
    dummy->prev = dummy;
}

void insertAfter(Node* y, int x)
{
    Node *newNode;
    newNode = createNode(x);
    newNode->next = y->next;
    y->next->prev = newNode;
    y->next = newNode;
    newNode->prev = y;
}

Node* search(int key)
{
    Node* current = dummy->next;
    while (current != dummy)
    {
        if (current->data == key)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void ins(int y, int x)
{
    Node *node_Y;
    node_Y = search(y);
    if (node_Y != NULL)
    {
        insertAfter(node_Y, x);
        printf("INSERT after %d.\n", y);
    }
    else
    {
        insertAfter(dummy, x);
        printf("INSERT after dummy node.\n");
    }
}

void del(int x)
{
    Node* nodeX = search(x);
    if (nodeX != NULL)
    {
        nodeX->prev->next = nodeX->next;
        nodeX->next->prev = nodeX->prev;
        free(nodeX);
        printf("Node with key value %d is DELETED.\n", x);
    }
    else
    {
        printf("DELETE not possible.\n");
    }
}

void sch(int key)
{
    Node* node = search(key);
    if (node != NULL)
    {
        printf("Node with key value %d is FOUND.\n", key);
    }
    else
    {
        printf("Not FOUND.\n");
    }
}

void shw()
{
    Node* current = dummy->next;
    while (current != dummy)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    char command[4];
    int key1, key2;

    initializeList();

    while (1)
    {
        scanf("%s", command);
        if (strcmp(command, "ins") == 0)
        {
            scanf("%d %d", &key1, &key2);
            ins(key1, key2);
        }
        else if (strcmp(command, "del") == 0)
        {
            scanf("%d", &key1);
            del(key1);
        }
        else if (strcmp(command, "sch") == 0)
        {
            scanf("%d", &key1);
            sch(key1);
        }
        else if (strcmp(command, "shw") == 0)
        {
            shw();
        }
        else if (strcmp(command, "ext") == 0)
        {
            break;
        }
        else
        {
            printf("Invalid command.\n");
        }
    }

    return 0;
}

