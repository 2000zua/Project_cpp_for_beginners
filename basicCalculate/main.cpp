#include <iostream>


using namespace std;

void calculate(double number1, double number2, char operation){
    switch (operation){
        case '+':
            cout << "\nResult of sum: "<< number1 + number2<<endl;
            break;
        case '-':
            cout << "\nResult of subtr: "<< number1 - number2<<endl;
            break;
        case '*':
            cout << "\nResult of multp: "<< number1 * number2<<endl;
            break;
        case '/':
            if (number2 != 0){
                cout << "\nResult of division: "<< number1 / number2<<endl;
            }else{
                cout << "\nError: Division by zero"<<endl;
            }  
            break;
        default:
            cout << "\nInvalid operation"<<endl;
            break;
    }
}

int main(){
    double number1, number2;
    char operation;
    
    cout << "Enter the first number: ";
    cin >> number1;

    cout <<"Enter the second number: ";
    cin >> number2;

    cout <<"Enter an operation (+, -, *,/): ";
    cin >> operation;

    calculate(number1, number2, operation);

    return 0;
}
