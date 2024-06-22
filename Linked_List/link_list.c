#include<stdio.h>
struct list
{
    int data;
    struct list *next;
};

typedef struct  list node;

int main()
{
    node *a, *b, *c;
    int d;
    a= malloc(sizeof(node)); //create a new box(in c++ we used new)
    b= malloc(sizeof(node));
    c= malloc(sizeof(node));
    //d= malloc(sizeof(node));

    a->data=10;
    b->data=20;
    c->data=30;
    d=a;
//d->data=50;

    printf("%d %d %d",a->data,b->data,d);

}
