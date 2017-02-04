#include <string>
#include "Registrar.h"

using namespace std;

#pragma once
class Student : public Registrar
{
protected:
	int ID;

public:
	string first;
	string last;
	int graduation;
	void SetStudent();
	Student();
	~Student();
};

