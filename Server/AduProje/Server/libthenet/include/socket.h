/* 
 *   Author: Kio || Bahadýr Bozdað
 *   Date: 12.02.2023
 *   file_name: socket.h
*/

#ifndef __INC_LIBTHENET_NETWORK_H__
#define __INC_LIBTHENET_NETWORK_H__

extern "C"
{
   #define INVALID_SOCKET -1

   extern socket_t socket_tcp_bind(const char *ip, int port);
}
#endif