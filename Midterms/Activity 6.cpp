#include <iostream>
using namespace std;

void printArray(const int arr[4][4]) {
    for (int indexR = 0; indexR < 4; ++indexR) {
        for (int indexC = 0; indexC < 4; ++indexC) {
            cout << arr[indexR][indexC] << "\t";
        }
        cout << endl<<"\n";
    }
}

bool binarySearch(const int arr[4][4], int target, int &rowFound, int &colFound) {
    int left = 0, right = 15; 

    while (left <= right) {
        int midRow = left + (right - left) / 2;
        int midCol = midRow % 4;
        rowFound = midRow / 4;

        if (arr[rowFound][midCol] == target) {
            colFound = midCol;
            return true;
        } else if (arr[rowFound][midCol] < target) {
            left = midRow + 1;
        } else {
            right = midRow - 1;
        }
    }
    return false;
}

int main() {
    int arr[4][4];
    int num;

    // Initialize the array with 3-digit sorted integers
    for (int indexR = 0, n = 100; indexR < 4; ++indexR) {
        for (int indexC = 0; indexC < 4; ++indexC, ++n) {
            arr[indexR][indexC] = n+10;
        }
    }

    // Print the array
    cout << "Content of the Array:" << endl;
    printArray(arr);

    // Prompt user for input
    cout << "Enter a number to search in the array: ";
    cin >> num;

    int rowFound, colFound;
    if (binarySearch(arr, num, rowFound, colFound)) {
        cout << "\nNumber " << num << " found at index: [" << rowFound<<"]" << "[" << colFound << "]" << endl;
    } else {
        cout << "\nNumber " << num << " not found in the array." << endl;
    }

    return 0;
}
