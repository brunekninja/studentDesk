#include "Student.h"
#include <iostream>


Student::Student()
{
	ID = 0;
	First;
	Last;
	Graduation = 0;

	std::cout << "Unesite ime studenta: ";
	std::cin >> First;
	std::cout << "\nUnesite prezime: ";
	std::cin >> Last;
	std::cout << "\nUnesite Godinu zavrsetka studija: ";
	std::cin >> Graduation;

	std::cout << First;
	std::cout << Last;
	std::cout << Graduation;
}


void Student::Display()
{
}


void Student::Write(int ID, char First, char Last, int Graduation)
{
	

}
