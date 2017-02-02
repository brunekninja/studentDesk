#include "LinkCourseStudent.h"
#include "Student.h"
#include "Course.h"
#include <iostream>
#include <fstream>


LinkCourseStudent::LinkCourseStudent()
{
}


LinkCourseStudent::~LinkCourseStudent()
{
}


void LinkCourseStudent::Display()
{
	std::cout << "\n\nOdaberite kolegij u kojeg zelite upisati studente\n";

	Course courses;
	Student students;

	students.SetFilename("db/studentsdb.txt");
	courses.SetFilename("db/coursesdb.txt");

	courses.Display();

	std::cout << "\n\nOdaberite brojem studente koje zelite upisati na kolegij, ako ih postoji veci broj odvojite ih zarezom\n";

	students.Display();
}
