#include "Registrar.h"
#include <vector>

using namespace std;

#pragma once
class LinkCourseStudent : public Registrar
{
private:
	int select;
	string temp;
	string selection_string;
	vector<char> temp_array;
	vector<char> selection_array;
protected:
	bool modify = false;
	bool grade = false;
public:
	LinkCourseStudent();
	~LinkCourseStudent();
	string ConvertToString(vector<char> selection_array);
	void Link();
	void SetModify();
	void SetGrade();
};

