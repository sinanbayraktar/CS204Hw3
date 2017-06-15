#include<iostream>
#include<string>
#include "studentlist.h"

using namespace std;


StudentList::StudentList()
{
	head = NULL;
	tail = NULL;
}


studentNode* StudentList :: findName (string name)
{
	studentNode *temp = head;

	while (temp != NULL)
	{
		if(temp->userName == name)
			return temp;

		temp = temp->next;
	}
	return temp;   // if student does not exist, return null
}

studentNode* StudentList :: findLocation (string name)   
{
	studentNode *temp = head;

	while (temp != NULL && temp->userName < name)
	{
		temp = temp->next;
	}
	return temp;  // temp can be null if it will be the last element
}


void StudentList :: addExam(string userName, string courseName, int grade)
{
	if (findName(userName) != NULL)  // if the student is in the list
	{
		studentNode *temp = findLocation(userName);
		examNode *ptr = temp->headExamList;

		while(ptr->next != NULL)  // finding the last element in the exam list
		{
			ptr = ptr->next;
		}

		ptr->next = new examNode(courseName, grade, NULL);
		cout<<"Exam for "<<courseName<<" with grade "<<grade<<" is added for "<<userName<<endl;
	}

	else // if student is not in the list and new node will be created
	{
		if (head == NULL)  // for the first element
		{
			examNode *ptr = NULL;
			ptr= new examNode (courseName, grade, NULL);			
			head=new studentNode(userName, ptr, NULL, NULL);
			tail = head;  // updating the tail
		}

		else if (findLocation(userName) == head)
		{
			examNode *ptr = new examNode (courseName, grade, NULL);
			studentNode *newtemp = new studentNode (userName, ptr, head, NULL);
			head->prev = newtemp;
			head = head->prev;
		}

		else if (findLocation(userName) == NULL)    // for the last element
		{
			examNode *ptr = new examNode (courseName, grade, NULL);
			studentNode *newtemp = new studentNode (userName, ptr, NULL, tail);
			tail->next = newtemp;
			tail = newtemp;   // updating the tail
		}


		else  // if student is in the middle
		{
			studentNode *temp = findLocation(userName);

			studentNode *newtemp;
			examNode *ptr = new examNode (courseName, grade, NULL);
			newtemp = new studentNode (userName, ptr, temp, temp->prev);
			temp->prev->next = newtemp;
			temp->prev = newtemp;
		}
		cout<<"A new student with user name "<<userName<<" has been added."<<endl;
		cout<<"Exam for "<<courseName<<" with grade "<<grade<<" is added for "<<userName<<endl;
	}
}

void StudentList :: deleteStudent(string userName)
{
	if (findName(userName) == NULL) // if student is not in the list
	{
		cout<<"Student does not exist in the list."<<endl;
	}

	else
	{
		studentNode *temp = findName(userName);
		examNode *ptr = temp->headExamList;
		examNode *ptr2;

		if (temp == head)  // for the first element deletion
		{
			if (temp->next)  // if head is not the only element
			{
				while (ptr)
				{
					ptr2 = ptr;
					ptr = ptr->next;
					delete ptr2;
				}

				temp->next->prev = NULL;
				head = temp->next;
				delete temp;
			}

			else  // if head is the only element in the list
			{
				while (ptr)
				{
					ptr2 = ptr;
					ptr = ptr->next;
					delete ptr2;
				}

				head = NULL;
				delete temp;
			}
		}

		else if (temp == tail)   // for the last element deletion
		{
			while (ptr)
			{
				ptr2 = ptr;
				ptr = ptr->next;
				delete ptr2;
			}

			temp->prev->next = NULL;
			tail = temp->prev;
			delete temp;
		}

		else   // middle element deletion
		{
			while (ptr)
			{
				ptr2 = ptr;
				ptr = ptr->next;
				delete ptr2;
			}

			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
		cout<<"Student "<<userName<<" has been deleted."<<endl;
	}

}

void StudentList :: deleteAll()
{
	if (head != NULL)
	{
		while (head)
		{
			studentNode *temp3 = head;
			studentNode *temp4 = head->next;

//	deleteStudent (temp3->userName) modified  starts

		studentNode *temp = findName(temp3->userName);
		examNode *ptr = temp->headExamList;
		examNode *ptr2;

		if (temp == head)  // for the first element deletion
		{
			if (temp->next)  // if not the only element
			{
				while (ptr)
				{
					ptr2 = ptr;
					ptr = ptr->next;
					delete ptr2;
				}

				temp->next->prev = NULL;
				head = temp->next;
				delete temp;
			}

			else  // if head is the only element in the list
			{
				while (ptr)
				{
					ptr2 = ptr;
					ptr = ptr->next;
					delete ptr2;
				}

				head = NULL;
				delete temp;
			}
		}

		else if (temp == tail)   // for the last element deletion
		{
			while (ptr)
			{
				ptr2 = ptr;
				ptr = ptr->next;
				delete ptr2;
			}

			temp->prev->next = NULL;
			tail = temp->prev;
			delete temp;
		}

		else   // middle element
		{
			while (ptr)
			{
				ptr2 = ptr;
				ptr = ptr->next;
				delete ptr2;
			}

			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}

// deleteStudent modified  ends here

			head = temp4;
		}
	}

}

void StudentList :: printStudent(string userName)
{
	if (findName(userName) == NULL) // if student is not in the list
	{
		cout<<"Student does not exist in the list."<<endl;
	}

	else
	{
		studentNode *temp = findName(userName);
		examNode *ptr = temp->headExamList;

		cout<<userName<<endl;
		cout<<"-------------------"<<endl;

		while (ptr)
		{
			cout<<ptr->courseName<<endl;
			cout<<ptr->grade<<endl<<endl;
			ptr = ptr->next;
		}
	}

}

void StudentList :: printAllAZ()
{
	if (head == NULL) // if no student in the list
	{
		cout<<"Student list is empty."<<endl;
	}

	else
	{
		cout<<"Printing all students in alphabetical order."<<endl;
		studentNode *temp = head;

		while (temp)
		{
			printStudent(temp->userName);
			temp = temp->next;
		}
	}
}

void StudentList :: printAllZA()
{
	if (head == NULL) // if no student in the list
	{
		cout<<"Student list is empty."<<endl;
	}

	else
	{
		cout<<"Printing all students in reverse alphabetical order."<<endl;
		studentNode *temp = tail;

		while (temp)
		{
			printStudent(temp->userName);
			temp = temp->prev;
		}
	}


}

