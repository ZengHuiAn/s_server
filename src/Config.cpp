//
// Created by zenghui an on 2019-04-23.
//
#include <iostream>
#include <vector>
struct DataBase {
  char *host, *userName, *passwd, *database;
  int port;
  DataBase(const char *host, const char *userName, const char *passwd,
           const char *database, int port) {
    this->host = const_cast<char *>(host);
    this->userName = const_cast<char *>(userName);
    this->passwd = const_cast<char *>(passwd);
    this->database = const_cast<char *>(database);
    this->port = port;
  }
};

static struct DataBase allConfig[] = {
    DataBase("172.16.3.200", "root", "123456", "Gamer", 60003),
};