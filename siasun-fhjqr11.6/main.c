/*
 * main.c

 *
 *  Created on: Aug 24, 2019
 *      Author: siasunggm
 */

#include <main.h>
#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <can.h>
#include <time.h>
#include <signal.h>
#include <Timer.h>
#include <zconf.h>
#include <TCP.h>
#include <Thread_Pool.h>
#include <HC_SuK043_C.h>
#include "AGV/agv.h"
#include "AGV/Agv_Control.h"
#include "AGV/Motion_Ctrl.h"
#include"AGV/Reproducer_Lamplight.h"
#include<cJSON_User.h>



extern canBus_ta *CAN0;
extern canBus_tb *CAN1;


char buffer[8];    //发送电台数组


void init_System()
{
	Paramter_Define();
	CAN_init();      //CAN总线初始化
	pool_init (5);  //线程池初始化，其中共4个活动线程
}

void Get_Agv_Data()
{

	Pthread_Analy();//线程处理函数
	CanRecvThreada(CAN0);  //CAN接收
    CanRecvThreadb(CAN1);  //CAN接收
    SDIO_Out_Data();    //SDIO通过CAN输出
}

void Get_Agv_Goal()
{
	 //Get_Transceiver_Data();  //获得调度数据
	 Get_HC_SuK043_Data();  //获得显示屏数据
}

int main ()
{

	init_System();//系统初始化

	while(1)
	{

        buffer[0] = 1;
        buffer[1] = 2;
        buffer[2] = 3;
        buffer[3] = 4;
        buffer[4] = 5;
        buffer[5] = 6;
        buffer[6] = 7;
        buffer[7] = 8;

       Get_Agv_Data();     //获取车体信息

       // Serialize();
       //De_Serialize();

       //Get_Agv_Goal();  //获得车体目标坐标值

       //Prase_Sensor_Data();    //传感器处理

      // AGV_Movecontrol();     //AGV运动控制

      // AGV_RUN();


	}

}
