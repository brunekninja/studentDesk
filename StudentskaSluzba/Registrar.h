#include <string>

using namespace std;

#pragma once
class Registrar
{
public:
	Registrar();
	~Registrar();
	string file_name;
	int GetLastID(string file_name);
	void Display();
	void SetFilename(string n);
	void Add(int* ID, string file_name, string* name, string* last = false, int* graduation = false);
};

