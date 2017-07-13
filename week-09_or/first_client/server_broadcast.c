/*
    Create Server (with thread)
*/

#include<stdio.h>
#include<winsock2.h>
#include<process.h>
#include<windows.h>
#include<ws2tcpip.h>
#include"servers.h"

void thread_broadcast()
{

    SOCKET s , new_socket;
    struct sockaddr_in server , client;
    int c;

    //Create a socket
    if((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET)
    {
        printf("Could not create socket: %d" , WSAGetLastError());
    }

    printf("Server socket created.\n");

    //Prepare the sockaddr_in structure
    server.sin_addr.S_un.S_addr = INADDR_ANY; //inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(22222);

    //Set sockopt
    int broadcastOn = 1;
    int checkCall = setsockopt(s, SOL_SOCKET, SO_BROADCAST, (char *)&broadcastOn, 4);
    if(checkCall == -1)
        printf("Error: setsockopt call failed");

    //Bind
    if(bind(s, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
    {
        printf("Bind failed with error code: %d" , WSAGetLastError());
        exit(EXIT_FAILURE);
    }

    puts("Bind done");

    //Listen to incoming connections
    //listen(s , 3);

    //Accept and incoming connection
    //puts("Waiting for incoming connections...");

    c = sizeof(struct sockaddr_in);

    while(1)
    {
        char buff[4000];
        int bytes_rec = 0;

        do {
            ZeroMemory(buff, sizeof(buff));
            //bytes_rec = recv(new_socket, buff, sizeof(buff), 0);
            bytes_rec = recvfrom(s, (char *)buff, sizeof(buff), 0, (struct sockaddr *)&client, &c);
            printf("Broadcast server received: %s\n", buff);
            Sleep(750);
            if (!bytes_rec) {
                printf("Client disconnected");
                break;
            }
            buff[bytes_rec] = '\0';
            //send(new_socket, buff, bytes_rec, 0);
            Sleep(900);
        } while (1 > 0);

        closesocket(s);
    }

    if (new_socket == INVALID_SOCKET)
    {
        printf("Accept failed with error code: %d" , WSAGetLastError());
    }

    closesocket(s);
    WSACleanup();
}
