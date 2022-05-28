#ifndef SQL_H_INCLUDED
#define SQL_H_INCLUDED
<<<<<<< HEAD
#include<iostream>
#include <mysql/mysql.h>
=======
<<<<<<< HEAD
#include<mysql/mysql.h>
=======

#include <mysql/mysql.h>
>>>>>>> 73144e7752046bcd6eb764e5a5200f80e7fe78e3
>>>>>>> 074095a469a9bd1acc257a5a4716bc1ac2f5489e

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

