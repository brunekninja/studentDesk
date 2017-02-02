#include <string>
#pragma once
class Student
{
protected:
	int ID;

public:
	std::string first;
	std::string last;
	int graduation;
	Student();
	~Student();
	void Display();
};

