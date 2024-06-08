#include <stdio.h>
void main()
{

    int i, j, temp, n, arr[100];
    printf("Enter the n: \n");
    scanf("%d", &n);


    for (i = 0; i < n ; i++)
    {
        arr[i]=rand()%100+1;
    }

    printf("Before sort:\n");

    for (i = 0; i < n ; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");



    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    printf("After sort:\n");
    for(i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}


