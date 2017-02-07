#include "Course.h"
#include <iostream>
#include <fstream>

Registrar course;

Course::Course()
{
	ID = 0;
	name;
}

void Course::AddCourse() 
{
	cout << "Unesite naziv kolegija: ";
	cin >> name;

	ID = course.GetLastID("db/coursesdb.txt");

	course.Add(&ID, "db/coursesdb.txt", &name);
}

void Course::Modify(char Name, int ID)
{
}

Course::~Course()
{
}