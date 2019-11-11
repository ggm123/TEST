/*
 * agv.h
 *
 *  Created on: 2019-9-25
 *      Author: siasunhebo
 */

#ifndef AGV_H_
#define AGV_H_

//事件定义
#define NO_EVENT                           0    //没有事件
#define GS_COMM_BREAK_EVENT                1    //导航传感器通讯中断事件
#define OUT_OF_TRACK_EVENT                 2    //脱轨
#define SERVO_INVALID_EVENT                3    //伺服失效事件
#define CONTROL_RESUMABLE_STOP_EVENT       4    //网络通信中断停车事件
#define WAY_POINT_ERROR                    5    //路线点校验错误
#define BMS_COM_OUTOFTM                    6
#define AGV_ARRIVE_DESTINATION                    7  //到达目标点


void paramter_define();    //车辆参数定义
void Prase_Sensor_Data();  //传感器处理
void AGV_Movecontrol();       //车体运动控制
void get_PID();            //获取PID偏差值
void Go_Stralght();
void Go_Swerve();
void Paramter_Define();


#endif /* AGV_H_ */
