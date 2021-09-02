#include <iostream>
#include "../headers/student.h"
#include "../headers/sql_db.h"
#include "../headers/menu.h"
#include <cstring>
#include <string>
#include <limits>
#include <ios>

void Student::set_data(char usr_name[], unsigned int usr_id, unsigned int usr_mobile, char usr_dob[], char usr_email[])
{
    strcpy(name, usr_name);
    id = usr_id;
    mobile = usr_mobile;
    strcpy(dob, usr_dob);
    strcpy(email, usr_email);
}

void Student::show_data()
{   
    printer(5);std::cout<<"________________________                   _________________________\n";
    printer(5);std::cout<<"                        \\USER DETAILS ARE/ \n";
    printer(5);std::cout << "User details are as follows : \n";
    printer(5);std::cout << "Name : " << name << "\n";
    printer(5);std::cout << "ID : " << id << "\n";
    printer(5);std::cout << "Mobile : " << mobile << "\n";
    printer(5);std::cout << "Email : " << email << "\n";
    printer(5);std::cout << "DoB : " << dob << "\n";
    printer(5);std::cout<<"--------------------------------------------------------------------\n";
}

void Student::get_data(){

    std::string temp;

    printer(5,1);std::cout <<"------------------------------------------\n";
    printer(5,1);std::cout<<"Enter Student Name : ";
    std::getline(std::cin,temp);
    strcpy(this->name,temp.c_str());

    printer(5,1);std::cout<<"Enter DoB in YYYY-MM-DD : ";
    std::getline(std::cin,temp);
    strcpy(this->dob,temp.c_str());
    
    printer(5,1);std::cout<<"Enter Email : ";
    std::getline(std::cin,temp);
    strcpy(this->email,temp.c_str());

    printer(5,1);std::cout<<"Enter ID : ";
    std::cin>>this->id;

    printer(5,1);std::cout<<"Enter Mobile Number : ";
    std::cin>>this->mobile;

    getchar();
}

// void Student::insert_data(void){
//     this->get_data();
//     this->show_data();
//     sql_db::INSERT_DATA(this);
// }