#include <liburing.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <vector>

using namespace std;

//string client_message;
char client_message[156];
const char* hello = "hello!!!\nНапиши сообщение ==> ";

int main(){
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address = {0};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    bind(server_fd, (struct sockaddr *)&server_address, socklen_t(sizeof(sockaddr_in)));
    listen(server_fd, 5);
    socklen_t socklen = sizeof(sockaddr_in); 
    int client_fd = accept(server_fd, (struct sockaddr*)&server_address, &socklen);
    while(true){
        client_fd = accept(server_fd, (struct sockaddr*)&server_address, &socklen);
        write(client_fd, hello, strlen(hello));
        read(client_fd, client_message, size_t(32));
        cout<<client_message;
        close(client_fd);
    }
    close(server_fd);

    return 0;
}