//
//  roster.h
//  C867 Application
//
//  Created by Logan on 7/15/20.
//  Copyright © 2020 Logan. All rights reserved.
//

#pragma once
#include "student.h"
#include <string>
using namespace std;

class Roster {
public:
    //add students
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeType);
    
    //print all
    void printAll();
    
    //print invalid emails
    void printInvalidEmails();
    
    //print average days in course by student ID
    void printDaysAvg(string studentID);
    
    //print student info by degree type
    void printByDegree(DegreeProgram degreeType);
    
    //remove student by student ID
    void remove(string studentID);
    
    //destructor
    ~Roster();
    
protected:
    //array of pointers
    Student* classRosterArray[5];
    int studentCounter = 0;
    int rosterSize = 5;
};
