#include "Student.h"
#include "Actions.h"
#include <iostream>
#include <fstream>

// TODO check if file dont exists, create first...

/*
	Main student method, get data from user
*/
Student::Student()
{
	ID = 0;
	first;
	last;
	graduation = 0;

	std::cout << "Unesite ime studenta: ";
	std::cin >> first;
	std::cout << "\nUnesite prezime: ";
	std::cin >> last;
	std::cout << "\nUnesite Godinu zavrsetka studija: ";
	std::cin >> graduation;

	Actions student;

	ID = student.GetLastID("db/studentsdb.txt");

	student.Write(&ID, "db/studentsdb.txt", &first, &last, &graduation);
}

/*
	List all students in console
*/
void Student::Display()
{

}


Student::~Student()
{

}
