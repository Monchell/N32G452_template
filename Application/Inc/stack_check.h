/**
 * @file stack_check.h
 * @author Monchell
 * @version v1.0.0
 *
 * @copyright Copyright (c) 2019, Nations Technologies Inc. All rights reserved.
 */
#ifndef __STACK_CHECK__
#define __STACK_CHECK__

#ifdef __cplusplus
extern "C" {
#endif

#include "n32g45x.h"
//任务堆栈大小
#define RECURSION_TASK_SIZE 		64
#define STACKCHECK_TASK_SIZE 		64
	
//任务优先级
#define RECURSION_TASK_PRIO			2
#define STACKCHECK_TASK_PRIO		2
void stackcheck_task(void *pvParameters);
void recursion_task(void *xTasks);
#ifdef __cplusplus
}
#endif

#endif /* __STACK_CHECK__ */
/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */
