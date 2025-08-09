#include <iostream>
#include "roster.h"
using namespace std;

int main()
{
    cout << "Course Title: Scripting and Programming: Applications" << "\n";
    cout << "Language: C++" << "\n";
    cout << "Student ID: 010829466 " << "\n";
    cout << "Name: Jack Pearcy " << "\n";
    cout << "\n";

    Roster classRoster;

    const string studentData[] = {

    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Jack,Pearcy,jpea211@wgu.edu,27,30,40,50,SOFTWARE" 
    };

    for (const string& data : studentData) {
        classRoster.parseAndAdd(data);
}

    cout << "Displaying current students:" << "\n\n";

    classRoster.printAll();

    cout << "\n";

    cout << "Invalid Emails Listed Below: " << "\n\n";

    classRoster.printInvalidEmails();

    cout << "\n";

    cout << "Student's average days in course:" << "\n\n";

    for (int i = 0; i < 5; ++i) {
        if (classRoster.classRosterArray[i] != nullptr) {
            classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
        }
    }

    cout << "\n";

    cout << "Showing students enrolled in SOFTWARE: " << "\n\n";

    //Print by degree program
    classRoster.printByDegreeProgram(SOFTWARE);

    cout << "\n";

    //Remove student
    classRoster.remove("A3");

    cout << "Removing student A3. . ." << "\n\n";

    classRoster.printAll();

    cout << "\n";

    classRoster.remove("A3"); // Remove again to show error
    return 0;

}