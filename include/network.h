#pragma once
typedef int SOCKET;

class Socket {
private:
  SOCKET sock;

public:
  Socket();
  ~Socket() = default;
};

Socket ::Socket() {
  //
  SOCKET newSock = socket(AF_INET, SOCK_STREAM, 0);
  if (newSock < 0) {
  }
}