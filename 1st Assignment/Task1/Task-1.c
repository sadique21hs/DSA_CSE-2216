#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILE_NAME "in.txt"
#define NUM_COUNT 500
#define MAX_VALUE 999

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void generate_numbers() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    for (int i = 0; i < NUM_COUNT; i++) {
        int num = rand() % (MAX_VALUE + 1);
        fprintf(file, "%d\n", num);
    }

    fclose(file);
}

void read_numbers(int arr[], int n) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
}

void write_numbers(const int arr[], int n) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
}

int main() {
    generate_numbers();

    int numbers[NUM_COUNT];
    read_numbers(numbers, NUM_COUNT);

    bubble_sort(numbers, NUM_COUNT);

    write_numbers(numbers, NUM_COUNT);

    printf("Numbers sorted and written to %s\n", FILE_NAME);
    return 0;
}
