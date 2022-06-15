#include <cassert>
#include <iostream>
#include "student.h"
#include "person.h"

Student::Student(std::string p_firstName, std::string p_lastName, 
                 int p_year, int p_month, int p_day, int yearOfStudying) :
                 Person(p_firstName, p_lastName, p_year, p_month, p_day)
{
    assert (yearOfStudying >=1 && yearOfStudying <=6 && "Year invalid");
    this->m_yearOfStudying = yearOfStudying;
}

Student::Student(const Student& student) : Person(student){
    this->m_yearOfStudying = student.m_yearOfStudying;
}

int Student::getYearOfStudying() const{
    return this->m_yearOfStudying;
}

void Student::setYearOfStudying(int yearOfStudying){
    assert (yearOfStudying >=1 && yearOfStudying <=6 && "Year invalid");
    this->m_yearOfStudying = yearOfStudying;
}

Student& Student::operator=(const Student& student){
    if (this == &student){
        return *this;
    }
    Person::operator=(student);
    this->m_yearOfStudying = student.m_yearOfStudying;
    return *this;

}

bool operator== (const Student& student1, const Student& student2){
    return (student1.m_firstName == student2.m_firstName 
        && student1.m_lastName == student2.m_lastName
        && student1.m_birthDate == student2.m_birthDate
        && student1.m_yearOfStudying == student2.m_yearOfStudying);
}

bool operator!= (const Student& student1, const Student& student2){
    return !(student1==student2);
}

std::ostream& operator<< (std::ostream& out, const Student& student){
    time_t birth = student.getBirthDate();
    out << "Student:\n" << "\tFirst Name: " << student.getFirstName() << "\n\tLast Name: "<< student.getLastName() 
    << "\n\tDate of Birth: "<<ctime(&birth) << "\tYear of Studying: " << student.getYearOfStudying() << std::endl;
    return out;
}

Student::~Student()
{
}
