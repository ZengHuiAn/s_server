#pragma once
#include <execinfo.h>
#define SIZE 100
template <typename... Args> void log(Args &&... args) {
  std::cout << __DATE__ << __TIME__ << ":\t";
  ((std::cout << args << ' '), ...);
}
