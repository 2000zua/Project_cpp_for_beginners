#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void showTasks(vector<string>& tasks){
    cout << "To Do List: \n";
    for(int i =0; i < tasks.size(); ++i){
        cout <<i+1<<". "<<tasks[i]<<endl;
    }
}

void scremm(){
    cout <<"=======================================\n";
    cout <<"======= A - Add a task\n";
    cout <<"======= V - View tasks\n";
    cout <<"======= Q - Quit\n";
    cout <<"======= Enter your choice: ";
}

int main(){
    vector<string> tasks;
    string task;
    char choice;

    ifstream inputFile("tasks.txt");
    while (getline(inputFile, task)){
        tasks.push_back(task);
    }
    inputFile.close();

    do
    {
        scremm();
        cin >> choice;

        switch (choice){
        case 'A':
        case 'a':
            cout <<"== Enter a task: \n";
            cin.ignore();
            getline(cin, task);
            tasks.push_back(task);
            break;
        case 'v':
        case 'V':
            showTasks(tasks);
            break;
        }

    } while (choice != 'Q' && choice != 'q');
    
    ofstream outputFile("tasks.txt");
    for(const auto &t : tasks){
        outputFile <<t<<endl;
    }
    outputFile.close();

    return 0;
}
