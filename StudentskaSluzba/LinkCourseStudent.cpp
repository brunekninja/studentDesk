#include "LinkCourseStudent.h"
#include "Student.h"
#include "Course.h"
#include <iostream>
#include <fstream>

Course courses;
Student students;
Registrar registrar;

LinkCourseStudent::LinkCourseStudent()
{
	select = 0;
}


LinkCourseStudent::~LinkCourseStudent()
{
}


//************************************
// Convert to string array of selections int-rs from user input
//
// Method:    ConvertToString
// FullName:  LinkCourseStudent::ConvertToString
// Access:    public 
// Returns:   std::string
// Qualifier:
// Parameter: vector<int> * selection_array
//************************************
string LinkCourseStudent::ConvertToString(vector<char> selection_array)
{
	string selection_string;

	temp_array = selection_array;

	for (size_t i = 0; i < temp_array.size(); i++)
	{
		selection_string = temp_array[i];

		if (i == temp_array.size() - 1)
		{
			temp.append(selection_string);
		}
		else 
		{
			temp.append(selection_string + ",");
		}
	}

	selection_string = temp;

	//TODO clean temp string...

	return selection_string;
}

void LinkCourseStudent::SetModify()
{
	modify = true;
}

void LinkCourseStudent::SetGrade()
{
	grade = true;
}

//************************************
// Link selected course with students
// stores all content from file in array, replaces string that is needed
// clears the file and stores modified content form array in file
//
// Method:    Link
// FullName:  LinkCourseStudent::Link
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: int * select
//************************************
void LinkCourseStudent::Link()
{
	string token;
	fstream file;

	registrar.SetFilename("db/coursesdb.txt");
	registrar.FileBuffer();

	for (size_t i = 0; i < registrar.buffer.size(); i++)
	{	
		size_t pos = registrar.buffer[i].find(":");
		if (pos != string::npos)
		{
			token = registrar.buffer[i].substr(0, pos);

			// only selected value, convert to string
			if (token == to_string(id_select))
			{
				size_t p = registrar.buffer[i].find("|");

				registrar.buffer[i].replace(p + 1, registrar.buffer[i].length(), selection_string = ConvertToString(usr_selection));
			}
		}
	}

	// now open that file with trunc and replace all content with stored strings arr in buffer
	file.open(registrar.file_name, ios::out | ios::trunc);

	if (file.is_open())
	{
		// TODO create backup file in case of failure stream
		for (size_t i = 0; i < registrar.buffer.size(); i++)
		{
			file << registrar.buffer[i];
			file << '\n';
		}
	}
	else
	{
		cout << "Greska prilikom otvaranja dokumenta.\n";
	}

	file.close();
}
