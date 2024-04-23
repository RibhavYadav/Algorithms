#include "stdio.h"
#include "stdlib.h"

int linearSearch(int *array, int length, int elm) {
    for (int i = 0; i < length; i++) {
        if (array[i] == elm)
            return i;
    }
    return -1;
}

void main() {
    int size, elm, found;
    printf("Enter size: "), scanf("%d", &size);
    int *arr = (int *) calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\nEnter element: "), scanf("%d", &elm);
    found = linearSearch(arr, size, elm);
    if (found == -1) printf("Element does not exist");
    else printf("Element found at index %d", found);
}
