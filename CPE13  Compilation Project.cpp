#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

// Activity 1
void activity_1() {
    int num1 = 400;
    int num2 = 40;

    cout << "\nInteger 1: " << num1 << endl
         << "Integer 2: " << num2 << endl;

    cout << "The Sum of the Integers: " << num1 + num2 << endl
         << "The Difference of the Integers: " << num1 - num2 << endl
         << "The Product of the Integers: " << num1 * num2 << endl
         << "The Quotient of the Integers: " << num1 / num2 << endl;
}

// Activity 2
void activity_2() {
    cout << "\t";

    for (int i = 11; i <= 20; i++) {
        cout << i << "\t";
    }

    cout << "\t" << endl;

    for (int i = 11; i <= 20; i++) {
 
        cout << "\n" << i << "\t";

        for (int j = 11; j <= 20; j++) {
            cout << i * j << "\t";
        }

        cout << "\n";
    }
}

// Acitivity 3
void activity_3(){	
	int number, numberSquared;
	

	cout << "\nEnter a number: ";
	cin >> number;
	cout<< endl;
	
	numberSquared = number*number;
	

	for(int loop = 0; loop <  number; loop++){
		

		 	for (int loop1 = 0; loop1 < number; loop1++ ){
		 		cout<<numberSquared<<"\t"<<"|";
		 		numberSquared --;
		 		
			 }; 
			 
		cout<<endl;
	}; 
	
}

// Acitivity 4
void activity_4() { 
	double circleDiameter;

    cout << "\nEnter the circle's diameter: ";
    cin >> circleDiameter;

 
    double radius = circleDiameter / 2;

    double circleArea =  M_PI * pow(radius, 2);
    double circleCircumference = 2 *  M_PI * radius;


    double semiMajorAxis = circleDiameter;
    double semiMinorAxis = semiMajorAxis / 2;
    double ellipseArea =  M_PI * semiMajorAxis / 2 * semiMinorAxis;
    double ellipseCircumference =  M_PI * (3 * (semiMajorAxis + semiMinorAxis) - pow(semiMajorAxis - semiMinorAxis, 2) / (semiMajorAxis + semiMinorAxis)); 

    cout << "\nFor Circle:" << endl;
    cout << "Circle Area: " << circleArea << endl;
    cout << "Circle Circumference: " << circleCircumference << endl;

    cout << "\nFor Ellipse:" << endl;
    cout << "Ellipse Area: " << ellipseArea << endl;
    cout << "Ellipse Circumference (Approximate): " << ellipseCircumference << endl;
}

// Acitivity 5
void activity_5(){
	const int MAX_SIZE = 10;

    int row, col;
    cout << "\nEnter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> col;

    if (row > MAX_SIZE || col > MAX_SIZE) {
        cout << "Error: Maximum allowed size is 10x10." << endl;
        return;
    }

    int arr[MAX_SIZE][MAX_SIZE];

    cout << "\nEnter 3-Digit Integers: " << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << "Enter element at position (" << i + 1 << ", " << j + 1 << "): ";
            cin >> arr[i][j];
        }
    }

    cout << "\nThe contents of the array are:" << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int sum = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            sum += arr[i][j];
        }
    }

    cout << "\nThe sum of all elements in the array is: " << sum << endl;
}

// Acitivity 6
void activity_6(){
	const int MAX_SIZE = 4;

    int arr[MAX_SIZE][MAX_SIZE];
    int num;

    for (int indexR = 0, n = 100; indexR < MAX_SIZE; ++indexR) {
        for (int indexC = 0; indexC < MAX_SIZE; ++indexC, ++n) {
            arr[indexR][indexC] = n + 10;
        }
    }

    cout << "\nContent of the Array:" << endl;
    for (int indexR = 0; indexR < MAX_SIZE; ++indexR) {
        for (int indexC = 0; indexC < MAX_SIZE; ++indexC) {
            cout << arr[indexR][indexC] << "\t";
        }
        cout << endl << "\n";
    }

    cout << "Enter a number to search in the array: ";
    cin >> num;

    int left = 0, right = 15;
    int rowFound = -1, colFound = -1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midRow = mid / MAX_SIZE;
        int midCol = mid % MAX_SIZE;

        if (arr[midRow][midCol] == num) {
            rowFound = midRow;
            colFound = midCol;
            found = true;
            break;
        } else if (arr[midRow][midCol] < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found) {
        cout << "\nNumber " << num << " found at index: [" << rowFound << "][" << colFound << "]" << endl;
    } else {
        cout << "\nNumber " << num << " not found in the array." << endl;
    }
}

