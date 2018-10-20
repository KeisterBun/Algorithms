/**
 * Quicksort implementation by Keith Drew, 2018
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 15

void swap(int *array, int index1, int index2);
int partition(int *array, int low_index, int high_index);
void quicksort(int *array, int low_index, int high_index);
void print_array(int *array, int bound);

int main() {
    int *arr = new int[ARRAY_SIZE];
    srand(time(NULL));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100 + 1;
    }

    print_array(arr, ARRAY_SIZE);
    
    quicksort(arr, 0, ARRAY_SIZE - 1);

    print_array(arr, ARRAY_SIZE);

    return 0;
}

// Swaps positions of items at index1 and index2 in array. Not safe.
void swap(int *array, int index1, int index2) {
    int tmp = array[index1];
    array[index1] = array[index2];
    array[index2] = tmp;
}

int partition(int *array, int low_index, int high_index) {
    int pivot = array[high_index];
    int return_index = low_index - 1;

    for (int i = low_index; i < high_index; i++) {
        if (array[i] <= pivot) {
            return_index++;
            swap(array, return_index, i);
            print_array(array, ARRAY_SIZE);
        }
    }

    return_index++;
    swap(array, return_index, high_index);
    return return_index;
}

void quicksort(int *array, int low_index, int high_index) {
    if (low_index < high_index) {
        int pivot_index = partition(array, low_index, high_index);

        quicksort(array, low_index, pivot_index - 1);
        quicksort(array, pivot_index + 1, high_index);
    }
}

void print_array(int *array, int bound) {
    for (int i = 0; i < bound; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}