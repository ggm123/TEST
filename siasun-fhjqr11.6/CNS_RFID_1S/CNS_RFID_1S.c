/*
 * CNS_RFID_1S.C
 *
 *  Created on: 2019-8-27
 *      Author: siasunggm
 */

#include <CNS_RFID_1S.h>
#include <stdio.h>

 canBus_tb *CAN1;

 CNS_RFID_1S_t CNS_RFID_1S_Analyze_Data()
{
    int  import0, import1,import2,import3,import4, import5,import6,import7,flag1,flag2, flag3;
    CNS_RFID_1S_t CNS_RFID_1S;
    import0 = (int)((short)(CAN1->recvBuffer.data[0]));
    import1 = (int)((short)(CAN1->recvBuffer.data[1]));
    import2 = (int)((short)(CAN1->recvBuffer.data[2]));
    import3 = (int)((short)(CAN1->recvBuffer.data[3]));
    import4 = (int)((short)(CAN1->recvBuffer.data[4]));
    import5 = (int)((short)(CAN1->recvBuffer.data[5]));
    import6 = (int)((short)(CAN1->recvBuffer.data[6]));
    import7 = (int)((short)(CAN1->recvBuffer.data[7]));
    flag1 =  import0;
    flag2 =  import2;
    flag3 =  import3;
    if(flag1 == 1)
    {
    	if(flag2 == 1)
    	{
    		if(flag3 >= 2)
    		{
				CNS_RFID_1S.import0 = import4;//位置标记
				CNS_RFID_1S.import1 = import5;//前进
				CNS_RFID_1S.import2 = import6;//后退
				CNS_RFID_1S.import3 = import7;//左转
				printf("CNS_RFID_1S_import0=%d\n",CNS_RFID_1S. import0);
				printf("CNS_RFID_1S_import1=%d\n", CNS_RFID_1S.import1);
				printf("CNS_RFID_1S_import2=%d\n",CNS_RFID_1S. import2);
				printf("CNS_RFID_1S_import3=%d\n", CNS_RFID_1S.import3);
    		}
    		else
    			printf("磁场强度太弱");
    	}
    	else
    		printf("未读到磁卡");
    }
    if (flag1 == 2)
    {
    	if(flag2 == 1)
    	{
    		if(flag3 >= 2)
    		{
				CNS_RFID_1S.import4 = import4;//右转
				printf("CNS_RFID_1S_import4=%d\n",CNS_RFID_1S.import4);
    		}
    		else
    			printf("磁场强度太弱");
    	}
    	else
    		printf("未读到磁卡");
    }
    return CNS_RFID_1S;
}



