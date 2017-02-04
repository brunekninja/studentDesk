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

/*
	Get last ID from txt database file
*/
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


/*
	Write all inserted data from user to .txt database
	works for both, setting courses and studnets, if some data is not sent to function ignores it
	I have set all function values to default false
*/
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
}

void Registrar::SetFilename(string n)
{
	file_name = n;
}

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