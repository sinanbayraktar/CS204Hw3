#include<iostream>
#include<string>

using namespace std;



struct examNode
{
	string courseName;
	int grade;
	examNode * next;
	
	// default constructor
	examNode::examNode ()
		:courseName(""), grade(0), next(NULL)
	{}

	//constructor
	examNode::examNode (string a, int i,examNode *n)
		:courseName(a), grade(i), next(n)
	{}
};

struct studentNode
{
	string userName;
	examNode * headExamList;
	studentNode * next;
	studentNode * prev;
	// constructors come here
	studentNode::studentNode ()
		:userName(""), headExamList(NULL), next(NULL), prev(NULL)
	{}

	//constructor
	studentNode::studentNode (string a, examNode *ptr, studentNode *n, studentNode *p)
		:userName(a), headExamList(ptr), next(n), prev(p)
	{}

};

class StudentList
{
public:
	StudentList();
	void addExam(string userName, string courseName, int grade);
	void deleteStudent(string userName);
	void printStudent(string userName);
	void printAllAZ(); //alphabetical order display
	void printAllZA(); //reverse alphabetical order display
	void deleteAll(); //to deallocate all dynamic data

	studentNode* findName(string name); // finding the node of that student if exists
	studentNode* findLocation(string name); 
	void SortList ();
private:
	studentNode * head;
	studentNode * tail;
	// any helper functions you see necessary
	// ...
};
