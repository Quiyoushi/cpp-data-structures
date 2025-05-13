#include <iostream>
using namespace std;

// Function Declaration
void selectionSort(int arr[], int size);
void bubbleSort(int arr[], int size);
void insertionSort(int arr[], int size);

int main() {
    int size, array[50];

    // Prompt user for the size of the array
    cout << "Enter the Size of Array (max 50): ";
    cin >> size;

    // Check if size is valid
    if (size > 50 || size <= 0) {
        cout << "Invalid size. Please enter a size between 1 and 50.";
        return 1;
    }

    // Prompt user to enter elements with a restriction of no duplicate
    cout << "Enter " << size << " Array Elements (4 digits each, no duplicates):\n";
    for (int i = 0; i < size; i++) {
        bool duplicate;
        do {
            duplicate = false;
            cout << "Element " << (i + 1) << ": ";
            cin >> array[i];
            if (array[i] < 1000 || array[i] > 9999) {
                cout << "Please enter a 4-digit number.\n";
                i--; // Retry this iteration for invalid input
            } else {
                for (int j = 0; j < i; j++) {
                    if (array[i] == array[j]) {
                        cout << "Duplicate found! Please enter a unique number.\n";
                        duplicate = true;
                        i--; // Retry this iteration for duplicate input
                        break;
                    }
                }
            }
        } while (duplicate);
    }

    // Call selection sort
    selectionSort(array, size);
    
    // Call bubble sort
    bubbleSort(array, size);
    
    // Call insertion sort 
    insertionSort(array, size);

    return 0;
}

// Function: selectionSort
// Uses selection sort algorithm to sort the array in ascending order
void selectionSort(int arr[], int size) {
    int temp, minIndex;

    for (int index = 0; index < size - 1; index++) {
        minIndex = index;

        // Find the minimum element in the remaining array
        for (int index2 = index + 1; index2 < size; index2++) {
            if (arr[index2] < arr[minIndex]) {
                minIndex = index2;
            }
        }

        // Swap the found minimum element with the first element
        if (minIndex != index) {
            temp = arr[index];
            arr[index] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

	// Print Array
    cout << "\nArray after Selection Sort:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function: bubbleSort
// Uses bubble sort algorithm to sort the array in ascending order
void bubbleSort(int arr[], int size) {
    int temp;

    for (int index = 0; index < size - 1; index++) {
        for (int index2 = 0; index2 < size - 1 - index; index2++) {
            if (arr[index2] > arr[index2 + 1]) {
                temp = arr[index2];
                arr[index2] = arr[index2 + 1];
                arr[index2 + 1] = temp;
            }
        }
    }

	// Print Array
    cout << "\nArray after Bubble Sort:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function: insertionSort
// Uses insertion sort algorithm to sort the array in ascending order
void insertionSort(int arr[], int size) {
    int key, index2;

    for (int index = 1; index < size; index++) {
        key = arr[index];
        index2 = index - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead
        // of their current position
        while (index2 >= 0 && arr[index2] > key) {
            arr[index2 + 1] = arr[index2];
            index2--;
        }
        arr[index2 + 1] = key;
    }

	// Print Array
    cout << "\nArray after Insertion Sort:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}