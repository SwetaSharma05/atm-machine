#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;
    string pin;

public:
    BankAccount(string name, int accNo, double initialBalance, string pinCode) {
        accountHolder = name;
        accountNumber = accNo;
        balance = initialBalance;
        pin = pinCode;
    }

    bool authenticate(string enteredPin) {
        return pin == enteredPin;
    }

    void displayBalance() {
        cout << "Current Balance: $" << balance << endl;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount.\n";
            return;
        }
        balance += amount;
        cout << "Deposited $" << amount << " successfully.\n";
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
        } else if (amount > balance) {
            cout << "Insufficient balance.\n";
        } else {
            balance -= amount;
            cout << "Withdrawn $" << amount << " successfully.\n";
        }
    }

    void displayDetails() {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
    }
};

// ATM Class
class ATM {
private:
    BankAccount* userAccount;

public:
    ATM(BankAccount* acc) {
        userAccount = acc;
    }

    void start() {
        string enteredPin;
        cout << "Enter your PIN: ";
        cin >> enteredPin;

        if (!userAccount->authenticate(enteredPin)) {
            cout << "Invalid PIN. Access Denied.\n";
            return;
        }

        int choice;
        do {
            cout << "\n===== ATM Menu =====\n";
            cout << "1. Check Balance\n";
            cout << "2. Deposit\n";
            cout << "3. Withdraw\n";
            cout << "4. View Account Details\n";
            cout << "5. Exit\n";
            cout << "Choose an option: ";
            cin >> choice;

            switch (choice) {
            case 1:
                userAccount->displayBalance();
                break;
            case 2: {
                double amount;
                cout << "Enter amount to deposit: $";
                cin >> amount;
                userAccount->deposit(amount);
                break;
            }
            case 3: {
                double amount;
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                userAccount->withdraw(amount);
                break;
            }
            case 4:
                userAccount->displayDetails();
                break;
            case 5:
                cout << "Thank you for using the ATM. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
            }
        } while (choice != 5);
    }
};

// Main function
int main() {
    // Create a sample account
    BankAccount myAccount("John Doe", 12345678, 1000.0, "1234");

    // Create ATM object
    ATM atm(&myAccount);

    // Start ATM session
    atm.start();

    return 0;
}
