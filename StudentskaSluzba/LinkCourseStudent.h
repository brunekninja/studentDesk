#include "Registrar.h"
#include <vector>

using namespace std;

#pragma once
class LinkCourseStudent : public Registrar
{
private:
	int select;
protected:
	bool modify = false;
	bool grade = false;
public:
	LinkCourseStudent();
	~LinkCourseStudent();
	void Link();
	void SetModify();
	void SetGrade();
};

