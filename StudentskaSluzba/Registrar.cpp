#include "Registrar.h"
#include <iostream>
#include <fstream>
#include <string>

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