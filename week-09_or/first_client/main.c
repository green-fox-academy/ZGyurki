/*
    Create Server - Client communication (with thread)
*/

#include<stdio.h>
#include<winsock2.h>
#include<process.h>
#include<windows.h>
#include<ws2tcpip.h>
#include"servers.h"

int main()
{
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;

    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code: %d", WSAGetLastError());
        //return 1;
    }

    printf("Initialised.\n");

    //Create a socket
    if((s = socket(AF_INET , SOCK_STREAM , 0)) == INVALID_SOCKET)
    {
        printf("Could not create socket: %d" , WSAGetLastError());
    }

    printf("Client socket created.\n");

    server.sin_addr.s_addr = inet_addr("10.27.6.152");
    server.sin_family = AF_INET;
    server.sin_port = htons( 12125 );

    //Connect to remote server
    if (connect(s, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        puts("Connect error");
        closesocket(s);
        WSACleanup();
        //return 1;
    } else {
        puts("Connected");
    }

    char buff[4000];
    int sent_bytes = 1;
    int received_bytes;

    do {
        // Receive the answer if message was sent
        printf("\nEnter the message to send: ");
        gets(buff);
        if (sent_bytes > 0) {
            int send_res = send(s , buff, strlen(buff), 0);
            if (send_res != SOCKET_ERROR) {
                ZeroMemory(buff, 4000);
                received_bytes = recv(s, buff, 4000, 0);
                // Error handling
                if (received_bytes < 0) {
                    //handle_error("recv() ");
                } else {
                    // Printing out received string
                    //buff[received_bytes] = '\0';
                    printf("Client received: %s\n", buff);
                    //Sleep(500);
                }
            }
        }
    } while (sent_bytes > 0);


    closesocket(s);
    WSACleanup();
	return 0;
}
