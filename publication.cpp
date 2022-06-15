#include <iostream>
#include <ctime>
#include <cassert>
#include "student.h"
#include "scientific-achievement.h"
#include "publication.h"


Publication::Publication(Student student, 
                ScientificAchievement scientificAchievement, 
                int yearOfPublication,
                int monthOfPublication,
                int dayOfPublication)
{
    this->m_student = student;
    this->m_scientificAchievement = scientificAchievement;

    assert (yearOfPublication >= 1900 && "Year invalid");
    assert (monthOfPublication >= 1 && monthOfPublication <= 12 && "Month invalid");
    assert (dayOfPublication >= 1 && dayOfPublication <= 31 && "Day invalid");

    tm dateStruct;
    dateStruct.tm_year = yearOfPublication - 1900;
    dateStruct.tm_mon = monthOfPublication - 1;
    dateStruct.tm_mday = dayOfPublication;
    dateStruct.tm_hour = 0;
    dateStruct.tm_min = 0;
    dateStruct.tm_sec = 0;
    dateStruct.tm_isdst = -1;

    time_t date = mktime(&dateStruct);
    this->m_publicationDate = date;
}

Publication::Publication(const Publication& publication){
    this->m_student = publication.m_student;
    this->m_scientificAchievement = publication.m_scientificAchievement;
    this->m_publicationDate = publication.m_publicationDate;
}

Student Publication::getStudent() const{
    return this->m_student;
}

ScientificAchievement Publication::getScientificAchievement() const{
    return this->m_scientificAchievement;
}

time_t Publication::getPublicationDate() const{
    return this->m_publicationDate;
}

void Publication::setStudent(const Student& student){
    this->m_student = student;
}

void Publication::setScientificAchievement(ScientificAchievement scientificAchievement){
    this->m_scientificAchievement = scientificAchievement;
}

void Publication::setPublicationDate(int yearOfPublication, int monthOfPublication, int dayOfPublication){
    tm dateStruct;
    tm* publicationDateStruct = gmtime(&this->m_publicationDate);
    assert (yearOfPublication >= 1900 && "Year invalid");
    dateStruct.tm_year = yearOfPublication-1900;
    if (monthOfPublication!=0) {
        assert (monthOfPublication >= 1 && monthOfPublication <= 12 && "Month invalid");
        dateStruct.tm_mon = monthOfPublication - 1;
    } else {
        dateStruct.tm_mon = publicationDateStruct->tm_mon;
    }
    if (dayOfPublication!=0){
        assert (dayOfPublication >= 1 && dayOfPublication <= 31 && "Day invalid");
        dateStruct.tm_mday = dayOfPublication;
    } else {
        dateStruct.tm_mday = publicationDateStruct->tm_mday;
    }
    dateStruct.tm_hour = 0;
    dateStruct.tm_min = 0;
    dateStruct.tm_sec = 0;
    dateStruct.tm_isdst = -1;
    time_t date = mktime(&dateStruct);
    this->m_publicationDate = date;
}

std::ostream& operator<< (std::ostream& out, const Publication& publication){
    std::string typeOfPublication;
    switch (publication.getScientificAchievement())
    {
    case THESIS:
        typeOfPublication = "Thesis";
        break;
    case PUBLICATION_PROFESSIONAL:
        typeOfPublication = "Professional Publication";
        break;
    case REPORT:
        typeOfPublication = "Report";
        break;
    case PUBLICATION_INTERNATIONAL:
        typeOfPublication = "International Publication";
        break;
    }
    time_t publicationDate = publication.getPublicationDate();
    out<<"Publication:\n"<<publication.getStudent()<<"Type of Publication:\n\t"<<typeOfPublication<<"\nPublication Date:\n\t"<<ctime(&publicationDate);
    return out;
}

bool operator==(const Publication& publication1, const Publication& publication2) {
    return (publication1.m_student == publication2.m_student &&
            publication1.m_scientificAchievement == publication2.m_scientificAchievement &&
            publication1.m_publicationDate == publication2.m_publicationDate);
}

bool operator!=(const Publication& publication1, const Publication& publication2) {
    return !(publication1 == publication2);
}

Publication::~Publication()
{
}