#include <stdio.h>
#include <limits.h>

int main() {
    int arr[100],n;

    printf("Enter the array length: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element of array: ");
        scanf("%d",&arr[i]);
    }
    int largest = INT_MIN, second_largest = INT_MIN;


    for (int i = 0; i < n; i++) {

        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] != largest) {

        }
    }


    if (second_largest == INT_MIN) {
        printf("has less than 2 distinct elements");
    } else {

        printf("second largest element : %d\n", second_largest);
    }

    return 0;
}