// Acitivity 7
void activity_7(){
	const int MAX_SIZE = 50;
    int size, array[MAX_SIZE];

    cout << "\nEnter the Size of Array (max 50): ";
    cin >> size;

    if (size > MAX_SIZE || size <= 0) {
        cout << "Invalid size. Please enter a size between 1 and 50.";
        return;
    }

    cout << "Enter " << size << " Array Elements (4 digits each, no duplicates):\n";
    for (int i = 0; i < size; i++) {
        bool duplicate;
        do {
            duplicate = false;
            cout << "Element " << (i + 1) << ": ";
            cin >> array[i];
            if (array[i] < 1000 || array[i] > 9999) {
                cout << "Please enter a 4-digit number.\n";
                i--;
            } else {
                for (int j = 0; j < i; j++) {
                    if (array[i] == array[j]) {
                        cout << "Duplicate found! Please enter a unique number.\n";
                        duplicate = true;
                        i--;
                        break;
                    }
                }
            }
        } while (duplicate);
    }

 
    for (int index = 0; index < size - 1; index++) {
        int minIndex = index;
        for (int index2 = index + 1; index2 < size; index2++) {
            if (array[index2] < array[minIndex]) {
                minIndex = index2;
            }
        }
        if (minIndex != index) {
            swap(array[index], array[minIndex]);
        }
    }

    cout << "\nArray after Selection Sort:\n";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    for (int index = 0; index < size - 1; index++) {
        for (int index2 = 0; index2 < size - 1 - index; index2++) {
            if (array[index2] > array[index2 + 1]) {
                swap(array[index2], array[index2 + 1]);
            }
        }
    }

    cout << "\nArray after Bubble Sort:\n";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    for (int index = 1; index < size; index++) {
        int key = array[index];
        int index2 = index - 1;
        while (index2 >= 0 && array[index2] > key) {
            array[index2 + 1] = array[index2];
            index2--;
        }
        array[index2 + 1] = key;
    }

    cout << "\nArray after Insertion Sort:\n";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Acitivity 8
void activity_8(){
	const int rows = 4;
    const int cols = 3;
    const int lim = 12;
    int array[rows][cols] = {20, 40, 60, 80, 10, 30, 50, 70, 90, 22, 44, 66};
    int copiedArray[rows][cols] = {0};
    int size = 12;

    auto printArray = [](int arr[rows][cols], int size) {
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
    };

    auto insertElement = [&](int row, int col, int value) {
        if (size >= lim) {
            cout << "\nArray is full, Cannot insert another element." << endl;
            return;
        }
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            cout << "\nInvalid row or column." << endl;
            return;
        }

        for (int i = size; i > (row * cols + col); i--) {
            array[i / cols][i % cols] = array[(i - 1) / cols][(i - 1) % cols];
        }
        array[row][col] = value;
        size++;

        cout << "\nElement inserted successfully." << endl;
    };

    auto deleteElement = [&](int row, int col) {
        if (size == 0) {
            cout << "\nArray is empty. Cannot delete any elements." << endl;
            return;
        }
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            cout << "\nInvalid row or column." << endl;
            return;
        }

        for (int i = (row * cols + col); i < size - 1; i++) {
            array[i / cols][i % cols] = array[(i + 1) / cols][(i + 1) % cols];
        }
        size--;

        cout << "\nElement deleted" << endl;
    };

    auto copyArray = [&]() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                copiedArray[i][j] = array[i][j];
            }
        }
        cout << "\nEntire array copied" << endl;
    };

    cout << "\nFixed Printed Array:" << endl;
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
            case 1: {
                int row, col, value;
                cout << "\nInsertion" << endl;
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter row (0 to " << rows - 1 << "): ";
                cin >> row;
                cout << "Enter column (0 to " << cols - 1 << "): ";
                cin >> col;
                insertElement(row, col, value);
                cout << "\nUpdated Array:" << endl;
                printArray(array, size);
                break;
            }
            case 2: {
                int row, col;
                cout << "\nDeletion Selected";
                cout << "\nEnter row (0 to " << rows - 1 << "): ";
                cin >> row;
                cout << "Enter column (0 to " << cols - 1 << "): ";
                cin >> col;
                deleteElement(row, col);
                cout << "\nUpdated Array:" << endl;
                printArray(array, size);
                break;
            }
            case 3: {
                copyArray();
                cout << "\nCopied Array:" << endl;
                printArray(copiedArray, size);
                break;
            }
            case 4: {
                cout << "\nProgram Terminated." << endl;
                return;
            }
            default: {
                cout << "\nInvalid choice" << endl;
                break;
            }
        }
    }
	
	
}

