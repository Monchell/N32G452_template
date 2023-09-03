/**
 * @file main.cpp
 * @author Monchell
 * @version v1.0.0
 *
 * @copyright free
 */


#include "stack_check.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "FreeRTOS.h"
#include "task.h"


void recursion(uint32_t tick);
/** 任务函数 */
/**
 * @brief 任务,递归调用一个函数
 * @param pvParameters：任务参数，无
 * @note  这个任务会递归的调用函数，以此不断的增加任务栈使用情况
 */
void recursion_task(void *pvParameters)
{
	recursion(5);
	recursion(10);
	while(1)
	{
		vTaskDelay(1000);
	}
}


/**
 * @brief 任务函数,检测任务检测堆栈
 * @param pvParameters：任务参数，需要检测堆栈的任务句柄
 * @note  这个任务会不断检测传入句柄的堆栈情况
 */
#if INCLUDE_uxTaskGetStackHighWaterMark == 1
UBaseType_t left_stack = 0;
void stackcheck_task(void *xTasks)
{
	while(1)
	{
		left_stack = uxTaskGetStackHighWaterMark(*(TaskHandle_t*)xTasks);
		vTaskDelay(1000);
	}		
}
#else
#error INCLUDE_uxTaskGetStackHighWaterMark should be 1
#endif

/**
 * @brief 递归函数，调用一个函数递归
 * @param pvParameters：任务参数，无
 * @note  这个任务会不断检测对应句柄的堆栈情况
 */
void recursion(uint32_t tick)
{
	vTaskDelay(1000);
	if(tick == 0)
		return;
	tick --;	
	recursion(tick);
	return;
}
/**
 * @}
 */
