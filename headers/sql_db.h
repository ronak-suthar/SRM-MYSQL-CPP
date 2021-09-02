#ifndef SQL_DB_H
#define SQL_DB_H
#include"student.h"
#include<mysql/mysql.h>

class sql_db{
    public:
    const char *server,*user,*password,*database;
    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;

    sql_db(void);

    MYSQL* establish_connection(void);
    void VIEW_DATA(void);
    void INSERT_DATA(Student);
    void UPDATE_DATA(int);

    ~sql_db(void);
};

#endif