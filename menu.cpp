#include<iostream>
#include"student.h"
#include"menu.h"
#include"sql_db.h"

void menu(sql_db& db){
    std::cout<<"Welcome to Student Record Managment System\n";

    std::cout<<"Kindly Choose the Operation you would like to perform\n";

    int choice;

    std::cout<<"1. Insert New Record\n";
    std::cout<<"2. View All Records\n";
    std::cout<<"3. Delete A Record\n";
    std::cout<<"4. Update A Record\n";
    std::cout<<"Press 404 To Close The Application\n";
    std::cout<<"Enter Your Choice : ";
    std::cin>>choice;

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
        Student data;
        std::cout<<"Enter Correct Details to be Updated\n";
        data.get_data();
        db.UPDATE_DATA(data);
        break;    
    default:
        std::cout<<"Press Any key to Close Application\n";
        getchar();
        exit(0);
        break;
    }

    system("clear");
    menu(db);
}