/*L R T B which is max and enter the sum*/
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

void insertLeft(Node* head, int data)
{
    Node* newNode;
    newNode = createNode(data);
    newNode->left = head->left;
    head->left = newNode;
}




int main()
{
    int n, i, x;
    char command[3];


    Node* head = createNode(0);

    printf("Enter the Value of n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the Value of command(L/R/U/D) and x:  ");
        scanf("%s %d", command, &x);

        if (strcmp(command, "L") == 0)
        {
            insertLeft(head, x);
        }
        else if (strcmp(command, "R") == 0)
        {
            insertRight(head, x);
        }
        else if (strcmp(command, "T") == 0)
        {
            insertTop(head, x);
        }
        else if (strcmp(command, "B") == 0)
        {
            insertBottom(head, x);
        }
    }


    int leftSum = calculateSum(head, 'L');

    int rightSum = calculateSum(head, 'R');

    int topSum = calculateSum(head, 'T');

    int bottomSum = calculateSum(head, 'B');


    int maxSum = leftSum;
    char* maxList = "Left Link List";

    if (rightSum > maxSum)
    {
        maxSum = rightSum;
        maxList = "Right Link List";
    }
    if (topSum > maxSum)
    {
        maxSum = topSum;
        maxList = "Top Link List";
    }
    if (bottomSum > maxSum)
    {
        maxSum = bottomSum;
        maxList = "Bottom Link List";
    }


    printf("%s Has Maximum Sum %d\n", maxList, maxSum);



    return 0;
}
