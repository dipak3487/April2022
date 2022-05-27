#ifndef SQL_H_INCLUDED
#define SQL_H_INCLUDED

#include <mysql/mysql.h>

using namespace std;

class sql {
    public:
    MYSQL mysql;
   // mysql_init(&mysql);
    MYSQL *conn= mysql_real_connect(&mysql, "localhost", "root", "root", "hotel", 3306, NULL, 0);
    MYSQL_ROW row;
    MYSQL_RES *res;

    bool query_check(stringstream &ss, sql sql);
};

#endif // SQL_H_INCLUDED

