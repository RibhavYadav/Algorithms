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

void selectionSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex])
                minIndex = j;
        }
        swap(&array[i], &array[minIndex]);
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
    selectionSort(array, size);
    printf("Array after swap:\n");
    printArray(array, size);
}