// Activity 9
void activity_9(){
	const int ROWS = 4;
    const int COLS = 4;
    const int MAX_SIZE = ROWS * COLS;
    int arr[MAX_SIZE];
    int size = 0;
    int choice, value;

    cout << "Enter 16 two-digit numbers to initialize the 4x4 array:" << endl;
    for (int i = 0; i < MAX_SIZE; i++) {
        cin >> arr[i];
        size++;
    }

    auto printArray = [&](int arr[], int size) {
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
    };

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
            case 1: {
                if (size == MAX_SIZE) {
                    cout << "Error: Array is full. Cannot push." << endl << endl;
                } else {
                    cout << "Enter value to push (two-digit number): ";
                    cin >> value;
                    if (value < 10 || value > 99) {
                        cout << "Error: Please enter a two-digit number." << endl;
                    } else {
                        for (int i = size; i > 0; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[0] = value;
                        size++;
                    }
                }
                break;
            }
            case 2: {
                if (size == 0) {
                    cout << "Error: Array is empty. Cannot pop." << endl << endl;
                } else {
                    cout << "Popped value: " << arr[0] << endl << endl;
                    for (int i = 0; i < size - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    size--;
                }
                break;
            }
            case 3: {
                if (size == MAX_SIZE) {
                    cout << "Error: Array is full. Cannot enqueue." << endl << endl;
                } else {
                    cout << "Enter value to enqueue (two-digit number): ";
                    cin >> value;
                    if (value < 10 || value > 99) {
                        cout << "Error: Please enter a two-digit number." << endl << endl;
                    } else {
                        for (int i = size; i > 0; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[0] = value;
                        size++;
                    }
                }
                break;
            }
            case 4: {
                if (size == 0) {
                    cout << "Error: Array is empty" << endl << endl;
                } else {
                    cout << "Dequeued value: " << arr[size - 1] << endl << endl;
                    size--;
                }
                break;
            }
            case 5: {
                cout << "End program" << endl;
                return;
            }
            default:
                cout << "Invalid choice" << endl;
        }

        printArray(arr, size);
    }
}

// Activity 10	
void activity_10(){
	const int itemCount = 5;
    string items[itemCount] = {"Cadbury", "Reeses", "Hershy's", "M&M", "Snickers"};
    double prices[itemCount] = {20.00, 25.00, 10.00, 30.00, 15.00};
    int stocks[itemCount] = {10, 12, 15, 11, 12};

    double payment = 0.0;

    while (true) {
     
        cout << "\n===== Chocolate Vending Machine ========\n";
        cout << "== No. Chocolates   Price (PHP) Stock ==\n";
        for (int i = 0; i < itemCount; ++i) {
            cout <<"== "<< i + 1 << ".   " 
                 << items[i];
            for (int j = items[i].length(); j < 15; ++j)
			cout << " "; 
			cout << prices[i] << "         " << stocks[i]<< "  =="<< endl;
        }
        cout << "========================================\n";

      
        cout << "Enter payment (PHP): ";
        cin >> payment;

      
        int choice;
        cout << "Enter the item number you want to buy: ";
        cin >> choice;

        if (choice < 1 || choice > itemCount) {
            cout << "Invalid choice. Please try again.\n";
            continue;
        }

        int selectedItem = choice - 1;

    
        if (stocks[selectedItem] <= 0) {
            cout << "Sorry, " << items[selectedItem] << " is out of stock.\n";
            continue;
        }

        if (payment < prices[selectedItem]) {
            cout << "\nInsufficient payment. Please insert more coins or bills.\n";
            continue;
        }

        payment -= prices[selectedItem];
        stocks[selectedItem]--;

        cout << "Dispensing " << items[selectedItem] << ". Thank you for your purchase!\n";

    
        cout << "\n=== Receipt ===\n";
        cout << "Item: " << items[selectedItem] << '\n';
        cout << "Price: PHP " << prices[selectedItem] << '\n';
        cout << "Change: PHP " << payment << '\n';
        cout << "================\n";

   
        char anotherTransaction;
        cout << "Do you want to buy another item? (y/n): ";
        cin >> anotherTransaction;

        if (anotherTransaction == 'n' || anotherTransaction == 'N') {
            break;
        }
    }

    cout << "Thank you for using the vending machine!\n";
}

// Main 
int main() {
    int choice;

    while (true) {
		cout << "\n\t\tCPE13 - Data Structures and Algorithm Activity Compilation";
        cout << "\n\n\t\t\t\t   Choose an option:\n";
        cout << "\t\t\t\t    1. Activity 1\n";
        cout << "\t\t\t\t    2. Activity 2\n";
        cout << "\t\t\t\t    3. Activity 3\n";  
        cout << "\t\t\t\t    4. Activity 4\n";
        cout << "\t\t\t\t    5. Activity 5\n";
        cout << "\t\t\t\t    6. Activity 6\n";
        cout << "\t\t\t\t    7. Activity 7\n";
        cout << "\t\t\t\t    8. Activity 8\n";
        cout << "\t\t\t\t    9. Activity 9\n";
        cout << "\t\t\t\t   10. Activity 10\n";
        cout << "\t\t\t\t   11. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                activity_1();
                break;
            case 2:
                activity_2();
                break;
            case 3:
				activity_3();
				break;
			case 4:
				activity_4();
				break;
			case 5:
				activity_5();
				break;
			case 6:
				activity_6();
				break;
			case 7:
				activity_7();
				break;
			case 8:
				activity_8();
				break;
			case 9:
				activity_9();
				break;
			case 10:
				activity_10();
				break;
            case 11:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
