#include "stdio.h"
#include "stdlib.h"


void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partition(int *array, int start, int end) {
    int pivot = array[end], i = start - 1;
    for (int j = start; j < end; j++) {
        if (array[j] <= pivot) {
            swap(&array[++i], &array[j]);
        }
    }
    swap(&array[++i], &array[end]);
    return i;
}

void quickSort(int *array, int start, int end) {
    if (start < end) {
        int pivot = partition(array, start, end);
        quickSort(array, start, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
}

int binarySearch(int *array, int start, int end, int elm) {
    if (start <= end) {
        int middle = (start + end) / 2;
        if (array[middle] > elm) {
            return binarySearch(array, start, middle - 1, elm);
        } else if (array[middle] < elm) {
            return binarySearch(array, middle + 1, end, elm);
        } else if (array[middle] == elm) {
            return middle;
        }
    }
    return -1;  // Element not found
}


void main() {
    int size, elm, found;

    printf("Enter size: "), scanf("%d", &size);
    int *arr = (int *) calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }

    quickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nEnter element: "), scanf("%d", &elm);
    found = binarySearch(arr, 0, size, elm);
    if (found == -1) printf("Element does not exist");
    else printf("Element found at index %d", found);
}
