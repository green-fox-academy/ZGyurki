#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <ws2tcpip.h>

// Create Server and Client Applications that send and receive messages.

int main()
{
  WSADATA wsad;
  WORD ver = MAKEWORD(2, 2);

  int client_size;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  struct sockaddr_in client;
  //struct sockaddr_storage serverStorage;
  //socklen_t addr_size;


  /*---- Create the socket. The three arguments are: ----*/
  /* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
  SOCKET welcomeSocket = socket(AF_INET, SOCK_STREAM, 0);

  /*---- Configure settings of the server address struct ----*/
  /* Address family = Internet */
  serverAddr.sin_family = AF_INET;
  /* Set port number, using htons function to use proper byte order */
  serverAddr.sin_port = htons(8080);
  /* Set IP address to localhost */
  serverAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
  /* Set all bits of the padding field to 0 */
  //memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));

  /*---- Bind the address struct to the socket ----*/
  bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  /*---- Listen on the socket, with 5 max connection requests queued ----*/
  listen(welcomeSocket, SOMAXCONN);
  if(listen(welcomeSocket, 5)==0)
    printf("Listening\n");
  else
    printf("Error\n");

  /*---- Accept call creates a new socket for the incoming connection ----*/
  client_size = sizeof client;
  SOCKET newSocket = accept(welcomeSocket, (struct sockaddr *) &client, &client_size);

  char host[NI_MAXHOST];
  char service[NI_MAXHOST];

  ZeroMemory(host, NI_MAXHOST);
  ZeroMemory(service, NI_MAXHOST);

  closesocket(welcomeSocket);

  /*---- Read the message from the server into the buffer ----*/

  /*---- Send message to the socket of the incoming connection ----*/
  while(1) {
    ZeroMemory(buffer, 1024);
    int bytes_rec = recv(newSocket, buffer, 1024, 0);
    send(newSocket, buffer, bytes_rec + 1, 0);
  }

  //strcpy(buffer,"Hello World\n");
  closesocket(newSocket);

  WSACleanup();

  return 0;

}
