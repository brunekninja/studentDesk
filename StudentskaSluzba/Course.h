#include <string>
#pragma once
class Course
{
protected:
	int ID;

public:
	Course();
	~Course();
	void Display();
	void Modify(char Name, int ID);
	std::string name;
};

