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

    int freq[n];


    for (int i = 0; i < n; i++)
    {
        freq[i] = 0;
    }


    for (int i = 0; i < n; i++)
    {

        freq[arr[i]]++;
    }

    printf("Frequency in the array:\n");
    for (int i = 0; i < n; i++)
    {
        if (freq[i] > 0)
        {
            printf("%d occurs %d times\n", i, freq[i]);
        }
    }

    return 0;
}

