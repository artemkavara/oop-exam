#include <string>
#include <ctime>
#include <cassert>
#include <iostream>
#include "person.h"

Person::Person(std::string firstName, std::string lastName, int year, int month, int day)
{
    this->m_firstName = firstName;
    this->m_lastName = lastName;

    assert (year >= 1900 && "Year invalid");
    assert (month >= 1 && month <= 12 && "Month invalid");
    assert (day >= 1 && day <= 31 && "Day invalid");

    tm dateStruct;
    dateStruct.tm_year = year - 1900;
    dateStruct.tm_mon = month - 1;
    dateStruct.tm_mday = day;
    dateStruct.tm_hour = 0;
    dateStruct.tm_min = 0;
    dateStruct.tm_sec = 0;
    dateStruct.tm_isdst = -1;

    time_t date = mktime(&dateStruct);
    this->m_birthDate = date;
}

Person::Person(const Person& person): m_firstName(person.m_firstName), m_lastName(person.m_lastName), m_birthDate(person.m_birthDate){}

std::ostream& operator<< (std::ostream &out, const Person &person){
    out << "Person:\n" << "First Name: " << person.m_firstName << "\nLast Name: "<< person.m_lastName << "\nDate of Birth: "<<ctime(&person.m_birthDate) << std::endl;
    return out;
}

Person& Person::operator=(const Person& person){
    if (this == &person){
        return *this;
    }

    this->m_firstName = person.m_firstName;
    this->m_lastName = person.m_lastName;
    this->m_birthDate = person.m_birthDate;

    return *this;
}

bool operator== (const Person& person1, const Person& person2){
    if (person1 == person2) return true;
    if (person1.m_firstName == person2.m_firstName && person1.m_lastName == person2.m_lastName && person1.m_birthDate == person2.m_birthDate) {
        return true;
    } else {
        return false;
    }
}

std::string Person::getFirstName() const{
    return this->m_firstName;
};

std::string Person::getLastName() const{
    return this->m_lastName;
};

time_t Person::getBirthDate() const{
    return this->m_birthDate;
};

void Person::setFirstName(std::string n_firstName){
    this->m_firstName = n_firstName;
}

void Person::setLastName(std::string n_lastName){
    this->m_lastName = n_lastName;
}

void Person::setBirthDate(int year, int month, int day){
    tm dateStruct;
    tm* personDateStruct = gmtime(&this->m_birthDate);
    assert (year >= 1900 && "Year invalid");
    dateStruct.tm_year = year-1900;
    if (month!=0) {
        assert (month >= 1 && month <= 12 && "Month invalid");
        dateStruct.tm_mon = month - 1;
    } else {
        dateStruct.tm_mon = personDateStruct->tm_mon;
    }
    if (day!=0){
        assert (day >= 1 && day <= 31 && "Day invalid");
        dateStruct.tm_mday = day;
    } else {
        dateStruct.tm_mday = personDateStruct->tm_mday;
    }
    dateStruct.tm_hour = 0;
    dateStruct.tm_min = 0;
    dateStruct.tm_sec = 0;
    dateStruct.tm_isdst = -1;
    time_t date = mktime(&dateStruct);
    this->m_birthDate = date;
}

Person::~Person()
{
}
