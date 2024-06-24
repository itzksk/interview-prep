#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Partition function to place the pivot element at the correct position
// and to arrange all elements smaller than the pivot to the left of the pivot
// and all elements greater than the pivot to the right of the pivot
int partition(int array[], int low, int high) {
    int pivot = array[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // Print current state of the array and the iterators
        printf("i: %d, j: %d, array: ", i, j);
        printArray(array, high + 1);

        // If the current element is smaller than or equal to the pivot
        if (array[j] <= pivot) {
            i++; // increment the index of the smaller element
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    // Print the state of the array after placing the pivot
    printf("After placing pivot, array: ");
    printArray(array, high + 1);
    return (i + 1);
}

// QuickSort function
void quickSort(int array[], int low, int high) {
    if (low < high) {
        // pi is the partitioning index, array[pi] is now at the right place
        int pi = partition(array, low, high);

        // Separately sort elements before and after partition
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// Main function to test QuickSort
int main() {
    int array[] = {6,2,1,4,8,7,5};
    int n = sizeof(array) / sizeof(array[0]);
    printf("Original array: \n");
    printArray(array, n);

    quickSort(array, 0, n - 1);
    printf("Sorted array: \n");
    printArray(array, n);
    return 0;
}
