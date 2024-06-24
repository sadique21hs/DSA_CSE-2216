#include <stdio.h>

int main()
{
    int n,arr1[100],arr2[100];

    printf("Enter the array length: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element of 1st array: ");
        scanf("%d",&arr1[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element of 2nd array: ");
        scanf("%d",&arr2[i]);
    }


    int merged[2 * n];

    int i = 0, j = 0, k = 0;
    while (i < n && j < n)
    {
        if (arr1[i] >= arr2[j])
        {
            merged[k++] = arr1[i++];
        }
        else
        {
            merged[k++] = arr2[j++];
        }
    }


    while (i < n)
    {
        merged[k++] = arr1[i++];
    }
    while (j < n)
    {
        merged[k++] = arr2[j++];
    }


    printf("Merge array in descending order: ");
    for (i = 0; i < 2 * n; i++)
    {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
