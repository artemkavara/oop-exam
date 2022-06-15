#include <iostream>
#include <deque>
#include <algorithm>
#include <map>
#include <cassert>
#include "research.h"
#include "publication.h"

Research::Research()
{
    this->m_researchName = "Research Name";
    std::deque<Publication> publications;
    publications.push_back(Publication());
    this->m_publications = publications;
}

Research::Research(std::string researchName, std::deque<Publication> publications){
    this->m_researchName = researchName;
    this->m_publications = publications;
}

Research::Research(const Research& research){
    this->m_researchName = research.m_researchName;
    this->m_publications = research.m_publications;
}

std::string Research::getResearchName() const {
    return this->m_researchName;
}

std::deque<Publication> Research::getListOfPublications() const{
    return this->m_publications;
}

void Research::setResearchName(std::string researchName){
    this->m_researchName = researchName;
}

void Research::setPublications(std::deque<Publication> publications){
    this->m_publications = publications;
}

void Research::showFullInformation(std::ostream &out){
    out << "Research Name: " << this->m_researchName << std::endl;
    out << "Publications:\n"<<std::endl;
    std::deque<Publication> elementsQueue = this->m_publications;
    std::reverse(elementsQueue.begin(), elementsQueue.end());
    for (auto publication : elementsQueue)
    {
        out << publication << std::endl;
    }
    
}

std::map<ScientificAchievement, int> Research::countPublications() const{
    int n_thesis = 0, n_prof = 0, n_rep = 0, n_int = 0;
    for (auto publication: this->m_publications){
        ScientificAchievement type_publication = publication.getScientificAchievement();
        switch (type_publication)
        {
        case THESIS:
            n_thesis++;
            break;
        case PUBLICATION_PROFESSIONAL:
            n_prof++;
            break;
        case REPORT:
            n_rep++;
            break;
        case PUBLICATION_INTERNATIONAL:
            n_int++;
            break;
        }
    }
    std::map<ScientificAchievement, int> countedElements;
    countedElements.insert(std::pair<ScientificAchievement, int>(THESIS, n_thesis));
    countedElements.insert(std::pair<ScientificAchievement, int>(PUBLICATION_PROFESSIONAL, n_prof));
    countedElements.insert(std::pair<ScientificAchievement, int>(REPORT, n_rep));
    countedElements.insert(std::pair<ScientificAchievement, int>(PUBLICATION_INTERNATIONAL, n_int));
    return countedElements;
}

std::ostream& operator<< (std::ostream &out, const Research &research){
    out << "Research Name: " << research.m_researchName << std::endl;
    out << "Publications:"<<std::endl;
    std::map<ScientificAchievement, int> countedElements = research.countPublications();
    out << "Theses: "<<countedElements.find(THESIS)->second<<std::endl;
    out << "Professional Publications: "<<countedElements.find(PUBLICATION_PROFESSIONAL)->second<<std::endl;
    out << "Reports: "<<countedElements.find(REPORT)->second<<std::endl;
    out << "International Publications: "<<countedElements.find(PUBLICATION_INTERNATIONAL)->second<<std::endl;
    return out;
}

Research& Research::operator=(const Research& research){
    if (this == &research){
        return *this;
    }
    this->m_researchName = research.m_researchName;
    this->m_publications = research.m_publications;
    return *this;
}

void Research::addNewPublication(const Publication publication){
    std::deque<Publication> currentPublications = this->m_publications;
    currentPublications.push_back(publication);
    this->m_publications = currentPublications;
}

void Research::deletePublication(int year, int month, int day){

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
    std::deque<Publication> validPublications;
    for (auto publ = this->m_publications.cbegin(); publ<=this->m_publications.cend(); ++publ){
        time_t publicationDate = (*publ).getPublicationDate();
        if (std::difftime(date, publicationDate) <= 0){
            validPublications.push_back(*publ);
        }
    }
    this->m_publications = validPublications;
}

Research Research::operator+(const Research& research){
    std::deque<Publication> listOfPublications = this->m_publications;
    bool exists;
    for (auto publication: research.getListOfPublications()){
        exists = false;
        for (auto currentPublication:listOfPublications){
            if (publication == currentPublication) {
                exists = true;
                break;
            }
        }
        if (!exists) listOfPublications.push_back(publication);
    }
    Research researchMerged(this->m_researchName, listOfPublications);
    return researchMerged;
}

Research::~Research()
{
}
