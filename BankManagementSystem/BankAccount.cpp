#include <string>
#include <iostream>

using namespace std;

class BankAccount{
private:
    std::string name;
    double balance;
public:
    BankAccount(std::string _accountName, double _initialBalance);
    void deposit(double _amount);
    void withdraw(double _amount);
    void display();
    std::string getName();
    void setName(std::string _name);
    void setBalance(double _balance);
    double getBalance();
};

BankAccount::BankAccount(std::string accountName, double initialBalance){
    this->name = accountName;
    this->balance = initialBalance;
}

void BankAccount::deposit(double amount){
    if (amount > 0){
        balance += amount;
    }
}

void BankAccount::withdraw(double amount){
    if(amount <= balance){
        balance -= amount;
    }else{
        std::cout <<"Insufficient funds."<<std::endl;
    }
}

std::string BankAccount::getName(){
    return this->name;
}

double BankAccount::getBalance(){
    return this->balance;
}

void BankAccount::display(){
    std::cout << "Account: "<<getName()<<"\nBalance: $"<<getBalance()<<std::endl;
}
