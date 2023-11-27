/*
 * Author: Kio || Bahadýr Bozdað
 * Created at: 14/11/2023 12:00
 * file_name: socket.c
*/

#include "stdafx.h"

socket_t socket_tcp_bind(const char *ip, int port)
{
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1)
    {
        //sys_err("socket creation error");
        return INVALID_SOCKET;
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(ip);

    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
    {
        //sys_err("bind error: %s", strerror(errno));
        return INVALID_SOCKET;
    }

    if (listen(serverSocket, 5) == -1)
    {
        //sys_err("listen error: %s", strerror(errno));
        return INVALID_SOCKET;
    }

    //sys_log("server socket created: %d", serverSocket);

    return serverSocket;
}