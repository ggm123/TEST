//
// Created by siasunhebo on 19-8-29.
//

#ifndef IMUTEST_NET_H
#define IMUTEST_NET_H

#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int sock_connect(const char *ip, int port, int sock_Flag );

int sock_connect(const char *ip, int port, int sock_Flag)
{
    int sock;
    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));//作用：bzero函数的作用是将addr指针指向的地址全部清零。
    addr.sin_family = AF_INET;//使用IPV4协议
    addr.sin_port = htons((short)port);//设置端口号8000
    inet_pton(AF_INET, ip, &addr.sin_addr);//设置IP地址

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)//SOCK_STREAM是socket类型，面向流；若面向数据报是SOCK_DGRAM
    {
        goto sock_err;
    }
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1)//连接服务器
    {
        goto sock_err;
    }
    return sock;

    sock_err:
    if (sock_Flag)
    {
        close(sock);
    }
    return -1;
}

#endif //IMUTEST_NET_H
