#pragma once
#include <cstdarg>
#include <execinfo.h>

template <typename... Args> void log(Args &&... args) {
  std::cout << __DATE__ << __TIME__ << ":\t";
  ((std::cout << args << ' '), ...);
}

void D_log(...) {
  //  std::cout << __DATE__ << __TIME__ << ":\t" << sizeof...(args);
}
