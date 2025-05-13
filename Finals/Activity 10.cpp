#include <iostream>
#include <string>

using namespace std;

void displayMenu(const string items[], const double prices[], const int stocks[], int itemCount) {
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
}

double acceptPayment() {
    double payment;
    cout << "Enter payment (PHP): ";
    cin >> payment;
    return payment;
}

int selectItem(const string items[], int itemCount) {
    int choice;
    cout << "Enter the item number you want to buy: ";
    cin >> choice;

    if (choice < 1 || choice > itemCount) {
        cout << "Invalid choice. Please try again.\n";
        return -1;
    }

    return choice - 1;
}

void dispenseItem(string itemName, double itemPrice, int& itemStock, double& payment) {
    if (itemStock <= 0) {
        cout << "Sorry, " << itemName << " is out of stock.\n";
        return;
    }

    if (payment < itemPrice) {
        cout << "Insufficient payment. Please insert more coins or bills.\n";
        return;
    }

    payment -= itemPrice;
    itemStock--;

    cout << "Dispensing " << itemName << ". Thank you for your purchase!\n";
}

void printReceipt(const string& itemName, double itemPrice, double change) {
    cout << "\n=== Receipt ===\n";
    cout << "Item: " << itemName << '\n';
    cout << "Price: PHP " << itemPrice << '\n';
    cout << "Change: PHP " << change << '\n';
    cout << "================\n";
}

int main() {
	const int itemCount = 5;
    string items[itemCount] = {"Cadbury", "Reeses", "Hershy's", "M&M", "Snickers"};
    double prices[itemCount] = {20.00, 25.00, 10.00, 30.00, 15.00};
    int stocks[itemCount] = {0, 12, 15, 11, 12};

    double payment = 0.0;

    while (true) {
        displayMenu(items, prices, stocks, itemCount);

        payment = acceptPayment();

        int selectedItem = selectItem(items, itemCount);
        if (selectedItem == -1) continue;

        dispenseItem(items[selectedItem], prices[selectedItem], stocks[selectedItem], payment);

        if (payment > prices[selectedItem]) {
            printReceipt(items[selectedItem], prices[selectedItem], payment);
        }

        char anotherTransaction;
        cout << "Do you want to buy another item? (y/n): ";
        cin >> anotherTransaction;

        if (anotherTransaction == 'n' || anotherTransaction == 'N') {
            break;
        }
    }

    cout << "Thank you for using the vending machine!\n";
    return 0;
}
