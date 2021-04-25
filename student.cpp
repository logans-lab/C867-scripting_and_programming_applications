//
//  student.cpp
//  C867 Application
//
//  Created by Logan on 7/15/20.
//  Copyright © 2020 Logan. All rights reserved.
//

#include "student.h"
#include "degree.h"
#include <iostream>
using namespace std;

//constructor
Student::Student(string sID, string fName, string lName, string eAddress, int sAge, int* days, DegreeProgram dP) {
    studentID = sID;
    firstName = fName;
    lastName = lName;
    emailAddress = eAddress;
    studentAge = sAge;
    daysInCourse[0] = days[0];
    daysInCourse[1] = days[1];
    daysInCourse[2] = days[2];
    degreeType = dP;
}

//print function per student
void Student::print(){
    //converting degree enums to strings in order to print
    string printDegree;
    switch (degreeType) {
      case SECURITY:
          printDegree = "SECURITY";
          break;
      case NETWORK:
          printDegree = "NETWORK";
          break;
      case SOFTWARE:
          printDegree = "SOFTWARE";
          break;
    }
    int* dayArray = getDaysInCourse();
    //tab separated list of student data
    cout << getStudentID() << "\tFirst Name: " << getFirstName() << "\tLast Name: " << getLastName() << "\tAge: " << getStudentAge() << "\tDays In Course: {" << dayArray[0] << ", " << dayArray[1] << ", " << dayArray[2] << "} Degree Program: " << printDegree << "." << endl;
}

//mutators
void Student::setStudentID(string a){
    studentID = a;
}
void Student::setFirstName(string b){
    firstName = b;
}
void Student::setLastName(string c){
    lastName = c;
}
void Student::setEmailAddress(string d){
    emailAddress = d;
}
void Student::setStudentAge(int e){
    studentAge = e;
}
void Student::setDaysInCourse(int* f){
    for(int i = 0; i < 3; i++){
        daysInCourse[i] = f[i];
    }
}
DegreeProgram Student::setDegreeType(DegreeProgram dT){
    return degreeType = dT;
}

//accessors
string Student::getStudentID(){
    return studentID;
}
string Student::getFirstName(){
    return firstName;
}
string Student::getLastName(){
    return lastName;
}
string Student::getEmailAddress(){
    return emailAddress;
}
int Student::getStudentAge(){
    return studentAge;
}
int* Student::getDaysInCourse(){
    return daysInCourse;
}
DegreeProgram Student::getDegreeType(){
    return degreeType;
}

//destructor
Student::~Student(){
    
}
