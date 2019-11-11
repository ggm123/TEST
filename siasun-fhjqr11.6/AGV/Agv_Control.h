/*
 * Agv_Control.h
 *
 *  Created on: 2019-9-25
 *      Author: siasunhebo
 */

#ifndef AGV_CONTROL_H_
#define AGV_CONTROL_H_

//AGV状态定义
#define AGV_MODE_STANDBY     0    //待机模式
#define AGV_MODE_RUNNING     1    //运行模式
#define AGV_MODE_SUSPENDED   2    //挂起模式
#define AGV_MODE_OP          3    //操作模式



void AGV_Running();
void AGV_RUN();
void AGV_StandBy();
void AGV_Suspended();
void AGV_Op();



#endif /* AGV_CONTROL_H_ */
