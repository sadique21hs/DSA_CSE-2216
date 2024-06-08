#include<stdio.h>
int main()
{
    int arr[100],n,search, found,item;
    printf("Enter the array size: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        printf("Enter the element: ");
        scanf("%d",&arr[i]);
    }
    printf("Enter element for search: ");
    scanf("%d",&search);
    for(int i=0; i<=n; i++)
    {
        if(arr[i]==search)
        {
            found=1;
            item=arr[i];
            break;

        }
    }

    if(found==1)
    {
        printf("We found, Here is the element: %d",item);
    }
    else
    {
        printf("not found");
    }
return 0;

}
