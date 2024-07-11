#include<stdio.h>

int main()
{
    int i,j,arr[100],n,temp;
    printf("Enter the array size: ");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        printf("Enter the element of array: ");
        scanf("%d",&arr[i]);
    }
    printf("Before Bubble sort.\n");

    for( i=0; i<n; i++)
    {
        printf("%d ",arr[i]);

    }
    for (i=0; i<n-1; i++)
    {
     
        for( j=0; j<n-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }

        }
        


    }
}
