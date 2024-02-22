#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void bubbleSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size - i - 1; j++) {
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
        }
    }
}

void main() {
    int *array, size;
    printf("Enter size:");
    scanf("%d", &size);
    array = (int *) malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        array[i] = rand();
    printf("Array before swap:\n");
    printArray(array, size);
    bubbleSort(array, size);
    printf("Array after swap:\n");
    printArray(array, size);
}
