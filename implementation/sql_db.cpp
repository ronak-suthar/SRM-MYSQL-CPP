#include <mysql/mysql.h>
#include "../headers/sql_db.h"
#include "../headers/student.h"
#include "../headers/menu.h"
#include <iostream>
#include <string>
#include <iomanip>

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
        printer(5, 2);
        std::cout << "Connection Error: " << mysql_error(connection) << std::endl;
        exit(1);
    }
    return connection;
}

void sql_db::execute_query(std::string &query)
{
    if (mysql_query(this->conn, query.c_str()))
    {
        std::cout << "ERROR : " << mysql_error(this->conn) << "\n";
    }
    else
    {
        printer(5, 1);
        std::cout << "Transaction Successfull\n";
        printer(5, 1);
        std::cout << "Press Any key to go back to menu\n";
        getchar();
    }
}
void sql_db::INSERT_DATA(Student Member)
{
    std::string query = "";

    //INSERT INTO COLLEGE VALUES ()
    query = "INSERT INTO Student " + std::string("VALUES (\"") + std::string(Member.name) + "\",\"" + std::to_string(Member.id) + "\",\"" + std::to_string(Member.mobile) + "\",\"" + std::string(Member.dob) + "\",\"" + std::string(Member.email) + "\")";

    //std::cout << query << "\n";

    sql_db::execute_query(query);
}

void sql_db::VIEW_DATA(void)
{
    std::string query = "SELECT * FROM Student";

    if (mysql_query(this->conn, query.c_str()))
    {
        printer(5, 2);
        std::cout << "ERROR : " << mysql_error(this->conn) << "\n";
    }
    else
    {
        this->res = mysql_use_result(this->conn);

        printer(5, 2);
        std::cout << "-----------------------------------------------------------------\n";

        printer(5);
        std::cout << std::left << std::setw(20) << std::setfill(' ') << "Name";
        std::cout << std::left << std::setw(12) << std::setfill(' ') << "| Id";
        std::cout << std::left << std::setw(12) << std::setfill(' ') << "| Mobile";
        std::cout << std::left << std::setw(12) << std::setfill(' ') << "| DoB";
        std::cout << std::left << std::setw(20) << std::setfill(' ') << "| Email";

        while ((this->row = mysql_fetch_row(this->res)) != NULL)
        {
            // the below row[] parametes may change depending on the size of the table and your objective
            printer(5, 1);
            //std::cout << row[0] << " | " << row[1] << " | " << row[2] << " | " << row[3] << " | " << row[4] << "\n";
            std::cout << std::left << std::setw(20) << std::setfill(' ') << row[0];
            std::cout <<"| "<< std::left << std::setw(10) << std::setfill(' ') <<row[1];
            std::cout <<"| "<< std::left << std::setw(10) << std::setfill(' ') <<row[2];
            std::cout <<"| "<< std::left << std::setw(10) << std::setfill(' ') <<row[3];
            std::cout <<"| "<< std::left << std::setw(20) << std::setfill(' ') <<row[4];
        }

        mysql_free_result(this->res);

        printer(5, 1);
        std::cout << "-----------------------------------------------------------------\n";

        printer(5, 1);
        std::cout << "Transaction Successfull\n";
        printer(5, 1);
        std::cout << "Press Any key to go back to menu\n";
        getchar();
    }
}

void sql_db::UPDATE_DATA(int choice)
{
    //std::string query = "UPDATE STUDENT SET ";

    unsigned long id;

    printer(5, 1);
    std::cout << "Enter Your Registration ID : ";
    std::cin >> id;
    getchar();

    if (choice == 1)
    {
        std::string name;
        printer(5, 1);
        std::cout << "Enter Correct Name : ";
        std::getline(std::cin, name);

        std::string query = "UPDATE Student SET name=\"" + name + "\" WHERE id=" + std::to_string(id);

        sql_db::execute_query(query);
    }
    else if (choice == 2)
    {
        std::string dob;
        printer(5, 1);
        std::cout << "Enter Correct DoB in YYYY-MM-DD : ";
        std::getline(std::cin, dob);

        std::string query = "UPDATE Student SET dob=\"" + dob + "\" WHERE id=" + std::to_string(id);

        sql_db::execute_query(query);
    }
    else if (choice == 3)
    {
        std::string email;
        printer(5, 1);
        std::cout << "Enter Correct Email : ";
        std::getline(std::cin, email);

        std::string query = "UPDATE Student SET email_id=\"" + email + "\" WHERE id=" + std::to_string(id);

        sql_db::execute_query(query);
    }
    else if (choice == 4)
    {
        unsigned long mobile;
        printer(5, 1);
        std::cout << "Enter Correct Mobile Number : ";
        std::cin >> mobile;
        getchar();

        std::string query = "UPDATE Student SET mobile=" + std::to_string(mobile) + " WHERE id=" + std::to_string(id);
        sql_db::execute_query(query);
    }
}

void sql_db::DELETE_DATA(void)
{
    unsigned long id;
    printer(5, 1);
    std::cout << "Enter Your Registration ID : ";
    std::cin >> id;
    getchar();

    std::string query = "DELETE FROM Student WHERE id=" + std::to_string(id);

    sql_db::execute_query(query);
}
sql_db::~sql_db(void)
{
    mysql_close(this->conn);
}
