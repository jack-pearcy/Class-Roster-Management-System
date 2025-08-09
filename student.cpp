#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

const string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };


// Constructor definition
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;

    // Copy daysInCourse array to member array courseDays
    for (int i = 0; i < 3; ++i) {
        this->courseDays[i] = daysInCourse[i];
    }

    this->degreeProgram = degreeProgram;
}

//definitions for getters
string Student::getStudentID() const {

	return studentID;

}

string Student::getFirstName() const {

	return firstName;

}

string Student::getLastName() const {

	return lastName;

}

string Student::getEmailAddress() const {

	return emailAddress;

}

int Student::getAge() const {

	return age;

}

const int* Student::getDaysInCourse() const {
    return courseDays;
}

DegreeProgram Student::getDegreeProgram() const {

	return degreeProgram;

}

//definitions for setters

void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysInCourse(int daysInCourse[]) {
    for (int i = 0; i < 3; ++i) {
        this->courseDays[i] = daysInCourse[i];
    }
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

// Definition for print function
void Student::print() const {
    cout << "Student ID: " << studentID << "\t"
        << "First Name: " << firstName << "\t"
        << "Last Name: " << lastName << "\t"
        << "Email: " << emailAddress << "\t"
        << "Age: " << age << "\t"
        << "Days In Course: {" << courseDays[0] << ", " << courseDays[1] << ", " << courseDays[2] << "}\t"
        << "Degree Program: " << degreeProgramStrings[static_cast<int>(degreeProgram)];
        cout << "\n";
}
