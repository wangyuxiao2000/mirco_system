#include "xuartlite.h"
#include "xparameters.h"
#include "xil_printf.h"
#include "sleep.h"

int uart_rx (XUartLite* UartInstance, u8* OutData)
{
	int finish = 0;
	int RecvNum = 0;
	u8 RecvData[64] = {0};  // 用于存储本次循环接收到的数据

	while(!finish)
	{
		// 从 UART接收数据
		int RecvCount = XUartLite_Recv(UartInstance, RecvData, sizeof(RecvData));

		// 将本次接收数据放入OutData内
    	if (RecvCount != 0)
    	{
    		memcpy(OutData + RecvNum, RecvData, RecvCount);
    		RecvNum = RecvNum + RecvCount;
    	}

    	// 收到回车字符时,认为完成一次完整接收,输出接收结果
    	if(RecvNum >= 1 && *(OutData + RecvNum - 1) == 13)
    	{
    		finish = 1;
    	}
	}

	return RecvNum;
}
