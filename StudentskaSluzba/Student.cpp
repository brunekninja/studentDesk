#include "Student.h"
#include <iostream>
#include <fstream>

/*
	Main student method, get data from user
*/
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

	ID = this->GetLastID();

	this->Write(&ID, &First, &Last, &Graduation);
}

/*
	List all students in console
*/
void Student::Display()
{

}

/*
	Get last ID from txt database file
*/
int Student::GetLastID() 
{
	int length;
	char needle = NULL;
	char id = NULL;

	std::ifstream file;
	file.open("database.txt");
	if (file.is_open())
	{
		file.seekg(0, file.end);
		length = file.tellg();
		file.clear();
		while (length-- > 0)
		{
			file.seekp(length, file.beg);
			file >> needle;
		}
	}
	else 
	{
		std::cout << "Greska prilikom otvaranja dokumenta za citanje.\n";
		return 2;
	}
	file.close();

	return id;
}

/*
	Write all inserted data from user to .txt database
*/
void Student::Write(int* ID, std::string* First, std::string* Last, int* Graduation)
{
	std::ofstream file;

	// open file for writing and append, set position at end of file
	file.open("database.txt", std::ofstream::out | std::ofstream::app);

	if (file.is_open())
	{
		file << *ID << ':';
		file << *First << '|';
		file << *Last << '|';
		file << *Graduation << '\n';
		file.close();

		std::cout << "Podaci spremljeni\n";
	}
	else
	{
		std::cout << "Greska prilikom otvaranja dokumenta za pisanje";
	}
}
