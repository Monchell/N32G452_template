/**
 * @file example_task.cpp
 * @author Monchell
 * @version v1.0.0
 *
 * @copyright free
 */


#include "example_task.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "FreeRTOS.h"
#include "task.h"


//global_tick,理论上不要这样写，但是作为例子可以查看是否成功运行
uint32_t global_tick = 0;
/** 任务函数 */
/**
 * @brief 实例任务，每1000ms给global_tick+1
 * @param pvParameters：任务参数，无
 * @note  
 */
void example_task(void *pvParameters)
{
	while(1)
	{
		global_tick++;
		vTaskDelay(1000);
	}
}
/**
 * @}
 */
