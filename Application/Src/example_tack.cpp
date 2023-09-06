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


//global_tick,�����ϲ�Ҫ����д��������Ϊ���ӿ��Բ鿴�Ƿ�ɹ�����
uint32_t global_tick = 0;
/** ������ */
/**
 * @brief ʵ������ÿ1000ms��global_tick+1
 * @param pvParameters�������������
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
