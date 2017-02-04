#include "LinkCourseStudent.h"
#include "Student.h"
#include "Course.h"
#include <iostream>
#include <fstream>

Course courses;
Student students;

LinkCourseStudent::LinkCourseStudent()
{
	s = 0;
}


LinkCourseStudent::~LinkCourseStudent()
{
}

/*
	get the array of user inputs
*/
vector<int> LinkCourseStudent::Selection()
{
	char c = 0;
	vector<int> arr;
	// always clear array, esspecialy if you need to repeat again
	arr.clear();

	while (c != 'k') {
		cin >> c;
		arr.push_back(c);
	}

	return arr;
}


void LinkCourseStudent::Display()
{
	cout << "\n\nOdaberite kolegij u kojeg zelite upisati studente\n";

	students.SetFilename("db/studentsdb.txt");
	courses.SetFilename("db/coursesdb.txt");

	// display all courses in console
	courses.Display();

	// get input from user, selection of course
	cin >> s;

	cout << "\n\nOdaberite brojem studente koje zelite upisati na kolegij,"
		"pritisnite enter nakon unosa\n"
		"Za kraj napisite 'k'\n\n";
	
	// display all studnets in console
	students.Display();

	char c = 0;

	selection_array = Selection();

	cout << "Za potvrdu unosa pritisnite 'y' za ponavljanje 'p' za ponistavanje 'n' \n\n";

	cin >> c;

	if (c == 'y')
	{
		cout << "Upis je uspjesno obavljen";
	}
	else if(c == 'p')
	{
		selection_array = Selection();
	}

}

void LinkCourseStudent::Link()
{

}
