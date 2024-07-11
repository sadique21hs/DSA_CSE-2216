int main()
{
    int arr[100],n,i,search,result ;
    printf("Enter the array size: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter the element: ");
        scanf("%d",&arr[i]);
    }for (i=0; i<n-1; i++)
    {
        int  flag=1; //for better
        for( j=0; j<n-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }

        }
        if(flag==0)
        {
            break;
        }


    }
    printf("\nAfter sort:\n");

    for( i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
