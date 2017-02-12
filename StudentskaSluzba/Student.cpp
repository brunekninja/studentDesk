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

Student::~Student()
{
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

void Student::Modify()
{
	string token;
	string temp;
	fstream file;

	for (size_t i = 0; i < buffer.size(); i++)
	{
		size_t pos = buffer[i].find(":");
		if (pos != string::npos)
		{
			token = buffer[i].substr(0, pos);

			// only selected value, convert to string
			if (token == to_string(id_select))
			{
				cout << "Unesite ime studenta: ";
				cin >> first;
				cout << "\nUnesite prezime: ";
				cin >> last;
				cout << "\nUnesite Godinu zavrsetka studija: ";
				cin >> graduation;

				temp += first + "|" + last + "|" + to_string(graduation);

				buffer[i].replace(pos + 1, buffer[i].length(), temp);
				
			}
		}
	}

	// now open that file with trunc and replace all content with stored strings arr in buffer
	file.open(file_name, ios::out | ios::trunc);

	if (file.is_open())
	{
		// TODO create backup file in case of failure stream
		for (size_t i = 0; i < buffer.size(); i++)
		{
			file << buffer[i];
			file << '\n';
		}
	}
	else
	{
		cout << "Greska prilikom otvaranja dokumenta.\n";
	}

	file.close();
}

