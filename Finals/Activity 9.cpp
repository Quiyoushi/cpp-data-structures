#include <iostream>
using namespace std;

const int ROWS = 4;
const int COLS = 4;
const int MAX_SIZE = ROWS * COLS;

void printArray(int arr[], int size) {
    cout << "Current array (4x4):" << endl;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int index = i * COLS + j;
            if (index < size) {
                cout << arr[index] << "\t";
            } else {
                cout << "--\t";
            }
        }
        cout << endl;
    }
}

int main() {
    int arr[MAX_SIZE];
    int size = 0; 
    int choice, value;

    cout << "Enter 16 two-digit numbers to initialize the 4x4 array:" << endl;
    for (int i = 0; i < MAX_SIZE; i++) {
        cin >> arr[i];
        size++;
    }

    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Enqueue\n";
        cout << "4. Dequeue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1: { // Push
                if (size == MAX_SIZE) {
                    cout << "Error: Array is full. Cannot push." << endl << endl;
                } else {
                    cout << "Enter value to push (two-digit number): ";
                    cin >> value;
                    if (value < 10 || value > 99) {
                        cout << "Error: Please enter a two-digit number." << endl;
                    } else {
                        // Shift elements to the right to make space for the new element at the top-left
                        for (int i = size; i > 0; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[0] = value; // Insert the new value at the beginning
                        size++;
                    }
                }
                break;
            }
            case 2: { // Pop
                if (size == 0) {
                    cout << "Error: Array is empty. Cannot pop." << endl << endl;
                } else {
                    cout << "Popped value: " << arr[0] << endl << endl;
                    // Shift elements to the left to fill the gap after removing the top element
                    for (int i = 0; i < size - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    size--;
                }
                break;
            }
            case 3: { // Enqueue
                if (size == MAX_SIZE) {
                    cout << "Error: Array is full. Cannot enqueue." << endl << endl;
                } else {
                    cout << "Enter value to enqueue (two-digit number): ";
                    cin >> value;
                    if (value < 10 || value > 99) {
                        cout << "Error: Please enter a two-digit number." << endl << endl;
                    } else {
                        // Shift elements to the right to make space for the new element at the top-left
                        for (int i = size; i > 0; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[0] = value; // Insert the new value at the beginning
                        size++;
                    }
                }
                break;
            }
            case 4: { // Dequeue
                if (size == 0) {
                    cout << "Error: Array is empty" << endl << endl;
                } else {
                    cout << "Dequeued value: " << arr[size - 1] << endl << endl;
                    size--; // Remove the bottom-right element
                }
                break;
            }
            case 5: { // Exit
                cout << "End program" << endl;
                return 0;
            }
            default:
                cout << "Invalid choice" << endl;
        }

        printArray(arr, size);
    }

    return 0;
}