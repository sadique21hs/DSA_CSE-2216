#include <stdio.h>
#include <stdlib.h>
struct list
{
    int data;
    struct list *next;
};
typedef struct list node;


void display(node *start)
{
    node *temp = start;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main()
{
    node *start = NULL;
    node *temp;
    node *prev = NULL;
    int ans, data;

    printf("Do you want to add data (1/0): ");
    scanf("%d", &ans);

    while (ans == 1)
    {
        temp = malloc(sizeof(node));
        printf("Enter data: ");
        scanf("%d", &data);
        temp->data = data;
        temp->next = NULL;

        if (start == NULL)
        {
            start = temp;
        }
        else
        {
            prev->next = temp;
        }

        prev = temp;
        printf("Do you want to add more data (1/0): ");
        scanf("%d", &ans);
    }

    printf("Displaying data: ");
    display(start);
    printf("\n");

    printf("Displaying data in reverse order: ");
    reverseDisplay(start);
    printf("\n");

    printf("Maximum value: %d\n", findMax(start));
    printf("\n");
    printf("Minimum value: %d\n", findMin(start));
    printf("\n");
    printf("Sum of all elements: %d\n", findSum(start));


    return 0;
}
