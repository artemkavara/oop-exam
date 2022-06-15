#include <iostream>
#include <deque>
#include <map>
#include "publication.h"

#ifndef RESEARCH_H
#define RESEARCH_H
class Research
{
private:
    std::string m_researchName;
    std::deque<Publication> m_publications;
public:
    Research();
    Research(std::string researchName, std::deque<Publication> publications);
    Research(const Research& research);
    std::string getResearchName() const;
    std::deque<Publication> getListOfPublications() const;
    void setResearchName(std::string researchName);
    void setPublications(std::deque<Publication> publications);
    void showFullInformation(std::ostream &out);
    std::map<ScientificAchievement, int> countPublications() const;
    friend std::ostream& operator<< (std::ostream &out, const Research &research);
    Research& operator=(const Research& research);
    void addNewPublication(const Publication publication);
    void deletePublication(int year=1900, int month=1, int day=1);
    Research operator+(const Research& research);
    ~Research();
};
#endif