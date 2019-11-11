/*
 * Reproducer_Lamplight.c
 *
 *  Created on: 2019-10-14
 *      Author: siasunhebo
 */
#include<SPC_SDIO_1616.h>
#include<agv.h>
#include<CNS_MGS_160S.h>
#include<main.h>
#include<Agv_Control.h>
#include<Motion_Ctrl.h>

 extern SPC_SDIO_1616_Data SPC_SDIO_1616a;
 extern Sound_Data Sound_Control_Data;
 extern Lamplight_Data Lamplight_Control_Data;
 extern  int Agv_Start_Flag;//AG启动标志位
 CNS_MGS_160S_t CNS_MGS_160Sa;
 CNS_MGS_160S_t CNS_MGS_160Sc;
 int AGV_On_Line;//AGV上线时标志位AGV_On__Line置1
 int AGV_On_Line_Control=1;
 extern uint16_t nAgvWorkMode;
 extern uint16_t Motionstyle;
 extern int Agv_Auto_Control_Flag;//自动控制标志位
 extern uint16_t nEvent;


void myprocess4()
{
	uint16_t i = 0,n=0,m=0,flag=0;
	for (i=0;i<16;i++)  //判断磁条上有多少个点检测到信号
		{
			if (CNS_MGS_160Sa.point[i]==1)
			{
				n++;
			}
			if (CNS_MGS_160Sc.point[i]==1)
			{
				m++;
			}

		}
			if(n < 5 && m<5)
			{
				if(n  > 1 && m>1)
					{
					  AGV_On_Line=1;
					}
				else
				{
					AGV_On_Line=0;
				}
			}
			else
			{
				AGV_On_Line=0;
			}
	if ( AGV_On_Line == 1 && AGV_On_Line_Control==1)//上线判断
	{
		Sound_Control_Data.Sound_Control[0]=1;
		usleep(200000);//计时200毫秒
		Sound_Control_Data.Sound_Control[0]=0;
		AGV_On_Line_Control=0;
	}
	if ( AGV_On_Line == 1 &&SPC_SDIO_1616a.point[15]==1)//到达上线点
	{
		Sound_Control_Data.Sound_Control[0]=1;
		Lamplight_Control_Data.Blue_Light=1;
		usleep(200000);//计时200毫秒
		Sound_Control_Data.Sound_Control[0]=0;
		Lamplight_Control_Data.Blue_Light=0;
	}
/**************************************
 * AGV自动寻线状态
 **************************************/
	if (Agv_Start_Flag == 1 &&  AGV_On_Line == 1 && nAgvWorkMode==AGV_MODE_RUNNING && (Motionstyle==MOTIONSTATE_GOSTRAIGHT
			||Motionstyle==MOTIONSTATE_TRUNLEFT ||Motionstyle==MOTIONSTATE_TRUNRIGHT||Motionstyle==MOTIONSTATE_GOBACKWARD )
			&&Agv_Auto_Control_Flag==1)
	{
		Sound_Control_Data.Sound_Control[1]=1;
		Lamplight_Control_Data.Green_Light=1;
		usleep(500000);
		Lamplight_Control_Data.Green_Light=0;
	}
  if (Agv_Start_Flag == 1 && nAgvWorkMode == AGV_MODE_OP )//AGV手动寻线状态
	{
		Sound_Control_Data.Sound_Control[2]=1;
		Lamplight_Control_Data.Blue_Light=1;
	}
	if (nEvent == GS_COMM_BREAK_EVENT || nEvent == OUT_OF_TRACK_EVENT  || nEvent ==  SERVO_INVALID_EVENT
			|| nEvent ==  CONTROL_RESUMABLE_STOP_EVENT || nEvent ==  WAY_POINT_ERROR )//报警状态
	{
		Sound_Control_Data.Sound_Control[3]=1;
		Lamplight_Control_Data.Red_Light=1;
		 usleep(500000);//计时500毫秒
		Sound_Control_Data.Sound_Control[3]=0;
		Lamplight_Control_Data.Red_Light=0;
	}
	if (nEvent == AGV_ARRIVE_DESTINATION)//到达目标点
	{
		Sound_Control_Data.Sound_Control[0]=1;
		Lamplight_Control_Data.Blue_Light=1;
		usleep(200000);//计时200毫秒
		Sound_Control_Data.Sound_Control[0]=0;
		Lamplight_Control_Data.Blue_Light=0;
	}

}





