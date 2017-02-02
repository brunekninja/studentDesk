#include "Actions.h"
#include <iostream>
#include <fstream>
#include <string>


Actions::Actions()
{
}


Actions::~Actions()
{
}

/*
	Get last ID from txt database file
*/
int Actions::GetLastID(std::string file_name)
{
	std::string textline;
	std::string frspart;
	int id = 0;

	std::ifstream file;
	file.open(file_name);

	if (file.is_open())
	{
		while (std::getline(file, textline))
		{
			frspart = textline.substr(0, textline.find(":"));
			id = std::stoi(frspart); // convert from string to integer
		}
		//TODO check if file is empty, assign 0 to id then
	}
	else
	{
		std::cout << "Greska prilikom otvaranja dokumenta za citanje.\n";
		return 2;
	}

	id++;

	file.close();

	return id;
}


/*
	Write all inserted data from user to .txt database
*/
void Actions::Write(int* ID, std::string file_name, std::string* name, std::string* last, int* graduation)
{
	std::ofstream file;
	// TODO if file dont exists create one and then append text
	// open file for writing and append
	file.open(file_name, std::ofstream::out | std::ofstream::app);

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

		std::cout << "Podaci spremljeni\n";
	}
	else
	{
		std::cout << "Greska prilikom otvaranja dokumenta";
	}
}