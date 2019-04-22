
#pragma once

#include <arpa/inet.h>
/**
 *创建套接字
 * @return socket
 */
SOCKET CreateSocket() {
  SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
  return sock;
}

/**
 * 创建一个空地址
 * @return
 */
struct sockaddr_in CreateEmptyAddr() {
  struct sockaddr_in address = {};
  return address;
}

/**
 *创建地址
 * @param addr ip
 * @param port 端口
 * @return
 */
struct sockaddr_in CreateAddr(char *addr, int port = -1) {
  struct sockaddr_in address = CreateEmptyAddr();
  address.sin_port = htons(port);
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr(addr);
  return address;
}