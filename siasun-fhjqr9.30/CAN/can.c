/*
 * can.c
 *
 *  Created on: Aug 24, 2019
 *      Author: siasunggm
 */

#include <can.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <linux/socket.h>
#include <linux/can.h>
#include <linux/can/error.h>
#include <linux/can/raw.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <CNS_MGS_160S.h>
#include <SPC_SDIO_1616.h>
#include <CNS_RFID_1S.h>
#include <FD123_CA_000.h>
#include <HC_SuK043_C.h>
#include <common.h>


#define errout(_s)	fprintf(stderr, "error class: %s\n", (_s))
#define errcode(_d) fprintf(stderr, "error code: %02x\n", (_d))


typedef union
{
	 short AGV_Velocity;
	 __u8  AGV_Idata[1];
}AGV_Velocity_Data;



AGV_Velocity_Data Transform_Velocity_Data;
AGV_Velocity_Data Transform_Velocity_Data1;
AGV_Velocity_Data Transform_Velocity_Data2;
AGV_Velocity_Data Transform_Velocity_Data3;
canBus_t *CAN0;
canBus_t *CAN1;
CNS_MGS_160S_t POINT0,POINT1;
CNS_RFID_1S_t POINTa;
FD123_CA_000_t POINTb;
HC_SuK043_C_t POINTc;
int motor_model_flag1=1,motor_model_flag2=1;//电机驱动模式
int motor_node_flag1=1,motor_node_flag2=1;
extern float AGV_VL;
extern float AGV_VR;
extern wheel_paramter_t wheelParamter;

extern AGV_SDIO_Data SPC_SDIO_1616_Outa;
extern AGV_SDIO_Data SPC_SDIO_1616_Outc;
struct timeval timeout;
int SPC_SDIO_1616_Outa_flag;
int SPC_SDIO_1616_Outb_flag;


void CAN_init()
{
	CAN0 = CanBusInit("can0");       //init can
	//CAN1 = CanBusInit("can1");       //init can
}

static void handle_err_frame(const struct can_frame *fr) {
	if (fr->can_id & CAN_ERR_TX_TIMEOUT) {
		errout("CAN_ERR_TX_TIMEOUT");
		printf("发送超时");
	}
	if (fr->can_id & CAN_ERR_LOSTARB) {
		errout("CAN_ERR_LOSTARB");
		printf("总线仲裁错误");
		errcode(fr->data[0]);
	}
	if (fr->can_id & CAN_ERR_CRTL) {
		if (fr->data && fr->can_dlc >= 2) {
			switch (fr->data[1]) {
			case CAN_ERR_CRTL_RX_OVERFLOW:
				printf("接收缓存溢出");
				break;
			case CAN_ERR_CRTL_TX_OVERFLOW:
				printf("发送缓存溢出");
				break;
			case CAN_ERR_CRTL_RX_WARNING:
				printf("接收报警");
				break;
			case CAN_ERR_CRTL_TX_WARNING:
				printf("发送报警");
				break;
			case CAN_ERR_CRTL_RX_PASSIVE:
				printf("接收被动错误");
				break;
			case CAN_ERR_CRTL_TX_PASSIVE:
				printf("发送被动错误");
				break;
			}
			errout("CAN_ERR_CRTL");
			errcode(fr->data[1]);
		} else
			errout("CAN_ERR_CRTL");
		printf("CAN控制器错误");
		errcode(fr->data[1]);
	}
	if (fr->can_id & CAN_ERR_PROT) {
		if (fr->data && fr->can_dlc >= 4) {
			switch (fr->data[2]) {
			case CAN_ERR_PROT_BIT:
				printf("位错误");
				break;
			case CAN_ERR_PROT_FORM:
				printf("帧格式错误");
				break;
			case CAN_ERR_PROT_STUFF:
				printf("位填充错误");
				break;
			case CAN_ERR_PROT_BIT0:
				printf("(接收站)不能发送占有位(dominant bit)");
				break;
			case CAN_ERR_PROT_BIT1:
				printf("(发送站)不能发送空闲位(recessive bit)");
				break;
			case CAN_ERR_PROT_OVERLOAD:
				printf("总线超负荷");
				break;
			case CAN_ERR_PROT_ACTIVE:
				printf("主动错误");
				break;
			case CAN_ERR_PROT_TX:
				printf("传输错误");
				break;
			}
			errout("CAN_ERR_CRTL");
			errcode(fr->data[2]);
		} else {
			printf("协议违反");
			errout("CAN_ERR_PROT");
			errcode(fr->data[3]);
		}
	}
	if (fr->can_id & CAN_ERR_TRX) {
		errout("CAN_ERR_TRX");
		errcode(fr->data[4]);
	}
	if (fr->can_id & CAN_ERR_ACK) {
		printf("应答错误");
		errout("CAN_ERR_ACK");
	}
	if (fr->can_id & CAN_ERR_BUSOFF) {
		printf("总线关闭");
		errout("CAN_ERR_BUSOFF");
	}
	if (fr->can_id & CAN_ERR_BUSERROR) {
		printf("总线错误(可能溢出)");
		errout("CAN_ERR_BUSERROR");
	}
	if (fr->can_id & CAN_ERR_RESTARTED) {
		printf("CAN控制器重启");
		errout("CAN_ERR_RESTARTED");
	}
}
#define myerr(str)	fprintf(stderr, "%s, %s, %d: %s\n", __FILE__, __func__, __LINE__, str)

