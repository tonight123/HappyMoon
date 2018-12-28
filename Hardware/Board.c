/**********************************************************************************************************
 * @文件     board.c
 * @说明     硬件初始化
 * @作者     YuyingJin
 * @网站     https://yuyingjin0111.github.io/
 * @日期     2018 ~
**********************************************************************************************************/
#include "Board.h"
/**********************************************************************************************************
*函 数 名: BoardInit
*功能说明: 飞控硬件初始化
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void Board_Init(void){
	// 时钟初始化
	Systick_Init(168);								                       
	// 中断分组配置
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	
	// 系统延时5s等待用户放平无人机
	delay_ms(5000);
	// ADC初始化
	Adc_Init();
#ifdef MPU6000
	// SPI1初始化 用于陀螺仪和加速计读取 MPU6000
	SPI1_Configuration();
#else
	// SPI3初始化 用于陀螺仪和加速计读取 MPU6500
	SPI3_Configuration();
#endif
	// pwm定时器初始化用于电调信号 500hz频率
	PWM_Init(); 
	// 用于与高性能板载ARM或板载PC通信 波特率230400
	Usart1toOdroid_Init(230400); 
	// 蓝牙串口打开，用于与地面站通信
	Bluetooth_Init();
	// GPIO初始化 一些通用GPIO口可以在这里配置
	GeneralGpio_Init(); 	

//	// USB转串口初始化
//  Usb_Init();
}


