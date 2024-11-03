#include <iostream>
using namespace std;

// Function to perform binary search
void binarySearch(int arr[], int size, int target) {
    int left = 0;                // Start of the array
    int right = size - 1;        // End of the array
    bool found = false;          // Flag to indicate if the target is found

    while (left <= right) {
        int middle = (left + right) / 2;  // Find the middle element

        if (arr[middle] == target) {      // If the target is found
            cout << "Number " << target << " found at position " << middle + 1 << ".\n";
            found = true;                 // Mark as found
            break;
        }
        else if (arr[middle] < target) {  // If target is greater, search in the right half
            left = middle + 1;
        } else {                          // If target is smaller, search in the left half
            right = middle - 1;
        }
    }

    if (!found) {                         // If the number was not found
        cout << "Number " << target << " not found in the array.\n";
    }
}

int main() {
    int size, target;

    // Input the size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int arr[size];  // Declare an array of given size

    // Input sorted array elements
    cout << "Enter the sorted elements of the array: \n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Input the target number to search
    cout << "Enter the number to search: ";
    cin >> target;

    // Perform binary search
    binarySearch(arr, size, target);

    return 0;
}
