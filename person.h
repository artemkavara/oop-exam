#include <iostream>
#include <ctime>

#ifndef PERSON_H
#define PERSON_H

class Person
{
protected:
    std::string m_firstName;
    std::string m_lastName;
    time_t m_birthDate; 
public:
    Person(std::string firstName="First Name", std::string lastName="Last Name", int year=1900, int month=1, int day=1);
    Person(const Person& person);
    std::string getFirstName() const;
    std::string getLastName() const;
    time_t getBirthDate() const;
    void setFirstName(std::string n_firstName);
    void setLastName(std::string n_lastName);
    void setBirthDate(int n_year=0, int n_month=0, int n_day=0);
    friend std::ostream& operator<< (std::ostream &out, const Person &person);
    friend bool operator== (const Person& person1, const Person& person2);
    Person& operator=(const Person& person);
    ~Person();
};

#endif