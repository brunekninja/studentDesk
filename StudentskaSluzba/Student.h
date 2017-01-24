#include <string>
#pragma once
class Student
{
public:
	std::string First;
	std::string Last;
	int Graduation;
	Student();
	int GetLastID();
	void Display();
	void Write(int* ID, std::string* First, std::string* Last, int* Graduation);
private:
	int ID;
};

