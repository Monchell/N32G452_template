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
/** ������ */
/**
 * @brief ����,�ݹ����һ������
 * @param pvParameters�������������
 * @note  ��������ݹ�ĵ��ú������Դ˲��ϵ���������ջʹ�����
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
 * @brief ������,����������ջ
 * @param pvParameters�������������Ҫ����ջ��������
 * @note  �������᲻�ϼ�⴫�����Ķ�ջ���
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
 * @brief �ݹ麯��������һ�������ݹ�
 * @param pvParameters�������������
 * @note  �������᲻�ϼ���Ӧ����Ķ�ջ���
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
