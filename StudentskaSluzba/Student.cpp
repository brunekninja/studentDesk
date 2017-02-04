#include "Student.h"
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
}

void Student::SetStudent()
{
	cout << "Unesite ime studenta: ";
	cin >> first;
	cout << "\nUnesite prezime: ";
	cin >> last;
	cout << "\nUnesite Godinu zavrsetka studija: ";
	cin >> graduation;

	Registrar student;

	ID = student.GetLastID("db/studentsdb.txt");

	student.Add(&ID, "db/studentsdb.txt", &first, &last, &graduation);
}

Student::~Student()
{

}
