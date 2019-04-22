#pragma once
class TcpClient : public Socket, IClient {
public:
  int Connect(SOCKET fd) override;
  TcpClient();
};

TcpClient::TcpClient() : Socket() {
  //
  this->initSocket();
  log("这是TcpClient");
}

int TcpClient::Connect(SOCKET fd) {
  //
}
// void TcpClient::initSocket() { Socket::initSocket(); }