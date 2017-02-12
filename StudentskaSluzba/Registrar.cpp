#include "Registrar.h"
#include <iostream>
#include <fstream>
#include <string>

//TODO create open file method, and stream selection

Registrar::Registrar()
{
	file_name;
}


Registrar::~Registrar()
{
}

//************************************
// Get last ID from txt database file
//
// Method:    GetLastID
// FullName:  Registrar::GetLastID
// Access:    public 
// Returns:   int
// Qualifier:
// Parameter: string file_name
//************************************
int Registrar::GetLastID(string file_name)
{
	string textline;
	string frspart;
	int id = 0;

	ifstream file;
	file.open(file_name);

	if (file.is_open())
	{
		while (getline(file, textline))
		{
			frspart = textline.substr(0, textline.find(":"));
			id = stoi(frspart); // convert from string to integer
		}
		//TODO check if file is empty, assign 0 to id then
	}
	else
	{
		cout << "Greska prilikom otvaranja dokumenta za citanje.\n";
		return 2;
	}

	id++;

	file.close();

	return id;
}

//************************************
// Write all inserted data from user to .txt database
// works for both, setting courses and studnets, if some data is not sent to function ignores it
// I set all function values to default false
// Method:    Add
// FullName:  Registrar::Add
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: int * ID
// Parameter: string file_name
// Parameter: string * name
// Parameter: string * last
// Parameter: int * graduation
//************************************
void Registrar::Add(int* ID, string file_name, string* name, string* last, int* graduation)
{
	ofstream file;
	// TODO if file dont exists create one and then append text
	// open file for writing and append
	file.open(file_name, ofstream::out | ofstream::app);

	if (file.is_open())
	{
		file << *ID << ':';
		file << *name << '|';

		if (last)
			file << *last << '|';

		if (graduation)
			file << *graduation;

		file << '\n';
		file.close();

		cout << "Podaci spremljeni\n";
	}
	else
	{
		cout << "Greska prilikom otvaranja dokumenta";
	}

	file.close();
}

void Registrar::SetFilename(string n)
{
	file_name = n;
}

void Registrar::GetAttendees()
{
	string token;
	string line;
	string attendee;

	// Display atendees based on selected course
	SetFilename("db/coursesdb.txt");
	FileBuffer();
	attendee = "";

	//clean attendees vector
	attendees.clear();

	for (size_t i = 0; i < buffer.size(); i++)
	{
		size_t pos = buffer[i].find(":");
		if (pos != string::npos)
		{
			token = buffer[i].substr(0, pos);

			// only selected value, convert to string
			if (token == to_string(id_select))
			{
				size_t p = buffer[i].find("|");
				token = buffer[i].substr(p + 1, buffer[i].size());

				for (size_t x = 0; x < token.size(); x++)
				{
					if (token[x] != ',')
					{
						attendee += token[x];
					}

					if (token[x] == ',' || x == token.size() - 1)
					{
						attendees.push_back(attendee);
						attendee = "";
					}
				}
			}
		}
	}
}

void Registrar::DisplayAttendees()
{
	string token;

	SetFilename("db/studentsdb.txt");
	FileBuffer();

	for (size_t i = 0; i < buffer.size(); i++)
	{
		size_t pos = buffer[i].find(":");
		if (pos != string::npos)
		{
			token = buffer[i].substr(0, pos);

			for (size_t x = 0; x < attendees.size(); x++)
			{
				if (attendees[x] == token)
				{
					cout << buffer[i];
					cout << "\n";
				}
			}
		}
	}
}

/*
	Display all data from selected text file
*/
void Registrar::Display()
{
	string textline;
	ifstream file;
	file.open(file_name);

	if (file.is_open())
	{
		while (getline(file, textline))
		{
			cout << textline << endl;
		}
	}
	else
	{
		cout << "Greska prilikom otvaranja dokumenta.\n";
	}

	file.close();
}

void Registrar::Remove()
{
	string token;
	int c;
	fstream file;

	for (size_t a = 0; a < usr_selection.size(); a++)
	{
		c = usr_selection[a];

		for (size_t i = 0; i < buffer.size(); i++)
		{
			size_t pos = buffer[i].find(":");
			if (pos != string::npos)
			{
				token = buffer[i].substr(0, pos);

				// only selected value, convert to string
				if (token == to_string(c))
				{
					buffer[i].replace(0, buffer[i].length(), "");
					//TODO if buffer empty skip that line, on file write
				}
			}
		}
	}

	file.open(file_name, ios::out | ios::trunc);

	if (file.is_open())
	{
		// TODO create backup file in case of failure stream
		for (size_t i = 0; i < buffer.size(); i++)
		{
			if (buffer[i] != "") 
			{
				file << buffer[i];
				file << '\n';
			}
		}
		cout << "Uspjesno obrisano\n";
	}
	else
	{
		cout << "Greska prilikom otvaranja dokumenta.\n";
	}

	file.close();

}

void Registrar::FileBuffer()
{
	string textline;
	fstream file;
	buffer;

	buffer.clear();

	file.open(file_name, ios::in);

	if (file.is_open())
	{
		while (getline(file, textline))
		{
			buffer.push_back(textline);
		}
	}
	else
	{
		cout << "Greska prilikom otvaranja dokumenta.\n";
	}

	file.close();
}