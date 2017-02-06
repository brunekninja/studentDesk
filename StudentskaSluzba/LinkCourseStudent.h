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
	vector<int> temp_array;
	vector<int> selection_array;
	vector<string> buffer;
public:
	LinkCourseStudent();
	~LinkCourseStudent();
	string ConvertToString(vector<int>* selection_array);
	void Display();
	void Link(int* select);
	vector<int> Selection();
};

