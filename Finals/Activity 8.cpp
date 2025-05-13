#include <iostream>

using namespace std;

const int rows = 4;
const int cols = 3; 
const int lim = 12;

// Function to print the 2D array 
void printArray(int arr[rows][cols], int size) {
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (index < size) {
                cout << arr[i][j] << "\t";
                index++;
            }
        }
        cout << endl;
    }
}

// insert function
void insertElement(int arr[rows][cols], int &size, int row, int col, int value) {
	if (size >= lim) {
        cout << "\nArray is full, Cannot insert another element." << endl;
        return;
    }
	 cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter row (0 to " << rows - 1 << "): ";
                cin >> row;
                cout << "Enter column (0 to " << cols - 1 << "): ";
                cin >> col;
    
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        cout << "\nInvalid row or column." << endl;
        return;
    }

    // Insert element and shift right
    for (int i = size; i > (row * cols + col); i--) {
        arr[i / cols][i % cols] = arr[(i - 1) / cols][(i - 1) % cols];
    }
    arr[row][col] = value;
    size++;

    cout << "\nElement inserted successfully." << endl;
}

// delete function
void deleteElement(int arr[rows][cols], int &size, int row, int col) {
    if (size == 0) {
        cout << "\nArray is empty. Cannot delete any elements." << endl;
        return;
    }
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        cout << "\nInvalid row or column." << endl;
        return;
    }

    // Shift elements to the left
    for (int i = (row * cols + col); i < size - 1; i++) {
        arr[i / cols][i % cols] = arr[(i + 1) / cols][(i + 1) % cols];
    }
    size--;

    cout << "\nElement deleted" << endl;
}

// Duplicate array function
void copyArray(int src[rows][cols], int copiedArray[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            copiedArray[i][j] = src[i][j];
        }
    }
    cout << "\nEntire array copied" << endl;
}

int main() {
    int array[rows][cols] = {20, 40, 60, 80, 10, 30, 50, 70, 90, 22, 44, 66}; //Initial array
    int copiedArray[rows][cols] = {0};       // Array to store the copied array
    int size = 12;                           // Current number of elements in array

    cout << "Fixed Printed Array:" << endl;
    printArray(array, size);

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "\n1. Insertion" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Copy" << endl;
        cout << "4. Exit" << endl;
        cout << "\nEnter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: { // Insertion
                int row, col, value;
                cout<<"\nInsertion"<<endl;
                insertElement(array, size, row, col, value);
                cout << "\nUpdated Array:" << endl;
                printArray(array, size);	
                break;
            }
            case 2: { // Deletion
                int row, col;
                cout<<"\nDeletion Selected";
                cout << "\nEnter row (0 to " << rows - 1 << "): ";
                cin >> row;
                cout << "Enter column (0 to " << cols - 1 << "): ";
                cin >> col;
                deleteElement(array, size, row, col);
                cout << "\nUpdated Array:" << endl;
                printArray(array, size);
                break;
            }
            case 3: { // Copying the array
                copyArray(array, copiedArray);
                cout << "\nCopied Array:" << endl;
                printArray(copiedArray, size);
                break;
            }
            case 4: { // Exit
                cout << "\nProgram Terminated." << endl;
                return 0;
            }
            default: {
                cout << "\nInvalid choice" << endl;
                break;
            }
        }
    }
}
