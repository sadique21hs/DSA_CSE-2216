#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char alphabet;
    int frequency;
    struct Node* next;
};
struct Node* createList();
void updateFrequency(struct Node* head, const char* str);
void printList(struct Node* head);
int main()
{
    char input[101];
    struct Node* head = createList();
    printf("Enter a string: ");
    scanf("%100s", input);
    updateFrequency(head, input);
    printList(head);
    struct Node* current = head;
    struct Node* next;
    while (current != NULL)
    {
        next = current->next;
        delete(current);
        current = next;
    }
    return 0;
}
struct Node* createList()
{
    struct Node* head = NULL;
    struct Node* current = NULL;
    for (char c = 'a'; c <= 'z'; c++)
    {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->alphabet = c;
        new_node->frequency = 0;
        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
            current = head;
        }
        else
        {
            current->next = new_node;
            current = current->next;
        }
    }
    return head;
}
void updateFrequency(struct Node* head, const char* str)
{
    struct Node* current;
    for (int i = 0; i < strlen(str); i++)
    {
        current = head;
        while (current != NULL)
        {
            if (current->alphabet == str[i])
            {
                current->frequency++;
                break;
            }
            current = current->next;
        }
    }
}
void printList(struct Node* head)
{
    struct Node* current = head;
    while (current != NULL)
    {
        printf("%c: %d\n", current->alphabet, current->frequency);
        current = current->next;
    }
}
