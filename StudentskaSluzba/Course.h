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
	void SetCourse();
	void SetFilename(std::string n);
	void Modify(char Name, int ID);
	std::string name;
	std::string file_name;
};

