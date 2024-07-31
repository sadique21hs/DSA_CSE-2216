
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *top;
    struct Node *bottom;
} ;
typedef struct List Node;

  Node  *createNode(int data)
{
    Node  *newNode;
    newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = newNode->top = newNode->bottom = NULL;
    return newNode;
}
