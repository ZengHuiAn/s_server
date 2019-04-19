#pragma once

SOCKET CreateSocket() {
  //
  SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
  return sock;
}