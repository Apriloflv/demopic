/******************************************************************************

                  版权所有 (C), 厦门优胜卫厨科技有限公司

 ******************************************************************************
  文 件 名   : picos.h
  版 本 号   : 初稿
  作    者   : LV
  生成日期   : 2018年4月12日
  最近修改   :
  功能描述   : picos.c 的头文件
  函数列表   :
  修改历史   :
  1.日    期   : 2018年4月12日
    作    者   : LV
    修改内容   : 创建文件

******************************************************************************/

#ifndef __PICOS_H__
#define __PICOS_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/* 定义可移植的无符号数据类型            */
typedef bit            uint1;
typedef unsigned char  uint8;                                   //定义可移植的无符号8位整数关键字            
typedef signed   char  int8;                                    // 定义可移植的有符号8位整数关键字            
typedef unsigned int   uint16;                                  // 定义可移植的无符号16位整数关键字          
typedef signed   int   int16;                                   // 定义可移植的有符号16位整数关键字         
typedef unsigned long  uint32;                                  // 定义可移植的无符号32位整数关键字       
typedef signed   long  int32;                                   // 定义可移植的有符号32位整数关键字       
typedef float          float24;
typedef double         int24;

/*  系统相关定义声明*/
#ifdef NUM_TASKS										    	// 需要重新定义最大任务数，未定义则默认为30
#define OS_MAX_TASKS    NUM_TASKS                        		//最大任务数
#else
#define OS_MAX_TASKS    30                               		//最大任务数
#endif
#define MS                        *8                    		//系统时间单位，对应于OSTimeTick的调用周期  
#define OSTickHOOK_EN            1                       		//允许系统时钟钩子函数  
#define OSIdle_EN                0                       		// 允许空闲任务，用于计算系统CPU占用率
#define OS_TASK_RAN_TIME_CALC_EN 0                       		//是否允许任务运行时间计算，以系统时间为基准 ，1开0关
#define NOP() asm("NOP")
#define FOSC_CPU        16                               		//定义晶振频率,单位M 


/*    定义程序任务基本结构  */
typedef struct 
{
    void (*TaskProc)(void); //程序任务指针
    uint16 TaskPeriod; //任务对应的时间片周期，支持最大65535*系统时间基准
} _task_;

extern void delay_100us(uint8 n);
extern void delay_1ms(uint16 n);
extern void nop_200(void);
extern void os_idle(void);
extern void task_start(void);
extern uint16 os_task_run_time_get(uint8 task_n);
extern void os_tick_hook(void);
extern void os_time_tick(void);
extern void task_nop(void);
extern void time_clock_second_tick_add(void);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __PICOS_H__ */
