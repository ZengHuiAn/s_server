//
// Created by zenghui an on 2019-04-23.
//
#include "ErrorHead.cpp"
#include <Debug.h>
#include <Dic.cpp>
#include <cstdarg>
#include <cstdlib>
#include <map>
#include <mysql/mysql.h>
#include <unistd.h>
void Run();

class MysqlHelper {
public:
  MysqlHelper();
  ~MysqlHelper();
  MYSQL *conn;
  void Connect(char *host, char *userName, char *passwd, char *database,
               int port);

  void Close();

  void Query(const char *fmt, ...);
};

MysqlHelper::MysqlHelper() {
  //
  this->conn = mysql_init(nullptr);
  if (this->conn == nullptr) {
    throw ErrorClass(MYSQL_INIT_ERROR);
  }
}

MysqlHelper::~MysqlHelper() { this->Close(); }

void MysqlHelper::Connect(char *host, char *userName, char *passwd,
                          char *database, int port) {

  log(host, userName, passwd, database, port);
  this->conn = mysql_real_connect(this->conn, host, userName, passwd, database,
                                  port, nullptr, 0);
  if (this->conn == nullptr)
    throw ErrorClass(MYSQL_CONNECT_ERROR);
}

void MysqlHelper::Close() {
  //
  if (this->conn != nullptr) {
    log("断开数据库了哦");
    mysql_close(this->conn);
  }
}

void MysqlHelper::Query(const char *fmt, ...) {
  if (this->conn == nullptr)
    throw ErrorClass(MYSQL_CONNECT_ERROR);

  char sql[4096];
  va_list args;
  va_start(args, fmt);
  size_t len = vsnprintf(sql, sizeof(sql), fmt, args);
  va_end(args);
  int ret = mysql_real_query(this->conn, sql, strlen(sql));
  if (ret != 0)
    throw ErrorClass(MYSQL_QUERY_FAILED);
  MYSQL_RES *result = mysql_store_result(this->conn);

  if (result) {
    unsigned int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))) {
      unsigned long *lengths;
      lengths = mysql_fetch_lengths(result);
      unsigned int i;

      for (i = 0; i < num_fields; i++) {
        //        values[i].ptr = row[i];
        //        values[i].len = lengths[i];

        log("行数:", i, "数据", row[i], "长度:", lengths[i]);
      }
    }

    mysql_free_result(result);
    //    free(values);
  } else {
    if (mysql_field_count(this->conn) == 0) {
      return;
    } else {
      log("mysql error");
      return;
    }
  }
}

void Run() {
  try {
    MysqlHelper helper = {};
    const struct DataBase firstMysql = allConfig[0];
    helper.Connect(firstMysql.host, firstMysql.userName, firstMysql.passwd,
                   firstMysql.database, firstMysql.port);

    log("哎呀，竟然连接到数据库了");
    helper.Query("select * from `%s`", "monster");
    //    mysqcl
  } catch (ErrorClass &except) {
    log(except.what());
  }
};