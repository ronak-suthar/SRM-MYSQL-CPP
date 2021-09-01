#include <mysql/mysql.h>
#include "sql_db.h"
#include "student.h"
#include <iostream>
#include <string>

sql_db::sql_db(void)
{
    sql_db::database = "COLLEGE";
    sql_db::server = "localhost";
    sql_db::user = "root";
    sql_db::password = "ronak@db";

    sql_db::conn = sql_db::establish_connection();
}

MYSQL *sql_db::establish_connection(void)
{
    MYSQL *connection = mysql_init(NULL); // mysql instance

    //connect database
    if (!mysql_real_connect(connection, this->server, this->user, this->password, this->database, 0, NULL, 0))
    {
        std::cout << "Connection Error: " << mysql_error(connection) << std::endl;
        exit(1);
    }
    return connection;
}

void sql_db::INSERT_DATA(Student Member)
{
    std::string query = "";

    //INSERT INTO COLLEGE VALUES ()
    query = "INSERT INTO Student " + std::string("VALUES (\"") + std::string(Member.name) + "\",\"" + std::to_string(Member.id) + "\",\"" + std::to_string(Member.mobile) + "\",\"" + std::string(Member.dob) + "\",\"" + std::string(Member.email) + "\")";

    std::cout << query << "\n";

    if (mysql_query(this->conn, query.c_str()))
    {
        std::cout << "ERROR : " << mysql_error(this->conn) << "\n";
    }
    else
    {
        std::cout << "Transaction Successfull\n";
        std::cout << "Press Any key to go back to menu\n";
        getchar();
    }
}

void sql_db::VIEW_DATA(void)
{
    std::string query = "SELECT * FROM Student";

    if (mysql_query(this->conn, query.c_str()))
    {
        std::cout << "ERROR : " << mysql_error(this->conn) << "\n";
    }
    else
    {
        this->res = mysql_use_result(this->conn);

        std::cout<<"-----------------------------------------------------------------\n";

        while ((this->row = mysql_fetch_row(this->res)) != NULL)
        {
            // the below row[] parametes may change depending on the size of the table and your objective
            std::cout << row[0] << " | " << row[1] << " | " << row[2] <<" | " << row[3] <<" | " << row[4] <<"\n";
        }

         mysql_free_result(this->res);
        
        std::cout<<"-----------------------------------------------------------------\n";

        std::cout << "Transaction Successfull\n";
        std::cout << "Press Any key to go back to menu\n";
        getchar();
    }
}

void sql_db::UPDATE_DATA(Student){
   //std::string query = "UPDATE STUDENT SET ";
}
sql_db::~sql_db(void)
{
    mysql_close(this->conn);
}
