#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
};
typedef struct list node;

node *start = NULL;

void display()
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
    int choice, item;

    do
    {
        menu();
        printf("Enter Choice: ");
        scanf("%d", &choice);
        display();
    }
      }
