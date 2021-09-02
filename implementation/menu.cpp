#include <iostream>
#include "../headers/student.h"
#include "../headers/menu.h"
#include "../headers/sql_db.h"
#include <iomanip>
void printer(int a,int b){
    for(int i=0;i<b;i++){
        std::cout<<"\n";
    }
    for(int i=0;i<a;i++){
        std::cout<<"    ";
    }
}
void menu(sql_db &db)
{   
    system("clear");

    printer(5);std::cout<<"___________                                            ___________\n";
    printer(5);std::cout<<"           \\Welcome to Student Record Managment System/\n";
    
    printer(5,2);std::cout<< "Kindly Choose the Operation you would like to perform\n";

    int choice;

    printer(5,1);std::cout << "1. Insert New Record\n";
    printer(5,1);std::cout << "2. View All Records\n";
    printer(5,1);std::cout << "3. Delete A Record\n";
    printer(5,1);std::cout << "4. Update A Record\n";
    printer(5,1);std::cout << "Press 404 To Close The Application\n";
    printer(5,1);std::cout << "Enter Your Choice : ";
    std::cin >> choice;

    getchar();

    system("clear");
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
        db.DELETE_DATA();
        break;
    case 4:

        int update_choice;

        
        printer(5,1);std::cout <<"------------------------------------------\n";
        printer(5,1);std::cout << "Choose a field that you want to update\n";
        printer(5,1);std::cout << "1. Name\n";
        printer(5,1);std::cout << "2. DoB\n";
        printer(5,1);std::cout << "3. Email\n";
        printer(5,1);std::cout << "4. Mobile Number\n";
        printer(5,1);std::cout << "Enter Your Choice :";
        std::cin >> update_choice;
        getchar();
        db.UPDATE_DATA(update_choice);
        break;
    default:
        return;
        break;
    }

    system("clear");
    menu(db);
}