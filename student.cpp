#include <iostream>
#include "student.h"
#include "sql_db.h"
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
    std::cout<<"________________________                   _________________________\n";
    std::cout<<"                        \\USER DETAILS ARE/ \n";
    std::cout << "User details are as follows : \n";
    std::cout << "Name : " << name << "\n";
    std::cout << "ID : " << id << "\n";
    std::cout << "Mobile : " << mobile << "\n";
    std::cout << "Email : " << email << "\n";
    std::cout << "DoB : " << dob << "\n";
    std::cout<<"--------------------------------------------------------------------\n";
}

void Student::get_data(){

    std::string temp;

    std::cout<<"Enter Student Name : ";
    std::getline(std::cin,temp);
    strcpy(this->name,temp.c_str());

    std::cout<<"Enter DoB in YYYY-MM-DD : ";
    std::getline(std::cin,temp);
    strcpy(this->dob,temp.c_str());
    
    std::cout<<"Enter Email : ";
    std::getline(std::cin,temp);
    strcpy(this->email,temp.c_str());

    std::cout<<"Enter ID : ";
    std::cin>>this->id;

    std::cout<<"Enter Mobile Number : ";
    std::cin>>this->mobile;

    getchar();
}

// void Student::insert_data(void){
//     this->get_data();
//     this->show_data();
//     sql_db::INSERT_DATA(this);
// }