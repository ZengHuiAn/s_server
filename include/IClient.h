#pragma once
#include "network.h"
class IClient {
public:
  virtual int Connect(SOCKET fd) = 0;
};