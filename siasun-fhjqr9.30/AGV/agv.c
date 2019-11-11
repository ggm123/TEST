/*
 * agv.c
 *
 *  Created on: 2019-9-25
 *      Author: siasunhebo
 */

#include <main.h>
#include <common.h>
#include <Agv_Control.h>
#include <Motion_Ctrl.h>
#include <CNS_RFID_1S.h>
#include <SPC_SDIO_1616.h>
#include <agv.h>

 Coordinate_Class_t Destination_Coor_InWorld;
 Coordinate_Class_t Current_Coor_InWorld;
 uint16_t  Go_Agv_flag0,Go_Agv_flag1,Go_Agv_flag2,Go_Agv_flag3;
  extern  uint16_t Motionstyle;
  int Agv_Start_Flag;//AGV启动标志位
  int Agv_Start_i;
  int Agv_Auto_Control_Flag;//自动控制标志位
  extern Velocity_Class_t AGV_Expect_Velocity;
  wheel_paramter_t wheelParamter;
  CNS_RFID_1S_t CNS_RFID_1S;
  extern SPC_SDIO_1616_Data SPC_SDIO_1616c;
  extern Velocity_Class_t AGV_Expect_Velocity;
  extern  SPC_SDIO_1616_Data SPC_SDIO_1616a;
  extern uint16_t nAgvWorkMode;
 extern  uint16_t nEvent;

  void Paramter_Define()
  {
	    wheelParamter.line_slowest_time = 0.63;
	    wheelParamter.motor_max_rotationl_velocity_soft = 2800.0;
	    wheelParamter.motor_min_rotationl_velocity_soft = 50.0;
	    wheelParamter.WHEEL_DIAMETER = 150.0;
	    wheelParamter.REDUCATION_RATIO = 25.0;
	    wheelParamter.wheel_acceleration_time = 0.6366;
		AGV_Expect_Velocity.velocity=300.0;//AGV线速度300mm/s
  }


void Prase_Sensor_Data()
{
	if(SPC_SDIO_1616c.point[3] == 1||SPC_SDIO_1616c.point[25] == 1)//PLS远距离检测到障碍
	{
		//To Do报警提示
	}
	else if(SPC_SDIO_1616c.point[2] == 1||SPC_SDIO_1616c.point[24] == 1)//PLS中距离检测到障碍
	{
		AGV_Expect_Velocity.velocity=100.0;//降速
	}

}

void Go_Stralght()
{
	if (Go_Agv_flag0 == 1)
	{
		Motionstyle = ACTION_MODE_GOAHEAD;
	}
	if (Go_Agv_flag1 == 1)
	{
		Motionstyle = ACTION_MODE_GOBACK;
	}
}

void Go_Swerve()
{
	if (Go_Agv_flag2 == 1)
	{
		Motionstyle = MOTIONSTATE_TRUNLEFT;
	}
	if (Go_Agv_flag3 == 1)
	{
		Motionstyle = MOTIONSTATE_TRUNRIGHT;
	}
}

void AGV_Movecontrol()
{
	if(SPC_SDIO_1616a.point[12] == 1)//拍下急停 控制器进入待机状态
	{
		nAgvWorkMode = AGV_MODE_STANDBY;
		Agv_Start_Flag = 0;
	}
	if(SPC_SDIO_1616a.point[15]==2)//地标传感器 检测到目标点
	{
		nEvent = AGV_ARRIVE_DESTINATION;
	}
	if (SPC_SDIO_1616a.point[0] == 1 && Agv_Start_Flag == 0)//AGV启动控制
	{
		Agv_Start_i++;
		if(Agv_Start_i > 200)//常按启动按钮500ms后启动
		{
			Agv_Start_i=0;
		    Agv_Start_Flag = 1;
		    nAgvWorkMode=AGV_MODE_STANDBY;
		}
	}
	if (SPC_SDIO_1616a.point[2] == 1)//AGV自动控制
	{
		Agv_Auto_Control_Flag = 1;
	}
	else if(SPC_SDIO_1616a.point[3] == 1)//AGV手动控制
	{
		nAgvWorkMode = AGV_MODE_OP;
	}

	if((Destination_Coor_InWorld.Landmark_Card_number != Current_Coor_InWorld.Landmark_Card_number) &&  Agv_Start_Flag==1&&Agv_Auto_Control_Flag)
	{
		Go_Agv_flag0=CNS_RFID_1S.import1; //RFID传感器读到直行数据赋值给变量Go_Agv_flag0
		Go_Agv_flag2=CNS_RFID_1S.import3; //RFID传感器读到左转数据赋值给变量Go_Agv_flag2

		if (Go_Agv_flag0 == 1 ||  Go_Agv_flag1 == 1)
		{
			  Go_Stralght(); //直行
		}
		else if(Go_Agv_flag2== 1 ||  Go_Agv_flag3 == 1)
		{
			  Go_Swerve(); //转弯
		}
		else
			AGV_Suspended();
	}
	else
	{
		AGV_Suspended();
	}
}
