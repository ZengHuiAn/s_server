#pragma once
typedef int SOCKET;
#include <networkUtils.h>

enum ESocketType {
  //
  CLIENT = 0,
  SERVER = 10,
};

class Socket {
private:
  SOCKET sock;
  void initSocket(ESocketType SType);

public:
  Socket();
  ~Socket() = default;
};

Socket ::Socket() {
  //
  SOCKET newSock = socket(AF_INET, SOCK_STREAM, 0);
  if (newSock < 0) {
    //
  }
}

void Socket::initSocket(ESocketType SType) {
  switch (SType) {
  case CLIENT:
    log("创建客户端\t");
    break;
  case SERVER:
    log("创建服务器\t");
    break;
  }
}