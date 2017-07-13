/* Includes ------------------------------------------------------------------*/
#include "socket_client.h"
#include "socket_server.h"
#include "lcd_log.h"
#include "cmsis_os.h"
#include "app_ethernet.h"
#include "lwip/sockets.h"
#include "stm32746g_discovery_ts.h"
#include <string.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void set_points(TS_StateTypeDef touch_scr)
{
	if ((63 > touch_scr.touchX[0]) && (35 < touch_scr.touchX[0]) && (63 > touch_scr.touchY[0]) && (35 < touch_scr.touchY[0])) {
		touch_scr.touchX[0] = (63 + 35) / 2;
		touch_scr.touchY[0] = (63 + 35) / 2;
		BSP_LCD_FillCircle(touch_scr.touchX[0], touch_scr.touchY[0], 6);
	}
	if ((91 > touch_scr.touchX[0]) && (63 < touch_scr.touchX[0]) && (63 > touch_scr.touchY[0]) && (35 < touch_scr.touchY[0])) {
		touch_scr.touchX[0] = (63 + 91) / 2;
		touch_scr.touchY[0] = (63 + 35) / 2;
		BSP_LCD_FillCircle(touch_scr.touchX[0], touch_scr.touchY[0], 6);
	}
	if ((119 > touch_scr.touchX[0]) && (91 < touch_scr.touchX[0]) && (63 > touch_scr.touchY[0]) && (35 < touch_scr.touchY[0])) {
		touch_scr.touchX[0] = (119 + 91) / 2;
		touch_scr.touchY[0] = (63 + 35) / 2;
		BSP_LCD_FillCircle(touch_scr.touchX[0], touch_scr.touchY[0], 6);
	}
	if ((147 > touch_scr.touchX[0]) && (119 < touch_scr.touchX[0]) && (63 > touch_scr.touchY[0]) && (35 < touch_scr.touchY[0])) {
		touch_scr.touchX[0] = (119 + 147) / 2;
		touch_scr.touchY[0] = (63 + 35) / 2;
		BSP_LCD_FillCircle(touch_scr.touchX[0], touch_scr.touchY[0], 6);
	}
	if ((175 > touch_scr.touchX[0]) && (147 < touch_scr.touchX[0]) && (63 > touch_scr.touchY[0]) && (35 < touch_scr.touchY[0])) {
		touch_scr.touchX[0] = (175 + 147) / 2;
		touch_scr.touchY[0] = (63 + 35) / 2;
		BSP_LCD_FillCircle(touch_scr.touchX[0], touch_scr.touchY[0], 6);
	}
	if ((203 > touch_scr.touchX[0]) && (175 < touch_scr.touchX[0]) && (63 > touch_scr.touchY[0]) && (35 < touch_scr.touchY[0])) {
		touch_scr.touchX[0] = (175 + 203) / 2;
		touch_scr.touchY[0] = (63 + 35) / 2;
		BSP_LCD_FillCircle(touch_scr.touchX[0], touch_scr.touchY[0], 6);
	}
	if ((231 > touch_scr.touchX[0]) && (203 < touch_scr.touchX[0]) && (63 > touch_scr.touchY[0]) && (35 < touch_scr.touchY[0])) {
		touch_scr.touchX[0] = (231 + 203) / 2;
		touch_scr.touchY[0] = (63 + 35) / 2;
		BSP_LCD_FillCircle(touch_scr.touchX[0], touch_scr.touchY[0], 6);
	}
	if ((259 > touch_scr.touchX[0]) && (231 < touch_scr.touchX[0]) && (63 > touch_scr.touchY[0]) && (35 < touch_scr.touchY[0])) {
		touch_scr.touchX[0] = (231 + 259) / 2;
		touch_scr.touchY[0] = (63 + 35) / 2;
		BSP_LCD_FillCircle(touch_scr.touchX[0], touch_scr.touchY[0], 6);
	}
}

// Set the drawing stage!
void drawing_stage()
{
	uint8_t  *ptr = "AMOBA";
	BSP_LCD_Clear(0xFFFF0000);
	//Create drawing area
	BSP_LCD_SetTextColor(LCD_COLOR_DARKYELLOW);
	BSP_LCD_FillCircle(370, 65, 30);
	/*BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_FillCircle(340, 135, 26);*/
	BSP_LCD_SetTextColor(LCD_COLOR_DARKCYAN);
	BSP_LCD_FillCircle(370, 205, 30);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	//BSP_LCD_DrawLine(2, 2, 380, 270);
	for (int i = 1; i < 10; i++)
		BSP_LCD_DrawLine(15, i * 28, 265, i * 28);
	for (int j = 1; j < 10; j++)
			BSP_LCD_DrawLine(j * 28, 15, j * 28, 260);
	BSP_LCD_DisplayStringAt(89, 130, ptr, RIGHT_MODE);
}


// Changing color and sending coordinates!
int color_change(int s, TS_StateTypeDef touch_scr)
{
	int sent_bytes;
	BSP_TS_GetState(&touch_scr);
	if (touch_scr.touchDetected) {
		BSP_LED_On(LED1);
		/*if ((420 < touch_scr.touchX[0]) && (460 > touch_scr.touchX[0]) && (115 < touch_scr.touchY[0]) && (155 > touch_scr.touchY[0]))
			BSP_LCD_SetTextColor(LCD_COLOR_WHITE);*/
		if ((345 < touch_scr.touchX[0]) && (395 > touch_scr.touchX[0]) && (40 < touch_scr.touchY[0]) && (90 > touch_scr.touchY[0]))
			BSP_LCD_SetTextColor(LCD_COLOR_DARKYELLOW);
		if ((345 < touch_scr.touchX[0]) && (395 > touch_scr.touchX[0]) && (180 < touch_scr.touchY[0]) && (230 > touch_scr.touchY[0]))
			BSP_LCD_SetTextColor(LCD_COLOR_DARKCYAN);
		if ((245 > touch_scr.touchX[0]) && (35 < touch_scr.touchX[0]) && (245 > touch_scr.touchY[0]) && (35 < touch_scr.touchY[0])) {
			set_points(touch_scr);
			//BSP_LCD_FillCircle(touch_scr.touchX[0], touch_scr.touchY[0], 6);
			sent_bytes = send(s, &touch_scr, sizeof(TS_StateTypeDef), 0);
			osDelay(30);
		}
		if (sent_bytes < sizeof(TS_StateTypeDef))
			printf("Error: send message\n");
	}
	return sent_bytes;
}

// TODO:
// Implement this function!
void socket_client_thread(void const *argument)
{
	int s;
	struct sockaddr_in server;

	printf("Initialised.\n");

	//Creating client TCP IP socket
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0) {
		printf("Error: socket\n");
	} else {
		printf("Socket OK\n");
	}

	//Set the followings
	server.sin_addr.s_addr = inet_addr("10.27.6.229");
	server.sin_family = AF_INET;
	server.sin_port = htons( 54545 );

	//Connect to remote server
	int connect_retval = connect(s, (struct sockaddr *)&server, sizeof(server));
	if (connect_retval < 0) {
		printf("Error: connection\n");
	} else {
		printf("Connected\n");
	}

	//Sending coordinates to server
	int condition;
	TS_StateTypeDef touch_scr;

	do {
		if (BSP_PB_GetState(BUTTON_KEY)) {
			drawing_stage();
		}
		BSP_TS_GetState(&touch_scr);
		if (touch_scr.touchDetected) {
			BSP_LED_On(LED1);
			condition = color_change(s, touch_scr);
		} else
			BSP_LED_Off(LED1);
	} while (condition > 0);
	closesocket(s);
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
