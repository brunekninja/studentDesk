#include "Registrar.h"
#include <string>

using namespace std;

#pragma once
class Course : public Registrar
{
protected:
	int ID;
	char type;
public:
	Course();
	~Course();
	string name;
	void AddCourse();
	void Modify(int ID, char type);
};

