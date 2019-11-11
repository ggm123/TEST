//
// Created by siasunhebo on 19-8-29.
//

#include <TCP.h>
#include <stdio.h>
#include <pthread.h>
#include <net.h>
#include <buffer.h>
#include <protocol.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<cJSON_User.h>

struct Buffer buf;
int Flag_Tcp0;

extern char buffer[8];  //发送电台数组
char *De_Serialize_Data;
char *Serialize_Data_Out;
extern int De_Serialize_flag;
int sock,sock2;

typedef union
{
	short fdata;
	char ldata[2];
} Transceiver_Data;    //电台数据联合体

Transceiver_Data Data0;
Transceiver_Data Data1;
Transceiver_Data Data2;
Transceiver_Data Data3;
Transceiver_Data Data4;
Transceiver_Data Data5;
Transceiver_Data Data6;
Transceiver_Data Data7;
Transceiver_Data Data8;


int Transceiver_Send(char *buf) {
	int num;
	if ((num = send(sock, buf, strlen(buf), 0)) == -1)//strlen()计算字符串占用位数
	{
		printf("ERROR: Failed to sent string.\n");
		close(sock);
		exit(1);
	}
	//printf("OK: Sent %d bytes sucessful, please enter again.\n", num);
	return 0;
}

void Get_Transceiver_Data()
{
	Data0.ldata[0] = buf.data[0];
	Data0.ldata[1] = buf.data[1];
	Data0.fdata;
	printf("Data0.fdata=%d\n",Data0.fdata);

	Data1.ldata[0] = buf.data[2];
	Data1.ldata[1] = buf.data[3];
	Data1.fdata;
	printf("Data1.fdata=%d\n",Data1.fdata);

	Data2.ldata[0] = buf.data[4];
	Data2.ldata[1] = buf.data[5];
	Data2.fdata;
	printf("Data2.fdata=%d\n",Data2.fdata);

	Data3.ldata[0] = buf.data[6];
	Data3.ldata[1] = buf.data[7];
	Data3.fdata;
	printf("Data3.fdata=%d\n",Data3.fdata);

	Data4.ldata[0] = buf.data[8];
	Data4.ldata[1] = buf.data[9];
	Data4.fdata;
	printf("Data4.fdata=%d\n",Data4.fdata);

	Data5.ldata[0] = buf.data[18];
	Data5.ldata[1] = buf.data[19];
	Data5.fdata;
	printf("Data5.fdata=%d\n",Data5.fdata);

	Data6.ldata[0] = buf.data[20];
	Data6.ldata[1] = buf.data[21];
	Data6.fdata;
	printf("Data6.fdata=%d\n",Data6.fdata);

	Data7.ldata[0] = buf.data[22];
	Data7.ldata[1] = buf.data[23];
	Data7.fdata;
	printf("Data7.fdata=%d\n",Data7.fdata);

	Data8.ldata[0] = buf.data[24];
	Data8.ldata[1] = buf.data[25];
	Data8.fdata;
	printf("Data8.fdata=%d\n",Data8.fdata);

}

void * myprocess3(void *arg)    //线程3
{
 // if(Flag_Tcp0==0)
	//{
	//Flag_Tcp0 = 1;
		sock = sock_connect("192.168.1.14",1234, 0);
		if (sock == -1)
		{
			printf("error: %s\n", strerror(errno));
			exit(0);
			//return NULL;
		}
		printf("connnect 192.168.1.14:1234\n");

		buffer_init(&buf);

		while (1)
		{
			sock = sock_connect("192.168.1.14",1234, 0);
			if (sock == -1)
			{
				printf("error: %s\n", strerror(errno));
				exit(0);
			}

			buffer_init(&buf);

			Transceiver_Send(Serialize_Data_Out);  //Transceiver_Send(buffer);     //套接字发送(放主函数会有接收延迟) 电台数据发送

			char tmp[26];
			int len = read(sock, tmp, sizeof(tmp)); //套接字接收,网络套接字是IP地址与端口的组合.从指定的打开的文件sock中读取指定大小tmp从tmp开始的缓冲区

			printf("TCP REV LEN=%d\n", len);
			if (len <= 0)
		  {
				printf("received %d, exit.\n", len);
				exit(0);
	        }
			if (buffer_add(&buf,  tmp, len) == -1)
			{
				printf("error, too large packet\n");
				exit(0);
			}
			int n = 0;
			while (1)
			{
				char *msg = parse_packet(&buf);
				De_Serialize_Data=msg;
				if (!De_Serialize_Data)
				  {
					printf("msg1=%s\n",msg);
						De_Serialize_flag=0;
				   }
					else
					{
						De_Serialize_flag=1;
						break;
					}
				if (!msg)
				{
					sock_connect("192.168.1.14",1234, 1);
					break;
				}
				n++;
				if (n > 1)
				{
					//printf(" [Mergerd Packed]\n");
				}
				free(msg);
			}
		}
	//}
 /*else
	{
		 Flag_Tcp0=0;
		 sock = sock_connect("192.168.1.14", 1234, 0);
		 if (sock == -1)
		 {
		 printf("error: %s\n", strerror(errno));
		 exit(0);
		 //return NULL;
		 }
		 printf("13234connnect 192.168.1.14:1234\n");

		 buffer_init(&buf);

	 while (1)
	 {
		 Transceiver_Send(buffer);     //套接字发送(放主函数会有接收延迟) 电台数据发送
		 char tmp[26];
		 int len = read(sock, tmp, sizeof(tmp));    //套接字接收,网络套接字是IP地址与端口的组合.从指定的打开的文件sock中读取指定大小tmp从tmp开始的缓冲区
		 printf("TCP REV LEN=%d\n", len);
		 if (len <= 0)
		 {
			 printf("received %d, exit.\n", len);
			 exit(0);
		 }
		 if (buffer_add(&buf, tmp, len) == -1)
		 {
			 printf("error, too large packet\n");
			 exit(0);
		 }
		 int n = 0;
		 while (1)
		 {
			 char *msg = parse_packet(&buf);
			 if (!msg)
			 {
			 break;
			 }
			 n ++;
			 printf("< %s\n", msg);
			 if (n > 1)
			 {
			 printf(" [Mergerd Packed]\n");
			 }
			 free(msg);
		 }
	 }
	   sock_connect("192.168.1.14", 1234, 1);
	 }*/
	return NULL;
}
