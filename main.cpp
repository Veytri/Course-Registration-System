/*
-This program can allow a student to do a few tasks such 
as course registration, add/drop courses, calculate total unit by course type,display all necessary information
-Program :   Computer Science Student¯s Registration System
*/
#include <iostream>
#include <fstream>
#include "Student.h"
#include "LinkedList.h"
using namespace std;

const int LINE = 11;   // global constant variable, for number of line in txt.file
void menu(){  // menu funtion for add/drop course
	system("cls");
cout<<"\t *** WELCOME ***\n";
cout<<"\t 1. Add a course\n";  
cout<<"\t 2. Drop a course\n"; 
cout<<"\t 3. Search a course\n"; 
cout<<"\t 4. Display all course\n"; 
cout<<"\t 5. Exit\n";
cout<<"\t Please enter your choice (1-5)\n"; 
}
void courseMenu(string courseCode[], string courseName[], int courseUnit[]){   // menu funtion for choosing the course
	system("cls");
cout<<"\t *** WELCOME ***\n";
 for(int i = 0; i < LINE; i++){
 	cout << "\t" << i + 1 << ". "<< courseCode[i] << " " << courseName[i] << " " << courseUnit[i] << endl; 
 }
cout<<"\tPlease enter your choice (1-11)\n"; 
}

int main(){
	LinkedList list;    // list as object type class linked list 
	Student student;   // object student of clas Student
	// name and matric for student, array courseCode is the code of course, array courseName is the name of course
    string name, matric, courseCode[LINE], courseName[LINE]; 
    int choice, courseChoice, courseUnit[LINE];  // choice is whether want to add/drop course, courseChoice is choose for chourse, array courseUnit is unit for each course
    ifstream myFile;
	myFile.open("Courses.txt");  // open file name "Courses.txt"
		if (myFile.fail())  // determine whether file can open successfully or not
   {
       cout << "Error in opening source file...." << endl;  // display when fail to open file
   }
    for(int i = 0; i < LINE; i++){  // loop to input information from txt.file to each of array
       getline(myFile, courseCode[i], '\t');     
       getline(myFile, courseName[i], '\t');      
       myFile >> courseUnit[i];          
       myFile.ignore(); 
	}
    cout << "What is your name:";   // prompt student to enter the name
    getline(cin, name);
    cout << "What is your matric number:"; // prompt student to enter the matric number
    cin >> matric;
    student.setData(name, matric);
    do{   // do while loop, at lease loop one time
menu(); // call menu funtion for add/drop course
cin>>choice;  // cin the choice for add/drop course
switch(choice) {  // switch
      case 1: 
         cout<< "Add a new course :";    // append a new course
         courseMenu(courseCode, courseName, courseUnit); //call and pass value to course menu function 
         cin >> courseChoice;
         while(courseChoice < 1 || courseChoice > 11){   // input valitation, prompt student to give a correct input when not give a true choice
		cout << "Wrong choice" << endl;
		cout << "Please enter the correct choice:";
		cin >> courseChoice; 
	}
         student.setAddCourseUnit(courseChoice); // pass the choice to setAddCourseUnit funtion
         student.setCourse(courseChoice); // pass the choice to setAddCourseUnit funtion
         student.calcTotalCourseUnit();  // call to calcalate the total course unit
         list.appendNode(student.getCourse());    //append the course in linked list    
         break;    
   case 2: 
      cout<<"\t\n Drop a course \n";  //delete a course
      courseMenu(courseCode, courseName, courseUnit);
      cin >> courseChoice;
      while(courseChoice < 1 || courseChoice > 11){
		cout << "Wrong choice" << endl;
		cout << "Please enter the correct choice:";
		cin >> courseChoice; 
	}
      student.setDropCourseUnit(courseChoice);
      student.setCourse(courseChoice);
      student.calcTotalCourseUnit();
      list.deleteNode(student.getCourse());  // delete the course in linkedd list
         break;
    case 3: 
          cout<<"\t\n Search a course: ";  //search course
          courseMenu(courseCode, courseName, courseUnit);
          cin >> courseChoice;
          while(courseChoice < 1 || courseChoice > 12){
		cout << "Wrong choice" << endl;
		cout << "Please enter the correct choice:";
		cin >> courseChoice; 
	}
          student.setCourse(courseChoice);
          list.searchNode(student.getCourse());// search the course in linkedd list
          break; 
    case 4: //display all the courses 
          cout << "Name: " << student.getName() << "  "<<"Matric: " << student.getMatric() << endl; // display the name of student and matric number
          cout << "Course Resgister" << endl;
          cout << "-----------" << endl;
          list.displayList();  // display all the courses in the linked list
          cout << "Now, the total course unit is " << student.getTotalCourseUnit() << endl;  // display the total course unit of student
		  system("pause");  
          break; 
    case 5: break;
    
    default: cout << "Wrong choice \n";   // input validation
             cout <<"Please enter the correct choice\n";
             cout <<"Press enter\n";
             cin.ignore();
	         cin.get();
			 break;}
   }while (choice!=5);  // break the do while loop when choice = 5
   cout<<"\n End of Program"; 
	return 0;
}
