#include <iostream>
#include "student.h"
#include "menu.h"
#include "sql_db.h"

void menu(sql_db &db)
{
    std::cout << "Welcome to Student Record Managment System\n";

    std::cout << "Kindly Choose the Operation you would like to perform\n";

    int choice;

    std::cout << "1. Insert New Record\n";
    std::cout << "2. View All Records\n";
    std::cout << "3. Delete A Record\n";
    std::cout << "4. Update A Record\n";
    std::cout << "Press 404 To Close The Application\n";
    std::cout << "Enter Your Choice : ";
    std::cin >> choice;

    getchar();

    switch (choice)
    {
    case 1:
        Student data;
        data.get_data();
        db.INSERT_DATA(data);
        break;
    case 2:
        db.VIEW_DATA();
        break;
    case 3:

        break;
    case 4:

        int update_choice;
        std::cout << "Choose a field that you want to update\n";
        std::cout << "1. Name\n";
        std::cout << "2. DoB\n";
        std::cout << "3. Email\n";
        std::cout << "4. Mobile Number\n";
        std::cout << "Enter Your Choice :";
        std::cin >> update_choice;
        getchar();
        db.UPDATE_DATA(update_choice);
        break;
    default:
        // std::cout << "Press Any key to Close Application\n";
        // getchar();
        exit(0);
        break;
    }

    system("clear");
    menu(db);
}