//
//  roster.cpp
//  C867 Application
//
//  Created by Logan on 7/15/20.
//  Copyright © 2020 Logan. All rights reserved.
//

#include "student.h"
#include "roster.h"
#include "degree.h"
#include <iostream>
#include <string>
using namespace std;

//add students
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeType){
    
    int daysArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    //creating new student objects for each student, each time add() is run
    classRosterArray[studentCounter] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeType);
    
    //set values for each student
    classRosterArray[studentCounter]->setStudentID(studentID);
    classRosterArray[studentCounter]->setFirstName(firstName);
    classRosterArray[studentCounter]->setLastName(lastName);
    classRosterArray[studentCounter]->setEmailAddress(emailAddress);
    classRosterArray[studentCounter]->setStudentAge(age);
    classRosterArray[studentCounter]->setDaysInCourse(daysArray);
    classRosterArray[studentCounter]->setDegreeType(degreeType);
    studentCounter++; //increment counter for next incoming student
}

//print all students by looping through each student in classRosterArray
void Roster::printAll(){
    cout << "All students:" << endl;
    for (int i = 0; i < rosterSize; i++){
        classRosterArray[i]->print();
    }
    cout << endl;
}

//print invalid email addresses
void Roster::printInvalidEmails(){
    cout << "Invalid email addresses: " << endl;
    //test for valid email address
    for (int i = 0; i < 5; i++){
        string emailTest = classRosterArray[i]->getEmailAddress();
        
        size_t spaceInEmail = emailTest.find(' ');
        size_t atInEmail = emailTest.find('@');
        size_t periodInEmail = emailTest.find('.', atInEmail);

        //is there an @ symbol in the email?
        if (atInEmail != string::npos){
            //yes, continue to next test
            //is there a period in the email after the @ symbol?
            if (periodInEmail != string::npos) {
                //yes, continue to next test
                //is there a space in the email?
                if (spaceInEmail != string::npos) {
                    //yes there is a space, print invalid email
                    cout << classRosterArray[i]->getEmailAddress() << endl;
                }
                //no space, has @, and period after @, email is valid - do nothing
            }
            //no period after @, print invalid email
            else {
                cout << classRosterArray[i]->getEmailAddress() << endl;
            }
        }
        //no @ symbol, print invalid email
        else {
            cout << classRosterArray[i]->getEmailAddress() << endl;
        }
    }
    cout << endl;
}

//print average days in course by student ID
void Roster::printDaysAvg(string idToCompare){
    //compare input student ID to students in classRosterArray and return array of daysInCourse[3]
    for (int i = 0; i < 5; i++) {
        if (idToCompare == classRosterArray[i]->getStudentID()) {
            int* avgDaysArray = classRosterArray[i]->getDaysInCourse();
            //calculate average
            int avg = (avgDaysArray[0] + avgDaysArray[1] + avgDaysArray[2]) / 3;
            //print average number of days by student ID
            cout << "Student: " << idToCompare << "\tAverage number of days in 3 courses: " << avg << endl;
        }
    }
}

//print student info by degree type
void Roster::printByDegree(DegreeProgram degreeType) {
    //converting degree enums to strings in order to print
    string degreeTest;
    switch (degreeType) {
      case SECURITY:
          degreeTest = "SECURITY";
          break;
      case NETWORK:
          degreeTest = "NETWORK";
          break;
      case SOFTWARE:
          degreeTest = "SOFTWARE";
          break;
    }
    //compare each student's degree program to input type
    cout << "Students enrolled in the " << degreeTest << " program:" << endl;
    for (int i = 0; i < 5; i++) {
        if (degreeType == classRosterArray[i]->getDegreeType()) {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}

//remove student from classRoster by student ID
void Roster::remove(string idToCompare){
    cout << "Removing student: " << idToCompare << endl;
    bool idFound = false;
    int indexNum = 0;
    for (int i = 0; i < rosterSize; i++) {
        //is student in classRoster?
        if (idToCompare == classRosterArray[i]->getStudentID()) {
            //yes, change idFound to true
            idFound = true;
            indexNum = i;
        }
    }
    //if student ID is found in classRosterArray (idFound is true), delete student
    if (idFound == true) {
        delete classRosterArray[indexNum];
        cout << "Student " << idToCompare << " was removed." << endl;
        //move the remaining students to the left in classRosterArray
        for (int i = indexNum; i < rosterSize - 1; i++) {
            classRosterArray[i] = classRosterArray[i+1];
        }
        //make array smaller
        rosterSize--;
    }
    //if student ID is not found, print "not found" message
    else {
        cout << "Student " << idToCompare << " was not found in the roster." << endl;
    }
    cout << endl;
}

//destructor - loop through all student objects and delete
Roster::~Roster(){
    for (int i = 0; i < rosterSize; i++) {
        delete classRosterArray[i];
    }
}
