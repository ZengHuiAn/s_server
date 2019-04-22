#pragma once
typedef signed int SOCKET;
#include "networkUtils.h"

class Socket {
protected:
  SOCKET sock;
  virtual void initSocket();

public:
  Socket();
  ~Socket() = default;
};

Socket ::Socket() {
  this->sock = -1;
  log("这是Socket");
}
void Socket::initSocket() {
  log("Socket 创建套接字");
  this->sock = CreateSocket();
}