#include "Actions.h"
#include <string>
#include <vector>

using namespace std;

#pragma once
class Registrar : public Actions
{
public:
	Registrar();
	~Registrar();
	string file_name;
	vector<string> buffer;
	vector<string> attendees;
	int GetLastID(string file_name);
	void Display();
	void SetFilename(string n);
	void Add(int* ID, string file_name, string* name, string* last = false, int* graduation = false);
	void Remove();
	void FileBuffer();
	void GetAttendees();
	void DisplayAttendees();
};

