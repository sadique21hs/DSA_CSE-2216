#include<stdio.h>
void sort(int a[], int n)
{
    int i, j,temp;
    for (i = 0; i < n - 1; i++)
    {
        temp = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("Sorted element: ");
    for(i=0; i<n; i++)
    {
        printf(" %d ",a[i]);
    }
}


int bSearch(int a[], int n, int item)
{
    int low=0;
    int high=n-1;

    while( low<=high)
    {
        int mid=(low+high)/2;

        if(a[mid]==item)
        {
            return 1;
        }
        else if(a[mid]>=item)
        {
            return 1;
        }
        else if(a[mid]<=item)
        {
            return 1;
        }
    }
}





int main()
{
    int arr[100],n,low,high,item;
    printf("Enter the array size: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        arr[i]=rand()%100+1;
    }
    sort(arr,5);
    printf("\n");
    printf("Enter element for search: ");
    scanf("%d",&item);
    if(bSearch(arr,n,item)==1)
    {
        printf("Found");

    }
    else
    {
        printf("Not found");
    }

}
