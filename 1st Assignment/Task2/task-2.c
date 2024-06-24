#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50000
#define RANGE_MIN -250
#define RANGE_MAX 249

void insertion_sort(int arr[], int n);
void input(int **arr, int *size, const char *filename);
int lin_search(int arr[], int size, int key);
void show(int index);

int main() {
    int i;
    FILE *fp;


    srand(time(0));
    fp = fopen("in.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    for (i = 0; i < N; i++) {
        int num = (rand() % (RANGE_MAX - RANGE_MIN + 1)) + RANGE_MIN;
        fprintf(fp, "%d\n", num);
    }
    fclose(fp);


    int size;
    input(&arr, &size, "in.txt");
    insertion_sort(arr, size);

    fp = fopen("out.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        free(arr);
        return EXIT_FAILURE;
    }
    for (i = 0; i < size; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);
    free(arr);

    input(&arr, &size, "out.txt");
    int key;
    printf("Enter the integer to search: ");
    scanf("%d", &key);
    int index = lin_search(arr, size, key);
    show(index);

    free(arr);
    return 0;
}

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void input(int **arr, int *size, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    int capacity = 10;
    *arr = (int *)malloc(capacity * sizeof(int));
    if (*arr == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%d", &((*arr)[count])) != EOF) {
        count++;
        if (count >= capacity) {
            capacity *= 2;
            *arr = (int *)realloc(*arr, capacity * sizeof(int));
            if (*arr == NULL) {
                perror("Memory reallocation failed");
                exit(EXIT_FAILURE);
            }
        }
    }

    *size = count;
    fclose(fp);
}

int lin_search(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

void show(int index) {
    if (index != -1) {
        printf("Element found at index %d.\n", index);
    } else {
        printf("Element not found.\n");
    }
}

