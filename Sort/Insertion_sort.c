
#include<stdio.h>
void main()
{
    int i, arr[100], n,temp,j,key;

    printf("Enter the number " );
    scanf("%d",&n);
    for( i=0; i<n; i++)
    {
        arr[i]=rand()%100+1;
        printf("%d ",arr[i]);

    }
printf("\n");
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

    }
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

}






