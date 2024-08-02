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

void menu()
{
    printf("\n1. Insert\n2. Show all\n3. Search\n4. Delete\n5. Length\n6. Exit\n");
}

void insertion(int item)
{
    node *temp;
    node *temp1;

    if (start == NULL)
    {
        start = (node *)malloc(sizeof(node));
        start->data = item;
        start->next = NULL;
    }
    else if (item <= start->data)
    {
        temp = (node *)malloc(sizeof(node));
        temp->data = item;
        temp->next = start;
        start = temp;
    }
    else
    {
        temp = start;
        while (temp->next != NULL && temp->next->data <= item)
        {
            temp = temp->next;
        }

        temp1 = (node *)malloc(sizeof(node));
        temp1->data = item;
        temp1->next = temp->next;
        temp->next = temp1;
    }
}

void deletion(int item)
{
    node *temp = start, *prev = NULL;

    if (temp != NULL && temp->data == item)
    {
        start = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != item)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Item not found in the list.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int search(int item)
{
    node *temp = start;
    while (temp != NULL)
    {
        if (temp->data == item)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int length()
{
    int count = 0;
    node *temp = start;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    int choice, item;

    do
    {
        menu();
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter item to insert: ");
            scanf("%d", &item);
            insertion(item);
            display();
            break;
        case 2:
            printf("Current list: ");
            display();
            break;
        case 3:
            printf("Enter item to search: ");
            scanf("%d", &item);
            if (search(item))
            {
                printf("Item %d found in the list.\n", item);
            }
            else
            {
                printf("Item %d not found in the list.\n", item);
            }
            break;
        case 4:
            printf("Enter item to delete: ");
            scanf("%d", &item);
            deletion(item);
            display();
            break;
        case 5:
            printf("Current length of the list: %d\n", length());
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}
