#include<stdio.h>
#include<stdlib.h>
// Sorts an array of given elements without comparison by counting the occurrences of each unique element in
// the given array. This is done by creating an auxiliary array of size equal to that of the largest element
// in the array. The sorting is done by mapping the count as an index of the auxiliary array.

int maxArray(int *arr, int size) {
    // Find the maximum element in the array
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int *arr, int size) {
    // Creating auxiliary array and setting it's elements to 0
    int max = maxArray(arr, size) + 1;
    int countArr[max], outputArr[size];
    for (int i = 0; i < max; i++)
        countArr[i] = 0;
    // Count of each element is stored at the index of that element i.e if count off 5 is 10, then index 5
    // of the count array will contain 10
    for (int i = 0; i < size; i++) {
        // As all elements in the count array is 0, we can count the number of occurrences by using the element in
        // the original array as an index and increment it's count in the count array
        countArr[arr[i]]++;
    }
    // Updating the count array by replacing the count of each element with the cumulative count
    for (int i = 1; i < max; i++) {
        countArr[i] += countArr[i - 1];
    }
    // Using the elements in the original array as an index in the count array, we calculate the correct position of
    // the element in the output array by subtracting 1 from the cumulative count. This new index will contain the
    // correct position of the element from the original array.
    for (int i = size - 1; i >= 0; i--) {
        // countArr[arr[i]] gets the cumulative count of the element arr[i], subtracting 1 from it gives us
        // arr[i]'s position in the output array count is then decremented
        outputArr[--countArr[arr[i]]] = arr[i];
    }
    // Copying elements from the output array to the original array
    for (int i = 0; i < size; i++) {
        arr[i] = outputArr[i];
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main() {
    // Creating an array of given size
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    int arr[size];
    // Assigning 'random' elements to the array
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }
    printf("Array before sort: \n");
    printArray(arr, size);
    countingSort(arr, size);
    printf("Array after sort: \n");
    printArray(arr, size);
}
