#include "Course.h"
#include <iostream>
#include <fstream>
#include <algorithm>

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

void Course::ModifyEnrollment(int ID, char type)
{
	string token;
	string temp;
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
				token = buffer[i].substr(p + 1, buffer[i].size());

				for (size_t x = 0; x < token.size(); x++)
				{
					if (token[x] != ',')
					{
						temp += token[x];
					}

					if (token[x] == ',' || x == token.size() - 1)
					{
						temp_array.push_back(stoi(temp));
						temp = "";
					}
				}

				// 'r' for remove
				if ('r' == type)
				{
					for (size_t x = 0; x < usr_selection.size(); x++)
					{
						temp_array.erase(remove(temp_array.begin(), temp_array.end(), usr_selection[x]), temp_array.end());
					}

					buffer[i].replace(p + 1, buffer[i].length(), selection_string = ConvertToString(temp_array));
				}
				else if ('g' == type)
				{

				}
				else
				{
					break;
				}
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