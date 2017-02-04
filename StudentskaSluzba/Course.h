#include "Registrar.h"
#include <string>

using namespace std;

#pragma once
class Course : public Registrar
{
protected:
	int ID;

public:
	Course();
	~Course();
	string name;
	void AddCourse();
	void Modify(char Name, int ID);
};

