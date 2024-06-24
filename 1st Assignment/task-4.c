#include <stdio.h>

int main()
{

    int arr[100],n;
    int count = 0;
    printf("Enter the array length: ");
    scanf("%d",&n);


    for (int i = 0; i < n; i++)
    {
        arr[i]=rand()%100+1;
    }



    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }

        printf("total number of duplicate: %d\n", count);

        return 0;
    }
}
