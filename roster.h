#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <string>
using namespace std;

class Roster {

public:
    static const int numStudents = 5;
    Student* classRosterArray[numStudents];

    // Constructor
    Roster();

    // Destructor
    ~Roster();

    // Methods
    void parseAndAdd(const std::string& studentData);

    void add(
        string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        int age,
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        DegreeProgram degreeProgram
    );

    void remove(std::string studentID);
    void printAll();
    void printAverageDaysInCourse(std::string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
};

#endif