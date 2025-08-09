#include <iostream>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;

// to remove students from roster
Roster::~Roster() {
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i] != nullptr) {
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
		}
	}
}

Roster::Roster() {
	for (int i = 0; i < numStudents; ++i) {
		classRosterArray[i] = nullptr;
	}
}

DegreeProgram degreeProgram;

void Roster::parseAndAdd(const string& studentData) {
	stringstream ss(studentData);
	string parseItem;
	string sData[9];
	int index = 0;

	// Parse the data into sData array
	while (getline(ss, parseItem, ',')) {
		sData[index++] = parseItem;
	}

	// Assign degree program
	DegreeProgram degreeProgram;
	if (sData[8] == "SECURITY") {
		degreeProgram = SECURITY;
	}
	else if (sData[8] == "NETWORK") {
		degreeProgram = NETWORK;
	}
	else if (sData[8] == "SOFTWARE") {
		degreeProgram = SOFTWARE;
	}

	// Call add with the parsed data
	add(
		sData[0],
		sData[1],
		sData[2],
		sData[3],
		stoi(sData[4]),
		stoi(sData[5]),
		stoi(sData[6]),
		stoi(sData[7]),
		degreeProgram
	);
}

void Roster::add(
	string studentID, 
	string firstName, 
	string lastName, 
	string emailAddress, 
	int age, 
	int daysInCourse1, 
	int daysInCourse2, 
	int daysInCourse3, 
	DegreeProgram degreeProgram)


{

	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);

	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = newStudent;
			break;
			}
		}
}

void Roster::remove(string studentID) {

	bool studentFound = false;
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
			studentFound = true;
			break;
		}
	}
	if (!studentFound) {
		cout << "Student with ID: " << studentID << " was not found." << '\n';
	}

}

void Roster::printAll() {
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			const int* days = classRosterArray[i]->getDaysInCourse();
			int sum = days[0] + days[1] + days[2];
			int average = sum / 3;
			cout << "Student " << studentID << ", averaged " << average << " days in course." << '\n';
			return;
		}
	}
	cout << "Error: Student with ID " << studentID << " not found." << '\n';
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i] != nullptr) {
			string email = classRosterArray[i]->getEmailAddress();
			if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
				cout << "Invalid email address: " << email << '\n';				
			}
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}