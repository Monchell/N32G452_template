/**
 * @file example_task.h
 * @author Monchell
 * @version v1.0.0
 *
 * @copyright Copyright (c) 2019, Nations Technologies Inc. All rights reserved.
 */
#ifndef __EXAMPLE_TASK__
#define __EXAMPLE_TASK__

#ifdef __cplusplus
extern "C" {
#endif

#include "n32g45x.h"
//�����ջ��С
#define EXAMPLE_TASK_SIZE 		64
	
//�������ȼ�
#define EXAMPLE_TASK_PRIO			2
void example_task(void *xTasks);
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
