#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>

#define PORT 8882
#define MAX 999

int main() {
    printf("Echo Client\n");
    char ip[999];
    printf("Server IP: ");
    scanf(" %s", ip);

    int s = socket(AF_INET , SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(PORT);

    memset(server.sin_zero, 0, sizeof(server.sin_zero));
    connect(s, (struct sockaddr*) &server, sizeof(server));

    char msg[MAX];
    while (strcmp(msg, "q\n"))
    {
        printf("Send: ");
        fgets(msg, MAX, stdin);
        send(s, msg, sizeof(msg), 0);

        char rec[MAX];
        if (recv(s, rec, MAX, 0) <= 0) // The server closed
            return -1;

        printf("Recieved: %s\n\n", rec);
    }

    printf("Exited!");
}