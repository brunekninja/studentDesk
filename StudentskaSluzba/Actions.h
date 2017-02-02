#include <string>
#pragma once
class Actions
{
public:
	Actions();
	~Actions();
	int GetLastID(std::string file_name);
	void Write(int* ID, std::string file_name, std::string* name, std::string* last = false, int* graduation = false);
};

