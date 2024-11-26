#include "wyx.h"

#define UART_0_ID XPAR_UARTLITE_0_DEVICE_ID

XUartLite UART_0;

int main()
{
	// 初始化变量
    int login = 0;
    u8 RxData[1024] = {0};

    // 初始化 UART 实例
    XUartLite_Initialize(&UART_0, UART_0_ID);

    // 发送启动信息
    xil_printf("Hello, WYX!\n");
    xil_printf("Password:\n");

    // 循环接收数据
    while(1)
    {
    	while(!login)
    	{
    		u8 password[7];
    		uart_rx(&UART_0, RxData);
    		memcpy(password, RxData, 7);

    		if(strcmp((const char*)password, "xilinx\r") == 0)
    		{
    			xil_printf("Success\n");
    			login = 1;
    		}
    		else
    		{
    			xil_printf("Failed\n");
    		}
    	}

    }

    return 0;
}
