
#include "ErrorMessage.cpp"
#include <Debug.h>
#include <cstring>
#include <exception>
enum ErrorCode {
  // mysql error
  // mysql 初始化失败
  MYSQL_INIT_ERROR = 0,
  MYSQL_CONNECT_ERROR,
  //查询失败
  MYSQL_QUERY_FAILED,

};

struct ErrorClass : public std::exception {
  ErrorCode code;

  std::string message;
  explicit ErrorClass(ErrorCode code) {
    this->code = code;
    this->message = ERRORMessageConfig[this->code];
  };
  const char *what() const throw() override {
    //
    return this->message.c_str();
  }
};