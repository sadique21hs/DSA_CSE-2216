#include<stdio.h>
struct list
{
    int data;
    list *next;
};
typedef struct list node;
node *start;


void menu()
{
    int data;
    list *next;
    printf("\n1.Insert: \n2.Exit : \n");
}


void inseretion(int item)
{
    node *temp;
    node *temp1;
    if (start==NULL)
    {
        start=new node();
        start->data=item;
        start->next=NULL;
    }
    else if(item<=start->data)
    {
        temp=new node();
        temp->data=item;
        temp->next=start;
        start=temp;

    }
    else
    {
        temp=start;
        while(temp->next!=NULL && temp->next->data<=item)
        {
            temp=temp->next;
        }

        temp1=new node();
        temp1->data=item;
        temp1->next=temp->next;
        temp->next=temp1;


    }

}



int main()
{
    int choice,i=1,item;
    start=NULL;
    do
    {
        menu();
        printf("Enter Choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter item for insert: ");
            scanf("%d",&item);
            inseretion(item);
            display();


        }

        else
        {
            i=0;
        }

    }
    while(i);
}
