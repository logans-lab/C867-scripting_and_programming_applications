//
//  main.cpp
//  C867 Application
//
//  Created by Logan on 7/24/20.
//  Copyright © 2020 Logan. All rights reserved.
//  See course instructions below
//

#include "roster.h"
#include "student.h"
#include "degree.h"
#include <iostream>
#include <cstring>
using namespace std;

void printAll();
void printInvalidEmails();
void printDaysAvg(string studentID);
void printByDegree(DegreeProgram degreeType);
void remove(string studentID);

int main(){
    
    //initial info about me to print first
    cout << "Scripting and Programming - Applications – C867" << endl;
    cout << "Language used: C++" << endl;
    cout << "WGU Student ID: #########" << endl;
    cout << "Name of programmer: Logan" << endl;
    cout << endl;
    
    //studentData array with my information as last element in array
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Logan,Lname,fname@email.com,30,22,44,25,SOFTWARE"
    };
    
    //declare classRoster object of class Roster
    Roster classRoster;
    //declare degreeType with default
    DegreeProgram degreeType = SECURITY;
    
    //parses each student's data into 9 separate strings
    string comma (",");
    for (int i = 0; i < 5; i++){ //loops through 5 students
        //student ID
        size_t commaVar1 = studentData[i].find(comma); //  finds first comma
        string tempID = studentData[i].substr(0, 2); //  saves studentID string
        
        //first name
        size_t commaVar2 = studentData[i].find(comma, commaVar1 + 1); //  finds second comma
        int firstNameLength = static_cast<int>(commaVar2) - static_cast<int>(commaVar1) - 1; // calculates end of first name string
        string tempFirstName = studentData[i].substr(commaVar1 + 1, firstNameLength); // save first name string
        
        //last name
        size_t commaVar3 = studentData[i].find(comma, commaVar2 + 1); //  finds third comma
        int lastNameLength = static_cast<int>(commaVar3) - static_cast<int>(commaVar2) - 1; // calculates end of last name string
        string tempLastName = studentData[i].substr(commaVar2 + 1, lastNameLength); // save last name string
        
        //email address
        size_t commaVar4 = studentData[i].find(comma, commaVar3 + 1); //  finds fourth comma
        int emailLength = static_cast<int>(commaVar4) - static_cast<int>(commaVar3) - 1; // calculates end of email string
        string tempEmail = studentData[i].substr(commaVar3 + 1, emailLength); // save email string
        
        //student age
        size_t commaVar5 = studentData[i].find(comma, commaVar4 + 1); //  finds fifth comma
        int ageLength = static_cast<int>(commaVar5) - static_cast<int>(commaVar4) - 1; // calculates end of age string
        string tempAge = studentData[i].substr(commaVar4 + 1, ageLength); // save age string
        int intAge = stoi(tempAge);
        
        //days1
        size_t commaVar6 = studentData[i].find(comma, commaVar5 + 1); //  finds sixth comma
        int days1Length = static_cast<int>(commaVar6) - static_cast<int>(commaVar5) - 1; // calculates end of days1 string
        string tempDays1 = studentData[i].substr(commaVar5 + 1, days1Length); // save days1 string
        int intDays1 = stoi(tempDays1);
        
        //days2
        size_t commaVar7 = studentData[i].find(comma, commaVar6 + 1); //  finds seventh comma
        int days2Length = static_cast<int>(commaVar7) - static_cast<int>(commaVar6) - 1; // calculates end of days2 string
        string tempDays2 = studentData[i].substr(commaVar6 + 1, days2Length); // save days2 string
        int intDays2 = stoi(tempDays2);
        
        //days3
        size_t commaVar8 = studentData[i].find(comma, commaVar7 + 1); //  finds eighth comma
        int days3Length = static_cast<int>(commaVar8) - static_cast<int>(commaVar7) - 1; // calculates end of days3 string
        string tempDays3 = studentData[i].substr(commaVar7 + 1, days3Length); // save days3 string
        int intDays3 = stoi(tempDays3);
        
        //degree name
        size_t commaVar9 = studentData[i].find(comma, commaVar8 + 1); //  finds end of last string
        int degreeLength = static_cast<int>(commaVar9) - static_cast<int>(commaVar8) - 1; // calculates end of degree string
        string tempDegree = studentData[i].substr(commaVar8 + 1, degreeLength); // save degree string
        
        //set enum degreeType based on string found in array
        if (tempDegree.at(2) == 'C') {
            degreeType = SECURITY;
        }
        if (tempDegree.at(2) == 'T') {
            degreeType = NETWORK;
        }
        if (tempDegree.at(2) == 'F') {
            degreeType = SOFTWARE;
        }
        
        //add each student to classRosterArray
        classRoster.add(tempID, tempFirstName, tempLastName, tempEmail, intAge, intDays1, intDays2, intDays3, degreeType);

    }//end of for loop parser
        
    //function calls
    classRoster.printAll();
    classRoster.printInvalidEmails();
    classRoster.printDaysAvg("A1");
    classRoster.printDaysAvg("A2");
    classRoster.printDaysAvg("A3");
    classRoster.printDaysAvg("A4");
    classRoster.printDaysAvg("A5");
    cout << endl; //line break in print screen for readability
    classRoster.printByDegree(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");
    
    return 0;
}
