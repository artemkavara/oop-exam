#include <iostream>
#include <ctime>
#include "student.h"
#include "scientific-achievement.h"
#pragma once

#ifndef PUBLICATION_H
#define PUBLICATION_H

class Publication
{
private:
    Student m_student;
    ScientificAchievement m_scientificAchievement;
    time_t m_publicationDate; 
public:
    Publication(Student student = Student(), 
                ScientificAchievement scientificAchievement = THESIS, 
                int yearOfPublication = 1900,
                int monthOfPublication = 1,
                int dayOfPublication = 1);
    Publication(const Publication& publication);
    Student getStudent() const;
    ScientificAchievement getScientificAchievement() const;
    time_t getPublicationDate() const;
    void setStudent(const Student& student);
    void setScientificAchievement(ScientificAchievement scientificAchievement);
    void setPublicationDate(int yearOfPublication = 0, int monthOfPublication = 0, int dayOfPublication = 0);
    friend std::ostream& operator<< (std::ostream& out, const Publication& publication);
    friend bool operator==(const Publication& publication1, const Publication& publication2);
    friend bool operator!=(const Publication& publication1, const Publication& publication2);
    ~Publication();
};

#endif