#include <iostream>
#include <ctime>
#include <deque>
#include <cassert>
#include "student.h"
#include "publication.h"
#include "scientific-achievement.h"
#include "research.h"


int main(){

    Student studentDefault = Student();
    Student student1 = Student("Peter", "Parker", 2001, 11, 13);
    Student student2 = Student("Ron", "Wisley", 1998, 9, 17);
    Student studentCopy = Student(student1);
    Student studentAssignment = student2;

    Publication publicationDefault = Publication();
    Publication publication1 = Publication(student1, REPORT, 2020, 3, 10);
    Publication publication2 = Publication(student1, THESIS, 2020, 4, 10);
    Publication publication3 = Publication(student2, PUBLICATION_PROFESSIONAL, 2021, 4, 10);
    Publication publication4 = Publication(student2, PUBLICATION_INTERNATIONAL, 2021, 4, 10);
    Publication publication5 = Publication(student2, PUBLICATION_PROFESSIONAL, 2022, 1, 12);
    Publication publicationCopy1 = Publication(publication1);
    Publication publicationAssignment3 = publication3;

    std::cout<<"=======Default Research======="<<std::endl;
    Research researchDefault;
    researchDefault.showFullInformation(std::cout);
    std::cout<<"===Short Information===\n"<<researchDefault<<std::endl;

    std::cout<<"======First Research======"<<std::endl;
    std::deque <Publication> research1Publications;
    research1Publications.push_back(publicationDefault);
    research1Publications.push_back(publication1);
    research1Publications.push_back(publication2);
    research1Publications.push_back(publication3);
    Research research1 = Research("Research No 1", research1Publications);
    research1.showFullInformation(std::cout);
    std::cout<<"===Short Information===\n"<<research1<<std::endl;

    std::cout<<"======Second Research======"<<std::endl;
    std::deque<Publication> research2Publications;
    research2Publications.push_back(publicationCopy1);
    research2Publications.push_back(publicationAssignment3);
    research2Publications.push_back(publication4);
    research2Publications.push_back(publication5);
    Research research2 = Research("Research No 2", research2Publications);
    research2.showFullInformation(std::cout);
    std::cout<<"===Short Information===\n"<<research2<<std::endl;

    std::cout<<"======Merged Research======"<<std::endl;
    Research researchMerged = research1 + research2;
    researchMerged.showFullInformation(std::cout);
    std::cout<<"===Short Information===\n"<<researchMerged<<std::endl;
    assert(researchMerged.getListOfPublications().size() == 6 && "Duplications left!");
    std::cout<<"======Add New Research======"<<std::endl;
    Publication publication6 = Publication(student2, PUBLICATION_INTERNATIONAL, 2022, 6, 15);
    researchMerged.addNewPublication(publication6);
    assert(researchMerged.getListOfPublications().size() == 7 && "Publication is not added!");
    researchMerged.showFullInformation(std::cout);
    std::cout<<"===Short Information===\n"<<researchMerged<<std::endl;
    std::cout<<"======Delete Research (Older than 2022.01.01)======"<<std::endl;
    researchMerged.deletePublication(2022);
    assert(researchMerged.getListOfPublications().size() == 2 && "Publications are not deleted!");
    researchMerged.showFullInformation(std::cout);
    std::cout<<"===Short Information===\n"<<researchMerged<<std::endl;
}