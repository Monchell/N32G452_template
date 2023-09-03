/**
 * @file overflow_check.c
 * @author Monchell
 * @version v1.0.0
 * @brief 提供了一个任务溢出检测函数
 * @copyright free
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "FreeRTOS.h"
#include "task.h"

#if configCHECK_FOR_STACK_OVERFLOW != 0
bool overflowed = false;
/**
 * @brief 堆栈溢出错误处理钩子函数
 * @param xTask：任务句柄，pcTaskName：任务名称
 * @note  某个任务堆栈溢出的时候会触发，目前只是进死循环，后续可以串口打印名称
 */
void vApplicationStackOverflowHook( TaskHandle_t xTask,char * pcTaskName)
{
	while(1)
	{		
		overflowed = true;
	}
}
#endif

