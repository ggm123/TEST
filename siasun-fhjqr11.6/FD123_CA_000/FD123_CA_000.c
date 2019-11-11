/*
 * FD123_CA_000.c
 *
 *  Created on: 2019-8-27
 *      Author: siasunggm
 */

#include <FD123_CA_000.h>
#include <stdio.h>
canBus_tb *CAN1;

FD123_CA_000_t FD123_CA_000a_Analyze_Data()
{
   int  import0, import1,import2,import3;
    FD123_CA_000_t FD123_CA_000a;
    import0 = (int)((short)(CAN1->recvBuffer.data[0]));
    import1 = (int)((short)(CAN1->recvBuffer.data[1]));
    import2 = (int)((short)(CAN1->recvBuffer.data[2]));
    import3 = (int)((short)(CAN1->recvBuffer.data[3]));
    FD123_CA_000a.import0 = import0;
    FD123_CA_000a.import1 = import1;
    FD123_CA_000a.import2 = import2;
    FD123_CA_000a.import3 = import3;
    printf("FD123_CA_000a_import0=%d\n", import0);
    printf("FD123_CA_000a_import1=%d\n", import1);
    printf("FD123_CA_000a_import2=%d\n", import2);
    printf("FD123_CA_000a_import3=%d\n", import3);
    return FD123_CA_000a;
}
FD123_CA_000_t FD123_CA_000b_Analyze_Data()
{
   int  import0, import1,import2,import3;
    FD123_CA_000_t FD123_CA_000b;
    import0 = (int)((short)(CAN1->recvBuffer.data[0]));
    import1 = (int)((short)(CAN1->recvBuffer.data[1]));
    import2 = (int)((short)(CAN1->recvBuffer.data[2]));
    import3 = (int)((short)(CAN1->recvBuffer.data[3]));
    FD123_CA_000b.import0 = import0;
    FD123_CA_000b.import1 = import1;
    FD123_CA_000b.import2 = import2;
    FD123_CA_000b.import3 = import3;
    printf("FD123_CA_000b_import0=%d\n", import0);
    printf("FD123_CA_000b_import1=%d\n", import1);
    printf("FD123_CA_000b_import2=%d\n", import2);
    printf("FD123_CA_000b_import3=%d\n", import3);
    return FD123_CA_000b;
}


