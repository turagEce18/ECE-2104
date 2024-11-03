#include <iostream>
using namespace std;

// Function to perform linear search
void linearSearch(int arr[], int size, int target) {
    bool found = false;  // Flag to indicate if the target is found
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {   // If the target is found
            cout << "Number " << target << " found at position " << i + 1 << ".\n";
            found = true;         // Mark as found
            break;                // Stop the search
        }
    }
    
    if (!found) {                 // If the number was not found
        cout << "Number " << target << " not found in the array.\n";
    }
}

int main() {
    int size, target;

    // Input the size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int arr[size];  // Declare an array of given size

    // Input array elements
    cout << "Enter the elements of the array: \n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Input the target number to search
    cout << "Enter the number to search: ";
    cin >> target;

    // Perform linear search
    linearSearch(arr, size, target);

    return 0;
}