void print_frame(struct can_frame *fr) {
	int i;
	printf("%08x\n", fr->can_id & CAN_EFF_MASK);
	//printf("%08x\n", fr->can_id);
	printf("dlc = %d\n", fr->can_dlc);
	printf("data = ");
	for (i = 0; i < fr->can_dlc; i++)
		printf("%02x ", fr->data[i]);
	printf("\n");
}

/*
 canbus初始化函数
 char *interface：can设备接口名
 canBus_t * ：返回的canbus结构体
 */
canBus_t *CanBusInit(char *interface)
{
	int ret;
	canBus_t *canbus_ptr = (canBus_t *) malloc(sizeof(canBus_t));
	memset(canbus_ptr, 0, sizeof(canBus_t));
	pthread_mutex_init(&canbus_ptr->rdwrLock, NULL);
	struct sockaddr_can addr;
	struct ifreq ifr;
	if ((canbus_ptr->canFd = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) //创建 SocketCAN 套接字
			{
		printf("socket err!\n");
	}
	strcpy(ifr.ifr_name, interface);
	if (-1 == (ioctl(canbus_ptr->canFd, SIOCGIFINDEX, &ifr))) //指定 can设备
			{
		printf("ioctl err!\n");
	}

	strncpy(ifr.ifr_name, interface, IFNAMSIZ - 1); //将接口传递给ifr
	ifr.ifr_name[IFNAMSIZ - 1] = '\0';
	ifr.ifr_ifindex = if_nametoindex(ifr.ifr_name); //检查接口是否真的存在
	if (!ifr.ifr_ifindex) {
		perror("if_nametoindex");
		return 0;
	}
	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	if ((bind(canbus_ptr->canFd, (struct sockaddr*) &addr, sizeof(addr))) < 0) //将套接字与 can0 绑定
			{
		printf("bind err!\n");
	}
	/*if (1)	 //设置过滤规则
	{
		struct can_filter filter[8];
	filter[0].can_id = 0x03 | CAN_EFF_FLAG;
	filter[0].can_mask = 0xFFFF;  //第 1 个规则是可以接收 ID 为 0x03 & 0xFFFF 的数据帧
	filter[1].can_id = 0x04 | CAN_EFF_FLAG;
	filter[1].can_mask = 0xFFFF; //第 2 个规则是可以接收 ID 为 0x04 & 0xFFFF 的数据帧
	filter[2].can_id = 0x06 | CAN_EFF_FLAG;
	filter[2].can_mask = 0xFFFF;  //第 1 个规则是可以接收 ID 为 0x06 & 0xFFFF 的数据帧
	filter[3].can_id = 0x08 | CAN_EFF_FLAG;
	filter[3].can_mask = 0xFFFF; // 第 2 个规则是可以接收 ID 为 0x08 & 0xFFFF 的数据帧
	filter[4].can_id = 0x188 | CAN_EFF_FLAG;
	filter[4].can_mask = 0xFFFF;  // 第 1 个规则是可以接收 ID 为 0x188 & 0xFFFF 的数据帧
	filter[5].can_id = 0x189 | CAN_EFF_FLAG;
	filter[5].can_mask = 0xFFFF; //第 2 个规则是可以接收 ID 为 0x189 & 0xFFFF 的数据帧
	filter[6].can_id = 0x301| CAN_EFF_FLAG;
    filter[6].can_mask = 0xFFFF;  // 第 1 个规则是可以接收 ID 为 0x301 & 0xFFFF 的数据帧
	filter[7].can_id = 0x302| CAN_EFF_FLAG;
	filter[7].can_mask = 0xFFFF; // 第 2 个规则是可以接收 ID 为 0x302 & 0xFFFF 的数据帧
	ret = setsockopt(canbus_ptr->canFd, SOL_CAN_RAW, CAN_RAW_FILTER, &filter, sizeof(filter));   //启用过滤规则，只要 CAN0 接收到的数据帧满足上面 2 个规则中的任何一个也被接受
	if (ret < 0)
	{
		perror("setsockopt failed");
		return 0;
	}
	}*/
	return canbus_ptr;
}

/*
 can设备发送线程
 */
void CanSendThreada(canBus_t *can)
{
	int ret;

	if (can->sendBuffer.can_id == 0x04)
	 {
	  can->sendBuffer.can_id = 0x07; //发送至显示屏显示
	  HC_SuK043_C_CanSend_Data(CAN0);
	}
	/*else if (can->sendBuffer.can_id == 0x07) //远程IO
		{
		if(SPC_SDIO_1616_Outa_flag==0)
		{
			SPC_SDIO_1616_Outa_flag=1;
			can->sendBuffer.can_id = 0x608;
			can->sendBuffer.can_dlc = 8;
			can->sendBuffer.data[0] = 0x23;
			can->sendBuffer.data[1] = 0x08;
			can->sendBuffer.data[2] = 0x62;
			can->sendBuffer.data[3] = 0x00;
			can->sendBuffer.data[4] = 0x00;
			can->sendBuffer.data[5] = 0xFF;
			can->sendBuffer.data[6] = 0XFF;
			can->sendBuffer.data[7] = 0X00;
		}
		else
		{
			can->sendBuffer.can_id = 0x208;
			can->sendBuffer.can_dlc = 04;
			can->sendBuffer.data[0] = SPC_SDIO_1616_Outa.SDIO_Idata[0];
			can->sendBuffer.data[1] = SPC_SDIO_1616_Outa.SDIO_Idata[1];
			can->sendBuffer.data[2] = SPC_SDIO_1616_Outa.SDIO_Idata[2];
			can->sendBuffer.data[3] = SPC_SDIO_1616_Outa.SDIO_Idata[3];
		}
	}
	else if(can->sendBuffer.can_id==0x208)
	 {
		if(SPC_SDIO_1616_Outb_flag==0)
		{
			SPC_SDIO_1616_Outb_flag=1;
			can->sendBuffer.can_id = 0x609;
			can->sendBuffer.can_dlc = 8;
			can->sendBuffer.data[0] = 0x23;
			can->sendBuffer.data[1] = 0x08;
			can->sendBuffer.data[2] = 0x62;
			can->sendBuffer.data[3] = 0x00;
			can->sendBuffer.data[4] = 0x00;
			can->sendBuffer.data[5] = 0xFF;
			can->sendBuffer.data[6] = 0XFF;
			can->sendBuffer.data[7] = 0X00;
		}
		else
		{
			 can->sendBuffer.can_id = 0x209;//远程IO
			 can->sendBuffer.can_dlc = 04;
			 can->sendBuffer.data[0] = SPC_SDIO_1616_Outc.SDIO_Idata[0];
			 can->sendBuffer.data[1] = SPC_SDIO_1616_Outc.SDIO_Idata[1];
			 can->sendBuffer.data[2] = SPC_SDIO_1616_Outc.SDIO_Idata[2];
			 can->sendBuffer.data[3] = SPC_SDIO_1616_Outc.SDIO_Idata[3];
		}
	 }*/
	 else //轮循读后磁条传感器0
	{
		can->sendBuffer.can_id = 0x04;
		can->sendBuffer.can_dlc = 01;
		can->sendBuffer.data[0] = 0x88;
	}
	ret = write(can->canFd, &can->sendBuffer, sizeof(struct can_frame));
	if (ret != sizeof(can->sendBuffer))
	{
		printf("Send Error can->sendBuffer\n!"); //发送错误
	}
	else
		printf("send thread done!\n");
	// usleep(50);

}

void CanSendThreadb(canBus_t *can)
{
	int ret,AGV_VL_a,AGV_VR_a;
	AGV_VL_a = (int)(AGV_VL*60*wheelParamter.REDUCATION_RATIO/M_PI/wheelParamter.WHEEL_DIAMETER);//电机转速
	Transform_Velocity_Data.AGV_Velocity = (short)((AGV_VL_a-((int)(AGV_VL_a/24))*24)/0.09375);
	Transform_Velocity_Data1.AGV_Velocity = (short)(AGV_VL_a/24);

	AGV_VR_a = (int)(AGV_VR*60*wheelParamter.REDUCATION_RATIO/M_PI/wheelParamter.WHEEL_DIAMETER);//电机转速
	Transform_Velocity_Data2.AGV_Velocity = (short)((AGV_VR_a-((int)(AGV_VR_a/24))*24)/0.09375);
	Transform_Velocity_Data3.AGV_Velocity = (short)(AGV_VR_a/24);

	if( motor_node_flag1 )//开启电机电机节点地址5
		 {
	  	       motor_node_flag1=0;
			 can->sendBuffer.can_id = 0x0;
			 can->sendBuffer.can_dlc = 02;
			 can->sendBuffer.data[0] = 0x01;
			 can->sendBuffer.data[1] = 0x05;
			 printf("12\n");
		 }
   else  if(motor_model_flag1)//选择电机1驱动模式，3：速度控制模式；1：位置控制模式；6：原点控制模式
		 {
			  motor_model_flag1=0;
			 can->sendBuffer.can_id = 0x202;
			 can->sendBuffer.can_dlc =01;
			 can->sendBuffer.data[0] = 0x03;
			 printf("56\n");
		 }
	 else  if( motor_node_flag2 )//开启电机电机节点地址6
	 {
	     motor_node_flag2=0;
		 can->sendBuffer.can_id = 0x0;
		 can->sendBuffer.can_dlc = 02;
		 can->sendBuffer.data[0] = 0x01;
		 can->sendBuffer.data[1] = 0x06;
		 printf("34\n");
	 }
		  else  if(motor_model_flag2)//选择电机2驱动模式，3：速度控制模式；1：位置控制模式；6：原点控制模式
		 {
			  motor_model_flag2=0;
			 can->sendBuffer.can_id = 0x204;
			 can->sendBuffer.can_dlc =01;
			 can->sendBuffer.data[0] = 0x03;
			 printf("78\n");
		 }
		  else{
					if (can->sendBuffer.can_id == 0x03)
						{
							can->sendBuffer.can_id = 0x08;//轮循RFID传感器
							can->sendBuffer.can_dlc = 4;
							can->sendBuffer.data[0] = 0x00;
							can->sendBuffer.data[1] = 0x00;
							can->sendBuffer.data[2] = 0x00;
							can->sendBuffer.data[3] = 0x00;
						}
					else if(can->sendBuffer.can_id==0x08)
						 {
						 can->sendBuffer.can_id = 0x201;//驱动器1从车头看是右轮
							can->sendBuffer.can_dlc = 06;
						   can->sendBuffer.data[0] = 0x0F;//锁轴F松轴6
					    	can->sendBuffer.data[1] = 0x00;
							can->sendBuffer.data[2] = 0x00;
							 can->sendBuffer.data[3] = 0x40;//Transform_Velocity_Data.AGV_Idata[0]; //每增加1转速增加0.09375r/min  40 06=150r/min
							 can->sendBuffer.data[4] = 0x06;//Transform_Velocity_Data1.AGV_Idata[0];//每增加1转速增加24r/min
							can->sendBuffer.data[5] = 0x00;
					 }
					else if(can->sendBuffer.can_id==0x201)
						 {
							 can->sendBuffer.can_id = 0x203;//驱动器2从车头看是左轮
							 can->sendBuffer.can_dlc = 06;
							 can->sendBuffer.data[0] = 0x0F;
							 can->sendBuffer.data[1] = 0x00;
							can->sendBuffer.data[2] = 0x00;
							 can->sendBuffer.data[3] = 0x40;//Transform_Velocity_Data2.AGV_Idata[0]; //每增加1转速增加0.09375r/min  40 06=150r/min
							 can->sendBuffer.data[4] = 0x06;//Transform_Velocity_Data3.AGV_Idata[0];//每增加1转速增加24r/min
							can->sendBuffer.data[5] = 0x00;
						 }
					else
					{
						can->sendBuffer.can_id = 0x03;//轮循读前磁条传感器
						can->sendBuffer.can_dlc = 01;
						can->sendBuffer.data[0] = 0x88;
					}
	   }
	ret = write(can->canFd, &can->sendBuffer, sizeof(struct can_frame));
	if (ret != sizeof(can->sendBuffer))
	{
		printf("Send Error can->sendBuffer\n!"); //发送错误
	}
	else
		printf("send thread done!\n");
}

/*
 can设备接收
 */
void CanRecvThread(canBus_t *can)
{
	int nbytes;
	int ret;
	struct timeval tv;
	fd_set rset;
	 timeout.tv_sec=0;
	 timeout.tv_usec=100000;//微妙

	FD_ZERO(&rset);
	FD_SET(can->canFd, &rset);

	printf("this is can select\n");
	ret = select(can->canFd + 1, &rset, NULL, NULL, &timeout);//ret = select(can->canFd + 1, &rset, NULL, NULL, NULL);//非阻塞式
	if (ret == 0)
	{
	    myerr("select time out");
		return ;
	}
	nbytes = read(can->canFd, &can->recvBuffer, sizeof(struct can_frame));
	printf("this is can read\n");
	if (can->recvBuffer.can_id & CAN_ERR_FLAG) //出错设备错误
	{
		handle_err_frame(&can->recvBuffer);
		myerr("CAN device error");
		return ;
	}
}
void * myprocess0 (void *arg)//线程0  can0接收
{
	 if(CAN0->recvBuffer.can_id==0x04)
		 {
			POINT0 = CNS_MGS_160Sc_Analyze_Data(); //解析后磁条传感器
			 usleep(50);
		 }
	  if(CAN0->recvBuffer.can_id==0x06)//解析显示屏
	 	 {
	        POINTc = HC_SuK043_C_Analyze_Data();
	 	 }
	if(CAN0->recvBuffer.can_id==0x188)//解析远程IO0
	{
		SPC_SDIO_1616a_Analyze_Data();
	 }
	if(CAN0->recvBuffer.can_id==0x189)//解析远程IO1
   {
		SPC_SDIO_1616c_Analyze_Data();
	}
    return NULL;
}

void * myprocess1(void *arg)//线程1  can1接收
{
	if(CAN1->recvBuffer.can_id==0x03)
	 {
		 POINT1 = CNS_MGS_160Sa_Analyze_Data(); //解析前磁条传感器
		 usleep(50);
	 }
	if(CAN1->recvBuffer.can_id==0x08)//解析RFID
		 {
			 POINTa = CNS_RFID_1S_Analyze_Data();
		 }
	if(CAN1->recvBuffer.can_id==0x301)//解析电机0
		 {
			 POINTb= FD123_CA_000a_Analyze_Data();
		 }
	if(CAN1->recvBuffer.can_id==0x302)//解析电机1
		 {
			 POINTb= FD123_CA_000b_Analyze_Data();
		 }
	 return NULL;
}

void * myprocess2(void *arg)//线程2
{
	  CanSendThreada(CAN0);//CAN0发送
   //  CanSendThreadb(CAN1);//CAN1发送
      return NULL;
}

void * myprocess5 (void *arg)
{
	  return NULL;
}


