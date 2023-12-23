#include <iostream>
#include <string>
#include "BankAccount.cpp"

using namespace std;

void scremm(){
    cout <<"========================================================\n";
    cout <<"================ SIMPLE BANK MANAGEMENT ================\n";
    cout <<"========================================================\n";
    cout <<"====== 1. Deposit: \n";
    cout <<"====== 2. Withdraw: \n";
    cout <<"====== 3. Dispay Account: \n";
    cout <<"====== 4. Exit: \n";
    cout <<"====== Enter choice:\n";
}

int main(){
    std::string name;
    double initialDeposit;

    cout << "Enter your name: \n";
    getline(std::cin, name);
    cout << "Enter initial deposit: \n";
    std::cin >> initialDeposit;

    BankAccount account(name, initialDeposit);

    int choice;
    double amount;

    do{
        scremm();
        cin >> choice;
        switch (choice){
        case 1:
            cout<<"Enter deposit amount: ";
            cin >> amount;
            account.deposit(amount);
            break;
        case 2:
            cout <<"Enter withdrawal amount: ";
            cin >> amount;
            account.withdraw(amount);
            break;
        case 3:
            account.display();
            break;
        case 4:
            break;
        default:
            cout <<"Invalid choice\n";
            break;
        }

    } while (choice != 4);
    

    return 0;
}
