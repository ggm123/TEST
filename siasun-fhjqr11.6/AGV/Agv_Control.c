/*
 * Agv_Control.c
 *
 *  Created on: 2019-9-25
 *      Author: siasunhebo
 */

#include <main.h>
#include <stdint.h>
#include "Agv_Control.h"
#include "agv.h"
#include "Motion_Ctrl.h"
#include <common.h>


uint16_t nEvent = NO_EVENT;    //当前所响应的事件
uint16_t nAgvWorkMode = AGV_MODE_STANDBY;
static uint16_t OutOfTrack = 0x00;    //脱轨，默认为不脱轨
static uint16_t GSMissing  = 0x00;    //导航信息丢失
extern uint16_t ethCommBreakFlag;
extern uint16_t Motionstyle;
 Velocity_Class_t Target_Velocity_InAGV;
uint16_t  Miss_flag;
extern uint16_t  AGVMove_flag;//判断是否检测到磁条
extern float  AGV_VL;
extern float  AGV_VR;
extern int AGV_On_Line;//AGV上线标志位
extern int Agv_Start_Flag;//AGV启动标志位


 void   AGV_RUN()
 {
	 switch (nAgvWorkMode)
	     {
	         case AGV_MODE_STANDBY:
	             AGV_StandBy();
	             break;
	         case AGV_MODE_RUNNING:
	             AGV_Running();
	             break;
	         case AGV_MODE_SUSPENDED:
	             AGV_Suspended();
	             break;
	         case AGV_MODE_OP:
	             AGV_Op();
	             break;
	         default:
	             break;
	     }

 }

 //待机操作函数
 void AGV_StandBy()
 {
	 AGV_VL=0.0;
	 AGV_VR=0.0;
	 if( AGV_On_Line == 1 && Agv_Start_Flag ==1)
	 {
		 nAgvWorkMode = AGV_MODE_RUNNING;
	 }
     //ToDo: 各状态及变量清零
 }

 //手动操作函数
 void AGV_Op()
 {

 }

 //挂起函数
 void AGV_Suspended()
 {
     //ToDo: 关掉驱动器使能，速度清零
	 AGV_VL=0.0;
	 AGV_VR=0.0;

     switch (nEvent)
     {
         case OUT_OF_TRACK_EVENT:      //如果脱轨，检查是否回归坐标点
         {
        	 AGV_VL=0.0;
        	 AGV_VR=0.0;

    	 	 if(AGVMove_flag==1)
    	 	 {
    	 		nEvent=0;
    	 		Miss_flag=0;
    	 		OutOfTrack = 0x00;
    	 	 }

             if (OutOfTrack == 0x00)
             {
                 nAgvWorkMode = AGV_MODE_RUNNING;
                 //ToDo: 速度等参数清零
             }
             break;
         }
         case GS_COMM_BREAK_EVENT:    //如果导航通讯中断
         {
             if (GSMissing == 0x00)
             {
                 nAgvWorkMode = AGV_MODE_RUNNING;
                 //ToDo: 速度等参数清零
             }
             break;
         }
         case CONTROL_RESUMABLE_STOP_EVENT:     //如果网络中断
         {
             if (ethCommBreakFlag == 0x00)
             {
                 nAgvWorkMode = AGV_MODE_RUNNING;
                 //ToDo: 速度等参数清零
             }
             break;
         }
         //驱动器
         case SERVO_INVALID_EVENT:            //如果伺服失效
         {
             //ToDo: 判断伺服是否恢复 速度等参数清零
             break;
         }
         default:
             break;
     }
 }


 void AGV_Running()
 {
     if (NO_EVENT == nEvent)
     {
         if (ethCommBreakFlag == 0x01)    //通讯中断
         {
             nEvent = CONTROL_RESUMABLE_STOP_EVENT;     //可恢复停车标志位
         }
         else if (OutOfTrack == 0x01)     //检查导航脱轨事件
         {
             nEvent = OUT_OF_TRACK_EVENT;
         }
         else if (GSMissing == 0x01)      //检查地标点是否丢失
         {
             nEvent = GS_COMM_BREAK_EVENT;
         }

         else
         {
 /*********************************************直行****************************************************/
             if (Motionstyle == ACTION_MODE_GOAHEAD)//前进
             {
                 Movement_Control_Goahead();
                 if ( Target_Velocity_InAGV.velocity>300)  //脱轨判定
                   {
                	 	 Miss_flag++;
                	 	 printf("Miss_flag=%d\n",Miss_flag);
                	 	 if(AGVMove_flag==1)
                	 	 {
                	 		Miss_flag=0;
                	 		OutOfTrack = 0x00;
                	 	 }
                	 	 if(Miss_flag>300)
                	 	 {
                	 		 Miss_flag = 0;
                	 		nEvent = 2;
                           OutOfTrack = 0x01;
                           nAgvWorkMode = AGV_MODE_SUSPENDED;
                	 	 }
                    }
             }
             else  if (Motionstyle == ACTION_MODE_GOBACK)//后退
                 {
						 Movement_Control_Goback();
						 if ( Target_Velocity_InAGV.velocity>300)  //脱轨判定
							  {
									 Miss_flag++;
									 printf("Miss_flag=%d\n",Miss_flag);
									 if(AGVMove_flag==1)
									 {
										Miss_flag=0;
										OutOfTrack = 0x00;
									 }
									 if(Miss_flag>300)
									 {
										 Miss_flag = 0;
										nEvent = 2;
										  OutOfTrack = 0x01;
										  nAgvWorkMode = AGV_MODE_SUSPENDED;
									 }
							   }
             }
 /********************************************左转******************************************************/
             else if (Motionstyle == ACTION_MODE_TRUNLEFT)
             {
            	 Movement_Control_Left();
				 if ( Target_Velocity_InAGV.velocity>300)  //脱轨判定
					  {
							 Miss_flag++;
							 printf("Miss_flag=%d\n",Miss_flag);
							 if(AGVMove_flag==1)
							 {
								Miss_flag=0;
								OutOfTrack = 0x00;
							 }
							 if(Miss_flag>300)
							 {
								 Miss_flag = 0;
								nEvent = 2;
								  OutOfTrack = 0x01;
								  nAgvWorkMode = AGV_MODE_SUSPENDED;
							 }
					   }

             }
 /********************************************右转******************************************************/
     else if (Motionstyle == ACTION_MODE_TRUNRIGHT)
             {
    	          Movement_Control_Right();

					 if ( Target_Velocity_InAGV.velocity>300)  //脱轨判定
						  {
								 Miss_flag++;
								 printf("Miss_flag=%d\n",Miss_flag);
								 if(AGVMove_flag==1)
								 {
									Miss_flag=0;
									OutOfTrack = 0x00;
								 }
								 if(Miss_flag>300)
								 {
									 Miss_flag = 0;
									nEvent = 2;
									  OutOfTrack = 0x01;
									  nAgvWorkMode = AGV_MODE_SUSPENDED;
								 }
						   }

             }
     else
     {
    	 AGV_VL=0.0;
    	 AGV_VR=0.0;
     }
         }
     }
     else if(nEvent == AGV_ARRIVE_DESTINATION)//到达终点,AGV进入挂起模式
     {
    	 AGV_Suspended();
     }
     else if (nEvent != NO_EVENT&&nEvent != AGV_ARRIVE_DESTINATION)
     {
         if ((nEvent == GS_COMM_BREAK_EVENT) && ((nEvent == ACTION_MODE_TRUNRIGHT) || (nEvent == ACTION_MODE_TRUNLEFT)))
         {
             Motionstyle = ACTION_MODE_STOP;
         }
         //恢复直行
         if ((nEvent == ACTION_MODE_GOAHEAD) || (nEvent == ACTION_MODE_GOBACK))
         {
             if (Miss_flag > 100 )  //脱轨判定
                  {
                        OutOfTrack = 0x01;
                  }
             //ToDo运动控制
         }

     }



 }
