#include <iostream>
#include "Student.h"

using namespace std;
Student::Student(){        // constructor, assign all variable to 0 and blank ""
	totalCourseUnit = 0;  
	name = "";
	matric = "";
	courseUnit = 0;
	course = "";
}
Student::~Student(){  // destructor, set all varibale back to 0 and blank ""
	totalCourseUnit = 0;
	name = "";
	matric = "";
	courseUnit = 0;
	course = "";
}
void Student::setData(string n, string m){    // mutator, function assign name and matric
	name = n;
	matric = m;
}
void Student::setAddCourseUnit(int choice){   // mutator, function to assign the course unit of each course when add course or register course

	switch(choice) { // switch statement 
      case 1:         // if choice = 1, then courseUnit = 3;
         courseUnit = 3;
         break; 
      case 2: 
         courseUnit = 4;
         break;
      case 3: 
         courseUnit = 4;
         break; 
      case 4: 
         courseUnit = 2;
         break;
      case 5: 
         courseUnit = 2;
         break; 
      case 6: 
         courseUnit = 4;
         break; 
      case 7: 
         courseUnit = 4;
         break; 
      case 8: 
         courseUnit = 4;
         break; 
      case 9: 
         courseUnit = 4;
         break; 
      case 10: 
         courseUnit = 2;
         break; 
      case 11: 
         courseUnit = 2;
         break;
      default: cout<< " Wrong choice \n"; } 
   
}
void Student::setDropCourseUnit(int choice){  // mutator, function to assign the course unit of each course when drop course 
	
	switch(choice) {  
      case 1:           // if choice = 1, then courseUnit = -3;
         courseUnit = -3;
         break; 
      case 2: 
         courseUnit = -4;
         break;
      case 3: 
         courseUnit = -4;
         break; 
      case 4: 
         courseUnit = -2;
         break;
      case 5: 
         courseUnit = -2;
         break; 
      case 6: 
         courseUnit = -4;
         break; 
      case 7: 
         courseUnit = -4;
         break; 
      case 8: 
         courseUnit = -4;
         break; 
      case 9: 
         courseUnit = -4;
         break; 
      case 10: 
         courseUnit = -2;
         break; 
      case 11: 
         courseUnit = -2;
         break; 
      default: cout<< " Wrong choice \n"; } 
   
}
void Student::calcTotalCourseUnit(){   // function to calculate the total course unit of student
		totalCourseUnit = totalCourseUnit + courseUnit;
		
}
void Student::setCourse(int choice){          // mutator, function to get the course registered or added 
	switch(choice) { 
      case 1: // if choice = 1, course = CPT111	PRINCIPLES OF PROGRAMMING 3;
         course = "CPT111	PRINCIPLES OF PROGRAMMING	3";
         break; 
      case 2: 
         course = "CPT112	DISCRETE STRUCTURES	4";
         break;
      case 3: 
         course = "CST131 	COMPUTER ORGANISATION	4";
         break; 
      case 4: 
         course = "HFF225	PHILOSOPHY AND CURRENT ISSUES	2";
         break;
      case 5: 
         course = "WSU101	SUSTAINABILITY: ISSUES, CHALLENGES AND PROSPECTS	2";
         break; 
      case 6: 
         course = "CPC151	FUNDAMENTALS OF LOGIC AND ARTIFICIAL INTELLIGENCE	4";
         break; 
      case 7: 
         course = "CPC152	FOUNDATIONS AND PROGRAMMING FOR DATA ANALYTICS	4";
         break; 
      case 8: 
         course = "CPT113	PROGRAMMING METHODOLOGY & DATA STRUCTURES	4";
         break; 
      case 9: 
         course = "HFE224	APPRECIATION OF ETHICS AND CIVILISATIONS	4";
         break; 
      case 10: 
         course = "LKM400	BAHASA MALAYSIA IV	2";
         break; 
      case 11: 
         course = "LSP404	TECHNICAL AND ENGINEERING ENGLISH	2";
         break; 
      default: cout<< " Wrong choice \n"; } 
}
string Student::getName(){  // accessor, function to get the name of student
	return name;
}
string Student::getMatric(){   // accessor, function to get the matric of studdent
	return matric;
}
string Student::getCourse(){  // accessor, function to get the course register by student
	return course;
}

int Student::getTotalCourseUnit(){  // accessor, function to get the total course unit of student

	return totalCourseUnit;
}
