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
#include <chrono>
#include <thread>

using namespace std;

char client_message[156];
const char* ACCEPTED = "ACCEPTED\n";

int server_fd = socket(AF_INET, SOCK_STREAM, 0);
struct sockaddr_in server_address = {0};
socklen_t socklen = sizeof(sockaddr_in); 
   

int main(){
   // int server_fd = socket(AF_INET, SOCK_STREAM, 0);
   // struct sockaddr_in server_address = {0};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    bind(server_fd, (struct sockaddr *)&server_address, socklen_t(sizeof(sockaddr_in)));
    listen(server_fd, 5);
    
  //  int client_fd = accept(server_fd, (struct sockaddr*)&server_address, &socklen);
  //  while(true){
       // client_fd = accept(server_fd, (struct sockaddr*)&server_address, &socklen);
    void proc(void);
    thread th1(proc); 
    thread th2(proc);
    thread th3(proc);
    thread th4(proc);
    //}
    th1.join();
    th2.join();
    th3.join();
    th4.join();
    
    close(server_fd);
    

    return 0;
}

void proc(void){
    int client_fd = accept(server_fd, (struct sockaddr*)&server_address, &socklen);
  //  while(true){
       // client_fd = accept(server_fd, (struct sockaddr*)&server_address, &socklen);
    read(client_fd, client_message, size_t(32));
    cout<<client_message;
    this_thread::sleep_for(chrono::seconds(3));
    write(client_fd, ACCEPTED, strlen(ACCEPTED));
    close(client_fd);
}
