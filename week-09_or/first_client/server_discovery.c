/*
    Create Server (with thread)
*/

#include<stdio.h>
#include<winsock2.h>
#include<process.h>
#include<windows.h>
#include<ws2tcpip.h>
#include"servers.h"

void thread_discovery()
{

    SOCKET start_socket, new_socket;
    struct sockaddr_in server, client;
    int c;

    //Create a socket
    if((start_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        printf("Could not create socket: %d" , WSAGetLastError());
    }

    printf("Server socket created.\n");

    //Prepare the sockaddr_in structure
    server.sin_addr.S_un.S_addr = INADDR_ANY; //inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(11111);

    //Bind
    if( bind(start_socket, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
    {
        printf("Bind failed with error code: %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }

    puts("Bind done");

    //Listen to incoming connections
    listen(start_socket , 3);

    //Accept and incoming connection
    puts("Waiting for incoming connections...");

    c = sizeof(struct sockaddr_in);

    while((new_socket = accept(start_socket, (struct sockaddr *)&client, &c)) != INVALID_SOCKET)
    {
        puts("Connection accepted");

        char buff[4000];
        int bytes_rec = 0;

        ZeroMemory(buff, 4000);
        bytes_rec = recv(new_socket, buff, 4000, 0);
        printf("Discovery server received: %s\n", buff);
        //Sleep(750);
        if (!bytes_rec) {
            printf("Client disconnected");
            break;
        }
        buff[bytes_rec] = '\0';
        closesocket(new_socket);
    }

    if (new_socket == INVALID_SOCKET)
    {
        printf("Accept failed with error code: %d" , WSAGetLastError());
    }

    closesocket(start_socket);
    WSACleanup();
}
