#include<stdio.h>
int main()
{
    int arr[100],n,i,search;
    printf("Enter the array size: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter the element: ");
        scanf("%d",&arr[i]);
    }
    printf("Before Bubble sort.\n");

    for( i=0; i<n; i++)
    {
        printf("%d ",arr[i]);

    }
    printf("\nEnter the element for search: ");
    scanf("%d",&search);
    int flag=0;
    for(i=0; i<n; i++)
    {
        if(arr[i]==search)
        {
            printf("\nThe data is on the index no: %d",i);
            flag=1;
            break;
        }

    }if (flag==0){
    printf("\nData not found");
    }
    
  
}
