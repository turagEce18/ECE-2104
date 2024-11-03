#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to place pivot in correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Select the last element as the pivot
    int i = (low - 1);      // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {  // If current element is smaller than the pivot
            i++;               // Increment the index of the smaller element
            swap(&arr[i], &arr[j]);  // Swap elements
        }
    }
    swap(&arr[i + 1], &arr[high]);  // Place the pivot in the correct position
    return (i + 1);                 // Return the index of the pivot
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Find the pivot index

        quickSort(arr, low, pi - 1);   // Sort elements before the pivot
        quickSort(arr, pi + 1, high);  // Sort elements after the pivot
    }
}

int main() {
    int size;

    // Input the size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int arr[size];  // Declare an array of given size

    // Input array elements
    cout << "Enter the elements of the array: \n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Perform Quick Sort
    quickSort(arr, 0, size - 1);

    // Output the sorted array
    cout << "Sorted array: \n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
