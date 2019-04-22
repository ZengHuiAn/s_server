#pragma once

#include <vector>
class TcpServer : public Socket, IServer {
protected:
  fd_set readFds;
  fd_set writeFds;
  fd_set expFds;
  struct timeval timeout;
  int addr_len;
  vector<SOCKET> client_sockets;

public:
  void initSocket() override;
  TcpServer();
  int AcceptClient();
};

TcpServer::TcpServer() : Socket() {
  //清楚fd_set
  this->initSocket();
  char addr[] = "0.0.0.0";
  this->client_sockets = {};
  this->readFds = {};
  this->timeout = {.tv_sec = 0};
  struct sockaddr_in addr_in = CreateAddr(addr, 6666);

  this->addr_len = sizeof(addr_in);
  int error = bind(this->sock, (struct sockaddr *)&addr_in, this->addr_len);
  log("绑定套接字:", error == 0 ? "成功" : "失败");

  if (error < 0) {
    return;
  }
  if (listen(this->sock, 10) < 0) {
    log("listen error");
    return;
  }
  //设置要读取的套接字

  FD_ZERO(&this->readFds);
}

void TcpServer::initSocket() {
  //
  Socket::initSocket();
}

int TcpServer::AcceptClient() {
  FD_ZERO(&readFds);
  FD_ZERO(&this->writeFds);
  FD_ZERO(&this->expFds);

  FD_SET(this->sock, &this->writeFds);
  FD_SET(this->sock, &this->readFds);
  FD_SET(this->sock, &this->expFds);
  //  FD_SET(this->sock, &this->readfds);
  int ret = select(this->sock + 1, &this->readFds, &this->writeFds,
                   &this->expFds, &this->timeout);
  if (ret < 0) {
    return ret;
  }
  if (FD_ISSET(this->sock, &this->readFds)) {
    //
  }
  //
}