#ifndef SQL_H_INCLUDED
#define SQL_H_INCLUDED

#include<iostream>
#include <mysql/mysql.h>

using namespace std;

class sql {
    public:
   // MYSQL *conn;
    // MYSQL *conn= mysql_init(NULL);
    // if(conn == NULL){
    //     cout<<"Fail to connect";
    // }
    MYSQL *conn= mysql_real_connect(mysql_init(0), "localhost", "root", "root", "hotel", 0, NULL, 0);

    MYSQL_ROW row;
    MYSQL_RES *res;

    bool query_check(stringstream &ss, sql sql);
};

#endif // SQL_H_INCLUDED

