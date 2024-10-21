#include <iostream>
using namespace std;

class SimpleStack {
    int top;           // This tells us where the top of the stack is
    int* stackArray;   // Array to store stack elements
    int maxSize;       // Maximum size of the stack

public:
    // Constructor to define the stack size
    SimpleStack(int size) {
        maxSize = size;              // Set the maximum size
        stackArray = new int[maxSize];  // Create an array with that size
        top = -1;                    // Start with the stack empty
    }

    // Add a number to the stack (Push)
    void push(int number) {
        if (top == maxSize - 1) {     // Check if stack is full
            cout << "Stack is full.\n";
        } else {
            top++;                    // Move top up by 1
            stackArray[top] = number; // Add the number to the top
            cout << number << " added.\n";
        }
    }

    // Remove any number from the stack
    void remove(int number) {
        if (top == -1) {              // Check if stack is empty
            cout << "Stack is empty, nothing to remove.\n";
            return;
        }

        // Search for the number in the stack
        int index = -1;
        for (int i = 0; i <= top; i++) {
            if (stackArray[i] == number) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Number not found in the stack.\n";
        } else {
            // Shift elements after the removed number to the left
            for (int i = index; i < top; i++) {
                stackArray[i] = stackArray[i + 1];
            }
            top--;  // Reduce the top position
            cout << number << " removed from the stack.\n";
        }
    }

    // Show the number on top (Peek)
    void peek() {
        if (top == -1) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Top is: " << stackArray[top] << endl;
        }
    }

    // Destructor to clean up memory
    ~SimpleStack() {
        delete[] stackArray;          // Free memory
    }
};

int main() {
    int size, numberOfElements, element, numberToRemove;
    
    // Input stack size
    cout << "Enter stack size: ";
    cin >> size;

    SimpleStack myStack(size);  // Create stack with user-defined size

    // Input number of elements to push
    cout << "How many numbers do you want to add? ";
    cin >> numberOfElements;

    // Input elements and push them to the stack
    for (int i = 0; i < numberOfElements; i++) {
        cout << "Enter number to push: ";
        cin >> element;
        myStack.push(element);  // Push user input into the stack
    }

    // Ask user which number to remove
    cout << "Enter number to remove: ";
    cin >> numberToRemove;
    myStack.remove(numberToRemove);   // Remove the user-specified number

    // Check the top element
    myStack.peek();

    return 0;
}
