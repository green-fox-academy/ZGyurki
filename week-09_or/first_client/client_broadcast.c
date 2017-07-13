/*
    Create Server - Client communication (with thread)
*/

#include<stdio.h>
#include<winsock2.h>
#include<process.h>
#include<windows.h>
#include<ws2tcpip.h>
#include"servers.h"

void client_broadcast()
{

    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;

    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code: %d",WSAGetLastError());
        //return 1;
    }

    printf("Initialised.\n");
    //Create a socket
    if((s = socket(AF_INET , SOCK_DGRAM , IPPROTO_UDP )) == INVALID_SOCKET)
    {
        printf("Could not create socket: %d" , WSAGetLastError());
    }

    printf("Client socket created.\n");

    server.sin_addr.S_un.S_addr = inet_addr("255.255.255.255"); //("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 12345 );

    //setsockopt
    int broadcastOn = 1;
    int checkCall = setsockopt(s, SOL_SOCKET, SO_BROADCAST, (char *)&broadcastOn, 4);
    if(checkCall == -1)
        printf("Error: setsockopt call failed");

    //Remote_Address.sin_addr.s_addr|=htonl(0x1ff);
/*
    int broadcastOff = 0;
    checkCall = setsockopt(s, SOL_SOCKET, SO_BROADCAST, &broadcastOff, 4);
    if(checkCall == -1)
        printf("Error: Second setsockopt call failed");
*/
    //Thread the server
    _beginthread(thread_discovery, 0, NULL);
    Sleep(1000);

    //Connect to remote server
    /*if (connect(s, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        puts("Connect error");
        closesocket(s);
        WSACleanup();
        return 1;
    }

    puts("Connected");*/

    int sent_bytes = 1;
    int received_bytes;

    char broMes[] = "TOTORO 8888";

    do {
        // Receive the answer if message was sent
        //printf("\nEnter the message to send: \n");
        //gets(buff);
        if (sent_bytes > 0) {
            int send_res = sendto(s , broMes, strlen(broMes), 0, (struct sockaddr *) &server, sizeof(server));
            if (send_res != SOCKET_ERROR) {
                ZeroMemory(broMes, strlen(broMes));
                received_bytes = recv(s, broMes, strlen(broMes), 0);
                // Error handling
                if (received_bytes < 0) {
                    //handle_error("recv() ");
                } else {
                    // Printing out received string
                    broMes[received_bytes] = '\0';
                    printf("Client received: %s\n", broMes);
                    Sleep(500);
                }
            }
        }
    } while (sent_bytes > 0);


    closesocket(s);
    WSACleanup();
}
