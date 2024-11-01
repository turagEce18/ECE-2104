#include <iostream>
using namespace std;

class SimpleQueue {
    int front, rear;    // 'front' is the first in line, 'rear' is the last
    int* queue;         // The queue to hold the numbers
    int maxSize;        // The biggest size the queue can be

public:
    // Constructor to set the size of the queue
    SimpleQueue(int size) {
        maxSize = size;            // Set the maximum size
        queue = new int[maxSize];  // Create the queue with the given size
        front = -1;                // The queue starts empty
        rear = -1;
    }

    // Add a number to the queue (Enqueue)
    void enqueue(int number) {
        if (rear == maxSize - 1) { // If the queue is full
            cout << "The queue is full!\n";
        } else {
            if (front == -1)       // If it's the first number being added
                front = 0;         // Set the front to the first position
            rear++;                // Move 'rear' to the next position
            queue[rear] = number;  // Add the number to the 'rear' position
            cout << number << " has been added to the queue.\n";
        }
    }

    // Remove the first number from the queue (Dequeue)
    void dequeue() {
        if (front == -1 || front > rear) {  // If the queue is empty
            cout << "The queue is empty, nothing to remove!\n";
        } else {
            cout << queue[front] << " has been removed from the queue.\n";
            front++;                // Move 'front' to the next position
        }
    }

    // Destructor to clean up the memory when done
    ~SimpleQueue() {
        delete[] queue;            // Delete the queue to free up memory
    }
};

int main() {
    int size, howMany, number;

    // Ask the user for the size of the queue
    cout << "Enter the size of the queue: ";
    cin >> size;

    // Create a queue of that size
    SimpleQueue myQueue(size);

    // Ask how many numbers they want to add
    cout << "How many numbers do you want to add? ";
    cin >> howMany;

    // Add the numbers to the queue
    for (int i = 0; i < howMany; i++) {
        cout << "Enter a number to add: ";
        cin >> number;
        myQueue.enqueue(number);  // Add the number
    }

    // Remove the first number from the queue
    myQueue.dequeue();            // Remove the first number

    return 0;
}
