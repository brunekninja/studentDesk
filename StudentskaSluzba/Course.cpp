#include "Course.h"
#include "Actions.h"
#include <iostream>
#include <fstream>

Course::Course()
{
	ID = 0;
	name;

	std::cout << "Unesite naziv kolegija: ";
	std::cin >> name;

	Actions course;

	ID = course.GetLastID("db/coursesdb.txt");

	course.Write(&ID, "db/coursesdb.txt", &name);
}


Course::~Course()
{
}


void Course::Display()
{
}


void Course::Modify(char Name, int ID)
{
}
