#include<stdio.h>
struct list
{
    int data;
    struct list *next;
};

typedef struct  list node;
int main()
{
    node *head;
    head=malloc(sizeof(node));
    head->data=10;

    node *temp;
    temp=malloc(sizeof(node));
    temp->data=20;

    node *prev;
    prev=malloc(sizeof(node));
    prev->data=30;

    head->next=temp;
    temp->next=prev;
    prev->next=head;


    node *start;
    start=malloc(sizeof(node));
    start=head;


    printf("%d %d %d %d %d",head->data, head->next->data, head->next->next->data,head->next->next->next->data,start->data);



}
