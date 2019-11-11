/*
 * CNS_MGS_160S.c
 *
 *  Created on: 2019-8-26
 *      Author: siasunggm
 */

#include <CNS_MGS_160S.h>
#include <stdio.h>

 canBus_ta *CAN0;
 canBus_tb *CAN1;

CNS_MGS_160S_t CNS_MGS_160Sa_Analyze_Data()
{

    CNS_MGS_160S_t CNS_MGS_160Sa;

    CNS_MGS_160Sa.point[0] = CAN1->recvBuffer.data[0]&0x02;
    CNS_MGS_160Sa.point[1] = CAN1->recvBuffer.data[0]&0x04;
    CNS_MGS_160Sa.point[2] = CAN1->recvBuffer.data[0]&0x08;
    CNS_MGS_160Sa.point[3] = CAN1->recvBuffer.data[0]&0x10;
    CNS_MGS_160Sa.point[4] = CAN1->recvBuffer.data[0]&0x20;
    CNS_MGS_160Sa.point[5] = CAN1->recvBuffer.data[0]&0x40;
    CNS_MGS_160Sa.point[6] = CAN1->recvBuffer.data[0]&0x80;

    CNS_MGS_160Sa.point[7] = CAN1->recvBuffer.data[1]&0x01;
    CNS_MGS_160Sa.point[8] = CAN1->recvBuffer.data[1]&0x02;
    CNS_MGS_160Sa.point[9] = CAN1->recvBuffer.data[1]&0x04;
    CNS_MGS_160Sa.point[10] = CAN1->recvBuffer.data[1]&0x08;
    CNS_MGS_160Sa.point[11] = CAN1->recvBuffer.data[1]&0x10;
    CNS_MGS_160Sa.point[12] = CAN1->recvBuffer.data[1]&0x20;
    CNS_MGS_160Sa.point[13] = CAN1->recvBuffer.data[1]&0x40;
    CNS_MGS_160Sa.point[14] = CAN1->recvBuffer.data[1]&0x80;

    CNS_MGS_160Sa.point[15] = CAN1->recvBuffer.data[2]&0x01;

    return CNS_MGS_160Sa;
}
CNS_MGS_160S_t CNS_MGS_160Sc_Analyze_Data()
{
    CNS_MGS_160S_t  CNS_MGS_160Sc;
    CNS_MGS_160Sc.point[0] = CAN0->recvBuffer.data[0]&0x02;
    CNS_MGS_160Sc.point[1] = CAN0->recvBuffer.data[0]&0x04;
    CNS_MGS_160Sc.point[2] = CAN0->recvBuffer.data[0]&0x08;
    CNS_MGS_160Sc.point[3] = CAN0->recvBuffer.data[0]&0x10;
    CNS_MGS_160Sc.point[4] = CAN0->recvBuffer.data[0]&0x20;
    CNS_MGS_160Sc.point[5] = CAN0->recvBuffer.data[0]&0x40;
    CNS_MGS_160Sc.point[6] = CAN0->recvBuffer.data[0]&0x80;

    CNS_MGS_160Sc.point[7] = CAN0->recvBuffer.data[1]&0x01;
    CNS_MGS_160Sc.point[8] = CAN0->recvBuffer.data[1]&0x02;
    CNS_MGS_160Sc.point[9] = CAN0->recvBuffer.data[1]&0x04;
    CNS_MGS_160Sc.point[10] = CAN0->recvBuffer.data[1]&0x08;
    CNS_MGS_160Sc.point[11] = CAN0->recvBuffer.data[1]&0x10;
    CNS_MGS_160Sc.point[12] = CAN0->recvBuffer.data[1]&0x20;
    CNS_MGS_160Sc.point[13] = CAN0->recvBuffer.data[1]&0x40;
    CNS_MGS_160Sc.point[14] = CAN0->recvBuffer.data[1]&0x80;

    CNS_MGS_160Sc.point[15] = CAN0->recvBuffer.data[2]&0x01;


    return CNS_MGS_160Sc;
}



