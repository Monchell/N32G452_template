/**
 * @file overflow_check.c
 * @author Monchell
 * @version v1.0.0
 * @brief �ṩ��һ�����������⺯��
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
 * @brief ��ջ����������Ӻ���
 * @param xTask����������pcTaskName����������
 * @note  ĳ�������ջ�����ʱ��ᴥ����Ŀǰֻ�ǽ���ѭ�����������Դ��ڴ�ӡ����
 */
void vApplicationStackOverflowHook( TaskHandle_t xTask,char * pcTaskName)
{
	while(1)
	{		
		overflowed = true;
	}
}
#endif

