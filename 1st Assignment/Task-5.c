#include <stdio.h>

int main()
{

    int arr[100],n;

    printf("Enter the array length: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element of array: ");
        scanf("%d",&arr[i]);
    }

    int is_unique;


    printf("unique element: ");
    for (int i = 0; i < n; i++)
    {
        is_unique = 1;

        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                is_unique = 0;
                break;
            }
        }


        if (is_unique)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    return 0;
}

