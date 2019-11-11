/*
 * can.h
 *
 *  Created on: Aug 24, 2019
 *      Author: siasunggm
 */

#ifndef CAN_H_
#define CAN_H_

#include <linux/can.h>      //sockaddr_can
#include <sys/socket.h>     //PF_CAN SOCK_RAW
#include <net/if.h>         //struct ifreq
#include <sys/ioctl.h>      //SI
#include <pthread.h>
//#include <Timer.h>

typedef struct canBusElema{
    int canFd;                      //can设备句柄
    struct can_frame sendBuffer;    //can设备发送buffer
    struct can_frame recvBuffer;    //can设备接收buffer
    pthread_mutex_t  rdwrLocka;      //can设备发送读取互斥锁
}canBus_ta;

typedef struct canBusElemb{
    int canFd;                      //can设备句柄
    struct can_frame sendBuffer;    //can设备发送buffer
    struct can_frame recvBuffer;    //can设备接收buffer
    pthread_mutex_t  rdwrLockb;      //can设备发送读取互斥锁
}canBus_tb;



typedef struct canbuscmd{
    int show;
    int record;
    int loopback;
    char *interface;
}canbuscmd_t;


typedef struct taskArg{
    canBus_ta * can0;
    canBus_tb * can1;
    unsigned int boId;
}taskArg_t;


typedef struct TaskAdd{
    void(*task)(taskArg_t *);
	//void(*task)(taskArg_t *);
    int canID;
    taskArg_t arg;
}TaskAdd_t;

void CAN_init();

canBus_ta * CanBusInita(char *interface);
canBus_tb * CanBusInitb(char *interface);

void CanRecvThreada(canBus_ta *can);
void CanRecvThreadb(canBus_tb *can);

void CanSendThreada(canBus_ta *can);
void CanSendThreadb(canBus_tb *can);

//void CanSendThread(taskArg_t *arg);
void print_frame(struct can_frame *fr);


#endif /* CAN_H_ */
