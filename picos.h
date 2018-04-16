/******************************************************************************

                  ��Ȩ���� (C), ������ʤ�����Ƽ����޹�˾

 ******************************************************************************
  �� �� ��   : picos.h
  �� �� ��   : ����
  ��    ��   : LV
  ��������   : 2018��4��12��
  ����޸�   :
  ��������   : picos.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2018��4��12��
    ��    ��   : LV
    �޸�����   : �����ļ�

******************************************************************************/

#ifndef __PICOS_H__
#define __PICOS_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/* �������ֲ���޷�����������            */
typedef bit            uint1;
typedef unsigned char  uint8;                                   //�������ֲ���޷���8λ�����ؼ���            
typedef signed   char  int8;                                    // �������ֲ���з���8λ�����ؼ���            
typedef unsigned int   uint16;                                  // �������ֲ���޷���16λ�����ؼ���          
typedef signed   int   int16;                                   // �������ֲ���з���16λ�����ؼ���         
typedef unsigned long  uint32;                                  // �������ֲ���޷���32λ�����ؼ���       
typedef signed   long  int32;                                   // �������ֲ���з���32λ�����ؼ���       
typedef float          float24;
typedef double         int24;

/*  ϵͳ��ض�������*/
#ifdef NUM_TASKS										    	// ��Ҫ���¶��������������δ������Ĭ��Ϊ30
#define OS_MAX_TASKS    NUM_TASKS                        		//���������
#else
#define OS_MAX_TASKS    30                               		//���������
#endif
#define MS                        *8                    		//ϵͳʱ�䵥λ����Ӧ��OSTimeTick�ĵ�������  
#define OSTickHOOK_EN            1                       		//����ϵͳʱ�ӹ��Ӻ���  
#define OSIdle_EN                0                       		// ��������������ڼ���ϵͳCPUռ����
#define OS_TASK_RAN_TIME_CALC_EN 0                       		//�Ƿ�������������ʱ����㣬��ϵͳʱ��Ϊ��׼ ��1��0��
#define NOP() asm("NOP")
#define FOSC_CPU        16                               		//���徧��Ƶ��,��λM 


/*    ���������������ṹ  */
typedef struct 
{
    void (*TaskProc)(void); //��������ָ��
    uint16 TaskPeriod; //�����Ӧ��ʱ��Ƭ���ڣ�֧�����65535*ϵͳʱ���׼
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
