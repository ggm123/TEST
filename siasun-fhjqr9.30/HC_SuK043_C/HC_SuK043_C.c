/*
 * HC_SuK043_C.c
 *
 *  Created on: 2019-8-27
 *      Author: siasunggm
 */

#include <HC_SuK043_C.h>
#include <stdio.h>
#include <can.h>
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
#include <common.h>


typedef union
{
	 short AGV_Status;
	 __u8  AGV_Idata[1];
}AGV_Status_Data;

AGV_Status_Data AGV_Status_Data1;
AGV_Status_Data AGV_Status_Data2;
canBus_t *CAN0;
extern Coordinate_Class_t Current_Coor_InWorld;
extern Coordinate_Class_t  Destination_Coor_InWorld;
extern uint16_t  Go_Agv_flag0,Go_Agv_flag1,Go_Agv_flag2,Go_Agv_flag3;


 HC_SuK043_C_t HC_SuK043_C_Analyze_Data()
{
    int import0, import1,import2,import3,import4, import5,import6,import7;
    HC_SuK043_C_t HC_SuK043_C;
    import0 = (int)((short)(CAN0->recvBuffer.data[0]));
    import1 = (int)((short)(CAN0->recvBuffer.data[1]));
    import2 = (int)((short)(CAN0->recvBuffer.data[2]));
    import3 = (int)((short)(CAN0->recvBuffer.data[3]));
    import4 = (int)((short)(CAN0->recvBuffer.data[4]));
    import5 = (int)((short)(CAN0->recvBuffer.data[5]));
    import6 = (int)((short)(CAN0->recvBuffer.data[6]));
    import7 = (int)((short)(CAN0->recvBuffer.data[7]));
    HC_SuK043_C.import0 = import0+import1*256;
    HC_SuK043_C.import1 = import2+import3*256;
    HC_SuK043_C.import2 = import4+import5*256;
    HC_SuK043_C.import3 = import6+import7*256;
    printf("HC_SuK043_C_import0=%d\n", HC_SuK043_C.import0);
    printf("HC_SuK043_C_import1=%d\n", HC_SuK043_C.import1);
    printf("HC_SuK043_C_import2=%d\n", HC_SuK043_C.import2);
    printf("HC_SuK043_C_import3=%d\n", HC_SuK043_C.import3);

    Destination_Coor_InWorld.Landmark_Card_number = HC_SuK043_C.import2;

    return HC_SuK043_C;
}

void  HC_SuK043_C_CanSend_Data(canBus_t *can)
{
	AGV_Status_Data1.AGV_Status = Go_Agv_flag0||Go_Agv_flag1;
	AGV_Status_Data2.AGV_Status = Go_Agv_flag2||Go_Agv_flag3;
		can->sendBuffer.can_dlc = 8;
		can->sendBuffer.data[0] = AGV_Status_Data1.AGV_Idata[0];
		can->sendBuffer.data[1] = 0x00;
		can->sendBuffer.data[2] = AGV_Status_Data2.AGV_Idata[0];
		can->sendBuffer.data[3] = 0x00;
		can->sendBuffer.data[4] = 0x00;
		can->sendBuffer.data[5] = 0x11;
		can->sendBuffer.data[6] = 0x11;
		can->sendBuffer.data[7] = 0x11;
}
void Get_HC_SuK043_Data()
{

	Destination_Coor_InWorld.Landmark_Card_number ;
	Current_Coor_InWorld.Landmark_Card_number;

}

