/*
 * Motion_Ctrl.c
 *
 *  Created on: 2019-9-25
 *      Author: siasunhebo
 */


#include "stdio.h"
#include "stdlib.h"
#include <stdint.h>
#include <main.h>
#include "Motion_Ctrl.h"
#include<CNS_MGS_160S.h>
#include<Agv_Control.h>
#include<common.h>

uint16_t ethCommBreakFlag = 0x00;
uint16_t Motionstyle      = MOTIONSTATE_ONSTOPING;
 CNS_MGS_160S_t CNS_MGS_160Sa;
 CNS_MGS_160S_t CNS_MGS_160Sc;
 Velocity_Class_t AGV_Expect_Velocity;
 float  Kp=0.7, Ki, Kd;//试验测得
 uint16_t  AGVMove_flag;
 float  AGV_VL;
 float  AGV_VR;

void Movement_Control_Goahead()//直行前进
{
	uint16_t i = 0,n=0,flag=0;
	float Error, PID_Result,Error_next, Error_last;
	for (i=0;i<16;i++)  //判断磁条上有多少个点检测到信号
	{
		if (CNS_MGS_160Sa.point[i]==1)
		{
			n = n + 1;
		}
	}
	if(n < 5)
	{
		flag = 0;
	}
	else
		flag = 1;
	if(n>1)
	{
		AGVMove_flag=1;
	}

	for (i=6;i<10;i++)
	{
		if(CNS_MGS_160Sa.point[i]==1 && CNS_MGS_160Sa.point[i+1]==1 &&  flag==0)
		{
			Error=(( i - 7.5) +(( i + 1) - 7.5)) / 2.0;
			PID_Result=Kp * (Error - Error_last) + Ki * Error + Kd * (Error - 2 * Error_last + Error_next);    //得到增量
             Error_last = Error_next;      //进入下次迭代
     	 	 Error_next = Error;
		}
		else
			PID_Result = 0;
	}
	AGV_VL=AGV_Expect_Velocity.velocity+PID_Result;
	AGV_VR=AGV_Expect_Velocity.velocity-PID_Result;
}
void Movement_Control_Goback()//直行后退
{
	uint16_t i = 0,n=0,flag=0;
	float Error, PID_Result,Error_next, Error_last;

	for (i=0;i<16;i++)  //判断磁条上有多少个点检测到信号
	{
		if (CNS_MGS_160Sc.point[i]==1)
		{
			n = n + 1;
		}
	}
	if(n < 5)
	{
		flag = 0;
	}
	else
		flag = 1;

	if(n>1)
	{
		AGVMove_flag=1;
	}

	for (i=6;i<10;i++)
	{
		if(CNS_MGS_160Sc.point[i]==1 && CNS_MGS_160Sc.point[i+1]==1 &&  flag==0)
		{
			Error=(( i - 7.5) +(( i + 1) - 7.5)) / 2.0;
			PID_Result=Kp * (Error - Error_last) + Ki * Error + Kd * (Error - 2 * Error_last + Error_next);    //得到增量
             Error_last = Error_next;      //进入下次迭代
     	 	 Error_next = Error;
		}
		else
			PID_Result = 0;
	}
	AGV_VL=AGV_Expect_Velocity.velocity-PID_Result;
	AGV_VR=AGV_Expect_Velocity.velocity+PID_Result;
}

void Movement_Control_Left()//左岔路
{
	uint16_t i = 0,n=0;
	float Error, PID_Result,Error_next, Error_last;

	for (i=0;i<8;i++)
	{
		if (CNS_MGS_160Sa.point[i]==1)
				{
					n = n + 1;
				}
		if(CNS_MGS_160Sa.point[i]==1 && CNS_MGS_160Sa.point[i+1]==1)
		{
			Error=(( i - 7.5) +(( i + 1) - 7.5)) / 2.0;
			PID_Result = Kp * (Error - Error_last) + Ki * Error + Kd * (Error - 2 * Error_last + Error_next);    //得到增量
             Error_last = Error_next;      //进入下次迭代
     	 	 Error_next = Error;
		}
	}
	if(n>1)
	{
		AGVMove_flag=1;
	}

}

void Movement_Control_Right()//右岔路
{
	uint16_t i = 0,n=0;
	float Error, PID_Result,Error_next, Error_last;

	for (i=8;i<16;i++)
	{
		if (CNS_MGS_160Sa.point[i]==1)
				{
					n = n + 1;
				}
		if(CNS_MGS_160Sa.point[i]==1 && CNS_MGS_160Sa.point[i+1]==1)
		{
			Error=(( i - 7.5) +(( i + 1) - 7.5)) / 2.0;
			PID_Result=Kp * (Error - Error_last) + Ki * Error + Kd * (Error - 2 * Error_last + Error_next);    //得到增量
             Error_last = Error_next;      //进入下次迭代
     	 	 Error_next = Error;
		}
	}
	if(n>1)
	{
		AGVMove_flag=1;
	}
}
