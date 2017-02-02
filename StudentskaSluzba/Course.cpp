#include "Course.h"
#include "Actions.h"
#include <iostream>
#include <fstream>

Course::Course()
{
	ID = 0;
	file_name;
	name;
}

void Course::SetFilename(std::string n)
{
	file_name = n;
}

void Course::SetCourse() 
{
	std::cout << "Unesite naziv kolegija: ";
	std::cin >> name;

	Actions course;

	ID = course.GetLastID("db/coursesdb.txt");

	course.Write(&ID, "db/coursesdb.txt", &name);
}

void Course::Display()
{
	std::string textline;
	std::ifstream file;
	file.open(file_name);

	if (file.is_open())
	{
		while (std::getline(file, textline))
		{
			std::cout << textline << std::endl;
		}
	}
	else
	{
		std::cout << "Greska prilikom otvaranja dokumenta.\n";
	}

	file.close();
}


void Course::Modify(char Name, int ID)
{
}

Course::~Course()
{
}