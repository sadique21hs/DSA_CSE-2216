#include <stdio.h>

int main() {

    int arr1[100],arr2[100],n;
    printf("Enter the array length: ");
    scanf("%d",&n);


    for (int i = 0; i < n; i++){
       arr1[i]=rand()%100+1;
    }

    for (int i = 0; i < n; i++) {
        arr2[i] = arr1[i];
    }


    printf("(arr1): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");


    printf("(arr2): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}
