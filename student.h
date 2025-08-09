#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

using namespace std;

//defining Student class
class Student {

private: //member variables
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int courseDays[3];
	DegreeProgram degreeProgram;

public:

Student(
	string studentID, 
	string firstName, 
	string lastName, 
	string emailAddress, 
	int age, 
	int daysInCourse[], 
	DegreeProgram degreeProgram);
	
	//getters
	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	const int* getDaysInCourse() const;
	DegreeProgram getDegreeProgram() const;

	//setters
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName); 
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]); 
	void setDegreeProgram(DegreeProgram degreeProgram);

	//print student info
	void print() const;

};


#endif
