#include <iostream>

using namespace std;

double CelsiusToFahrenheit(double celsius){
    return (celsius*9.0/5.0) + 32.0;
}

double FahrenheitToCelsius(double fahrenheit){
    return (fahrenheit - 32.0)*5.0/9.0;
}

double CelsiusToKelvin(double celsius){
    return celsius+273.15;
}

double KelvinToCelsius(double kelvin){
    return kelvin - 273.15;
}

int scremm(){
    int choice;
    cout <<"========================================================\n";
    cout <<"================ TEMPERATURE CONVERTER =================\n";
    cout <<"========================================================\n";
    cout <<"====== 1. Celsius To Fahrenheit: \n";
    cout <<"====== 2. Fahrenheit To Celsius: \n";
    cout <<"====== 3. Celsius To Kelvin: \n";
    cout <<"====== 4. Kelvin To Celsius: \n";
    cout <<"====== 5. Quit:\n";
    cout <<"=== Enter your choice (1-4): ";
    cin >> choice;
    return choice;
}

int main(){
    double temperature, convertedTem;
    bool run = false;
    int choice = scremm();
    
    cout <<"=== Enter the temperature: ";
    cin >> temperature;

    switch (choice){
        case 1:
            convertedTem = CelsiusToFahrenheit(temperature);
            break;
        case 2:
            convertedTem = FahrenheitToCelsius(temperature);
            break;
        case 3:
            convertedTem = CelsiusToKelvin(temperature);
            break;
        case 4:
            convertedTem = KelvinToCelsius(temperature);
            break;
        default:
            cout <<"Invalid Choice\n";
            break;
    }
    cout <<"Converted Temperature: "<<convertedTem<<endl;  

    return 0;
}
