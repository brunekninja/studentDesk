#include "Course.h"
#pragma once
class Registrar : public Course
{
public:
	Registrar();
	~Registrar();
	void getCourse(int ID);
};

