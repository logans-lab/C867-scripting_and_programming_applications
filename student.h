//
//  student.h
//  C867 Application
//
//  Created by Logan on 7/15/20.
//  Copyright © 2020 Logan. All rights reserved.
//

#pragma once
#include "degree.h"
#include <string>
using namespace std;

class Student {
public:
    // print function
    void print();
    
    //constructor
    Student(string sID, string fName, string lName, string eAddress, int sAge, int* days, DegreeProgram dP);
    
    //mutators
    void setStudentID(string a);
    void setFirstName(string b);
    void setLastName(string c);
    void setEmailAddress(string d);
    void setStudentAge(int e);
    void setDaysInCourse(int* f);
    DegreeProgram setDegreeType(DegreeProgram dT);
    
    //accessors
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getStudentAge();
    int* getDaysInCourse();
    DegreeProgram getDegreeType();

    //destructor
    ~Student();
    
private:
    //variables
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int studentAge;
    int daysInCourse[3];
    DegreeProgram degreeType;
};
