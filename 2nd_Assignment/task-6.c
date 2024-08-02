#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
typedef struct Node
{
    int coeff;    // Coefficient of the term
    int exp;      // Exponent of the term
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int coeff, int exp)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into a polynomial in sorted order (by exponent)
void insertNode(Node** head, int coeff, int exp)
{
    Node* newNode = createNode(coeff, exp);
    if (*head == NULL || (*head)->exp < exp)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        Node* current = *head;
        while (current->next != NULL && current->next->exp >= exp)
        {
            current = current->next;
        }
        if (current->exp == exp)
        {
            current->coeff += coeff; // Combine coefficients if exponent matches
            free(newNode);
        }
        else
        {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}

// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2)
{
    Node* result = NULL;
    Node* temp = NULL;

    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exp > poly2->exp)
        {
            insertNode(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        }
        else if (poly1->exp < poly2->exp)
        {
            insertNode(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
        else
        {
            int coeffSum = poly1->coeff + poly2->coeff;
            if (coeffSum != 0)
            {
                insertNode(&result, coeffSum, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL)
    {
        insertNode(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL)
    {
        insertNode(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

// Function to print a polynomial
void printPolynomial(Node* head)
{
    if (head == NULL)
    {
        printf("0");
        return;
    }
    Node* current = head;
    while (current != NULL)
    {
        if (current->coeff != 0)
        {
            if (current != head && current->coeff > 0)
            {
                printf(" + ");
            }
            if (current->coeff < 0)
            {
                printf(" - ");
                printf("%d", -current->coeff);
            }
            else
            {
                printf("%d", current->coeff);
            }
            if (current->exp != 0)
            {
                printf("x^%d", current->exp);
            }
        }
        current = current->next;
    }
    printf("\n");
}

// Function to free the linked list
void freeList(Node* head)
{
    Node* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* result = NULL;

    int n,n2, coeff, exp;

    printf("Enter number of 1st polynomial: ");
    scanf("%d", &n);
    printf("Enter the base and power.\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &coeff, &exp);
        insertNode(&poly1, coeff, exp);
    }

    printf("Enter number 2nd polynomial: ");
    scanf("%d", &n2);
    printf("Enter the base and power.\n");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d %d", &coeff, &exp);
        insertNode(&poly2, coeff, exp);
    }

    result = addPolynomials(poly1, poly2);

    printf("polynomial_1: ");
    printPolynomial(poly1);

    printf("polynomial_2: ");
    printPolynomial(poly2);

    printf("Sum of polynomials: ");
    printPolynomial(result);

    // Free allocated memory
    freeList(poly1);
    freeList(poly2);
    freeList(result);

    return 0;
}
