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

void Course::Modify(int ID, char type)
{
	string token;
	fstream file;

	SetFilename("db/coursesdb.txt");
	FileBuffer();

	for (size_t i = 0; i < buffer.size(); i++)
	{
		size_t pos = buffer[i].find(":");
		if (pos != string::npos)
		{
			token = buffer[i].substr(0, pos);

			// only selected value, convert to string
			if (token == to_string(ID))
			{
				size_t p = buffer[i].find("|");

				//buffer[i].replace(p + 1, buffer[i].length(), selection_string = ConvertToString(usr_selection));
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

Course::~Course()
{
}