#include <iostream>
#ifndef STUDENT_H
#define STUDENT_H
using namespace std;
class Student{      // class Student
	private: // private data
		string name;   // name of student
		string matric; // matric of student
		int totalCourseUnit;  // total course unit student take
		int courseUnit;   // course unit for each course
		string course; // name of course
	public:  // public data
		Student(); // constructor
		~Student();  // destructor
		void setData(string, string); // mutator, function assign name and matric
		void setAddCourseUnit(int);  // mutator, function assign course unit when add course
		void setDropCourseUnit(int);  // mutator, function assign course unit when drop course
		void setCourse(int);  // mutator, function assign course name
		string getName(); // accessor, function to get the name of student
        string getMatric();  // accessor, function to get the matric of student
        string getCourse(); // accessor, function to get the course register
        int getTotalCourseUnit();  // accessor, function to get the total course unit that student take
        void calcTotalCourseUnit();  // function to calculate the total course unit
};
#endif
