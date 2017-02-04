#include "Registrar.h"
#include <vector>

using namespace std;

#pragma once
class LinkCourseStudent : public Registrar
{
private:
	int s;
	vector<int> selection_array;
public:
	LinkCourseStudent();
	~LinkCourseStudent();
	void Display();
	void Link();
	vector<int> Selection();
};

