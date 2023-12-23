#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

using namespace std;

int main(){
    int server_fb, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // creating socket file descriptor
    if((server_fb = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to port 8080
    if(setsockopt(server_fb, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("Setsockopt");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if(bind(server_fb, (struct sockaddr *)&address, sizeof(address)) < 0){
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    if(listen(server_fb,3) < 0){
        perror("Listen");
        exit(EXIT_FAILURE);
    }
    if((new_socket = accept(server_fb, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0){
        perror("Accept");
        exit(EXIT_FAILURE);
    }

    while (true){
        memset(buffer, 0, sizeof(buffer));
        int bytes_read = read(new_socket, buffer, sizeof(buffer));
        if(bytes_read == 0){
            cout <<"Client dusconnected. \n";
            break;
        }
        
        send(new_socket, buffer, strlen(buffer), 0);

        if(strcmp(buffer, "exit") == 0){
            cout <<"Exit command received. Closing connection.\n";
            break;
        }
    }

    close(new_socket);
    close(server_fb);
    return 0;
}
