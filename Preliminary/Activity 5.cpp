#include <iostream>
using namespace std;

// Function to input the array
void fillArray(int arr[][10], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << "\nEnter element at position (" << i+1 << ", " << j+1 << "): ";
            cin >> arr[i][j];
        }
    }
}

// Function to calculate the sum of all elements in the array
int sumArray(int arr[][10],int row, int col) {
    int sum = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            sum += arr[i][j];
        }
    }
    return sum;
}

int main() {
	
    int row, col;
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> col;

    // Create a 2D array with maximum size of 10x10
    int arr[10][10];
	
	
	cout<< "\nEnter 3-Digit Integers: "<<endl;
	
    fillArray(arr, row, col);
  	
	cout << "\nThe contents of the array are:" << endl;
  	
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nThe sum of all elements in the array is: " << sumArray(arr, row, col) << endl;

    return 0;
}