#include <string>
#include "Course.h"

#pragma once
class Student : public Course
{
protected:
	int ID;

public:
	std::string first;
	std::string last;
	int graduation;
	void SetStudent();
	Student();
	~Student();
};

