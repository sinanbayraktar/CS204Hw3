#include <iostream>
#include <string>
#include<sstream>
#include<fstream>
#include "studentlist.h"

using namespace std;


int main()
{
	StudentList myList;
	
	while (true)
	{
		int a;   // option number
		cout<<endl<<"Exam Grades\n-----------------------------------\nPlease select one option [1..7]:\n1. Load information from a file\n2. Add student and exam manually\n3. Delete a student\n4. Display exam grades of a student\n5. Display exam grades of all students in alphabetical order\n6. Display exam grades of all students in reverse alphabetical order\n7. Exit\nYour choice:"<<endl;
		cin>>a;		

		if (a == 1)   // Load driver names and points from a file option
		{
			string fileName;
			cout<<"Enter the name of the file: ";
			cin>>fileName;

			ifstream input;
			input.open(fileName);

			while(input.fail())  // error message for wrong file names
			{
				cout<< "Error:Could not open the file "<< fileName<< endl;

				cout<<"Enter the input file name"<< endl;
				cin>>fileName;

				ifstream input;
				input.open(fileName);
			}

			string line;
			while(!input.eof())
			{
				getline(input, line);
				stringstream ss(line);

				string userName;
				string courseName;
				int grade;

				while (ss >> userName >> courseName >> grade)
				{
					myList.addExam (userName, courseName, grade);
				}
			}
			cout<<"File has been processed."<<endl;
		}

		else if (a == 2)   // Add student and exam manually
		{
			string newname;
			string newcourse;
			int newgrade;

			cout<<"Please enter the user name of the student: "<<endl;
			cin>>newname;
			cout<<"Please enter the name of the course: "<<endl;
			cin>>newcourse;
			cout<<"Please enter the grade[0..100]"<<endl;
			cin>>newgrade;

			myList.addExam (newname, newcourse, newgrade);

		}

		else if (a == 3)    // Delete a student
		{
			string studentname;
			cout<<"Please enter the user name of the student"<<endl;
			cin>>studentname;

			myList.deleteStudent (studentname);
		}

		else if (a == 4)   // Display exam grades of a student
		{
			string studentname;
			cout<<"Please enter the user name of the student"<<endl;
			cin>>studentname;

			myList.printStudent (studentname);
		}

		else if (a == 5)   // Display exam grades of all students in alphabetical order
		{
			myList.printAllAZ ();
		}

		else if (a == 6)   // Display exam grades of all students in reverse alphabetical order
		{
			myList.printAllZA();
		}

		else if (a == 7)   // Exit option
		{
			myList.deleteAll ();

			cin.ignore();
			cin.get();
			return 0; 
		}
	}
}
