#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    // Initialize random seed
    srand(static_cast<unsigned int>(time(0)));

    int secretNumber = rand() % 101;
    int guess = 0;

    cout << "Я выбрал число от 1 до 100.\n";
    cout << "Можете ли вы догадаться, что это такое? \n";

    while (guess != secretNumber){
        cout <<"Введите свое предположение: ";
        cin >> guess;

        if (guess > secretNumber){
            cout <<"\n😂 Очень высоко! Пробовать снова.\n";
        }else if(guess < secretNumber){
            cout <<"\n😂 Очень низкий. попробуйте еще раз.\n";
        }else{
            cout <<"\n😍😍 Поздравляю!!! Вы угадали мой номер!!\n";
        }   
    }
    return 0;
}
