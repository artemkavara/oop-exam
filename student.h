#include <iostream>
#include <ctime>
#include "person.h"
#pragma once

#ifndef STUDENT_H
#define STUDENT_H

class Student : public Person
{
private:
    int m_yearOfStudying;
public:
    Student(std::string p_firstName = "First Name", std::string p_lastName = "Last Name", 
            int p_year = 1900, int p_month = 1, int p_day = 1, int yearOfStudying=1);
    Student(const Student& student);
    int getYearOfStudying() const;
    void setYearOfStudying(int yearOfStudying);
    Student& operator=(const Student& student);
    friend std::ostream& operator<< (std::ostream& out, const Student& student);
    friend bool operator== (const Student& student1, const Student& student2);
    friend bool operator!= (const Student& student1, const Student& student2);
    ~Student();
};


#endif