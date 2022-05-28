#ifndef SQL_H_INCLUDED
#define SQL_H_INCLUDED
<<<<<<< HEAD
#include<mysql/mysql.h>
=======

#include <mysql/mysql.h>
>>>>>>> 73144e7752046bcd6eb764e5a5200f80e7fe78e3

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

