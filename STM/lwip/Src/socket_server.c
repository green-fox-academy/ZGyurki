/* Includes ------------------------------------------------------------------*/

#include "socket_server.h"
#include "lcd_log.h"
#include "cmsis_os.h"
#include "app_ethernet.h"
#include "lwip/sockets.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

// TODO:
// Implement this function!
void socket_server_thread(void const *argument)
{
	// Create listener socket
		is_ip_ok();
	    int listen_socket = socket(AF_INET, SOCK_STREAM, 0);
	    if (listen_socket < 0) {
	        printf("Error: msg_listener - socket()\n");
	        return;
	    }

	    // Server listen address structure initialization
		struct sockaddr_in address;
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = INADDR_ANY;
		address.sin_port = htons( 12125 );
		//struct sockaddr *listen_addr = (struct sockaddr *) &address;

		// Bind the listen address to the socket
		if (bind(listen_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
	        printf("Error: msg_listener - bind()\n");
	        return;
		}

	    // Start listening on with the set socket with a predefined queue size
		if (listen(listen_socket, 1000) < 0) {
	        printf("Error: msg_listener - listen()\n");
	        return;
		}

	    // printf("msg_listener initialized\n");

	    struct sockaddr_in client_addr;
	    int client_socket;
	    int received_bytes;
	    // Define buffer for incoming message
	    char buff[4000];
	    osDelay(3000);
	    printf("\n!!Message arae is open!!\n");

	    while (1) {
	        //printf("msg_listener - Waiting for connection...\n");
	        // Accept incoming connections
	        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, sizeof(struct sockaddr_in));
	        if (client_socket == 0)
	            printf("Error: msg_listener - accept()\n");
	        do {
	            // Receive broadcast data
	            received_bytes = recv(client_socket, buff, 4000, 0);
	            // Check for error
	            if (received_bytes < 0)
	                printf("Connection over\n");
	            else {
	                // Close the string
	                buff[received_bytes] = '\0';

	                // Get client IP
	                //uint32_t client_ip = client_addr.sin_addr.s_addr;

	                // Print client name
	                // printf("%s: ", get_usr_name(client_ip));
	                // Print the message
	                printf("This meassege received: %s\n", buff);
	                send(client_socket, buff, received_bytes, 0);
	            }
	        } while (received_bytes > 0);
	        closesocket(client_socket);
	    }
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
