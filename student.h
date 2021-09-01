#ifndef STUDENT_H
#define STUDENT_H

class Student{
    private:

    char name[30];
    unsigned long id;
    unsigned long mobile;
    char dob[11];
    char email[30];

    public:

    void set_data(char*,unsigned int,unsigned int,char*,char*);
    void show_data(void);
    void get_data(void);
    void insert_data(void);

    friend class sql_db;
};

#endif