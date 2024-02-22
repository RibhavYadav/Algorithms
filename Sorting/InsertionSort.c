#include<stdio.h>
#include<stdlib.h>

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void insertionSort(int *array, int size) {
    for (int i = 1; i < size; i++) { // Assuming first element to be sorted
        int elm = array[i], j = i - 1; // j stores the index of the last sorted element i.e i - 1
        while (j >= 0 && array[j] > elm) { // if true move the sorted element right by 1
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = elm;
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
    insertionSort(array, size);
    printf("Array after swap:\n");
    printArray(array, size);
}
