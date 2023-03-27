#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc , char *argv[]) {
    int desc, clients, c, size;
    struct sockaddr_in server, client;
    char message[2000];

    //Create socket
    desc = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8882); // Host to network

    //Bind
    if (bind(desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        //print the error message
        printf("bind failed. Esgeatit");
        return 1;
    }
    puts("Ale");

    //Listen
    listen(desc, 3);

    //Accept and incoming connection
    puts("Waiting...");
    c = sizeof(struct sockaddr_in);

    while (1) {

        //accept connection from an incoming client
        clients = accept(desc, (struct sockaddr *) &client, (socklen_t *) &c);

        int pid = fork();

        if (pid == 0) {

            if (clients < 0) {
                printf("Fail");
                return 1;
            }
            puts("Ale Venga");

            //Receive a message from client
            while ((size = recv(clients, message, 2000, 0)) > 0) {
                //Send the message back to client
                printf("%s", message);
                write(clients, message, size);
            }

            if (size == 0) {
                puts("Client is gone.");
                fflush(stdout);
            }

            if (size == -1) {
                printf("Hin.");
            }
            return 0;
        }

    }
}