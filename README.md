## N32G452_template说明
<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [N32G452_template说明](#n32g452_template说明)
  - [简介](#简介)
  - [文件目录](#文件目录)
  - [历史版本](#历史版本)

<!-- /code_chunk_output -->
### 简介
这是一个N32G452的工程模板，内容包含了N32G452的keil-mdk基本配置，同时加入了freertos的操作系统
如何将这个模板工程，转换成自己的工程，可以查看[如何修改工程名](https://blog.csdn.net/u010134355/article/details/123470539)
### 如何测试代码能跑
直接编译debug查看窗口表达式添加变量global_tick,如何能看到他1s加1，就证明这个代码能在你的单片机上运行了。
### 文件目录
```bash
+---Application//用于存放应用层代码
|   +---Inc
|   \---Src
+---BSP//板级支持包，包括驱动，外设
|   +---Device//外设
|   |   +---Inc
|   |   \---Src
|   \---Driver//驱动
|       +---Inc
|       \---Src
+---firmware//官方提供的固件库部分代码，这个部分是从官方的SDK移植过来的
|   +---CMSIS
|   |   +---core
|   |   \---device
|   |       \---startup
|   +---n32g45x_algo_lib
|   |   +---inc
|   |   \---lib
|   +---n32g45x_std_periph_driver
|   |   +---inc
|   |   \---src
|   \---n32g45x_usbfs_driver
|       +---inc
|       \---src
+---FreeRTOS//freertos操作系统
|   +---include
|   \---portable
|       +---Keil
|       +---MemMang
|       \---RVDS
|           \---ARM_CM4F
+---Middleware//中间层，这部分我的理解是一些算法和对驱动进一步封装的一些模块
|   +---Inc
|   \---Src
\---Project//存放keil project
```
### 历史版本
- 2023.8.09 构建了添加文件结构目录，把一些错别字删掉了
- 2023.8.09 把初始任务转移到Application的其他文件里，使用了一个堆栈检测的任务作为例子
- 2023.8.11 中断组改成4，优先级个数16，子优先级个数0，和FreeRTOSConfig.h里面的configLIBRARY_LOWEST_INTERRUPT_PRIORITY保持一致
- 2023.9.03 修改堆栈优先级宏定义存放位置，现在存放在任务函数实现文件的头文件里面了
- 2023.9.03 修改任务堆栈溢出检测功能的代码，解耦到中间层，理解为系统的堆栈进行检测
- 2023.9.03 systick的中断函数放在了timer.c里面，把n32g54x_it.c和h删掉了
- 2023.9.06 把示例任务改成了对global_tick这个变量1s加1
