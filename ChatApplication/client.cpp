#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring> 

using namespace std;

int main(){
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        cout <<"\n Socket creation error. \n";
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0){
        cout <<"\nInvalid address / Address not supported\n";
        return -1;
    }

    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        cout << "\nConnection Failed\n";
        return -1;
    }

    string message;
    while (true){
        cout << "Enter message (type 'exit' to close): \n";
        getline(cin, message);

        if(message == "exit"){
            break;
        }
        send(sock, message.c_str(), message.length(), 0);
        valread = read(sock, buffer, 1024);
        cout <<"Server: "<<buffer<<endl;
        memset(buffer, 0, sizeof(buffer)); // clear the buffer
    }
    
    close(sock);

    return 0;
}
