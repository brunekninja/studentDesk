#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma once
class Actions
{
public:
	Actions();
	~Actions();
	vector<int> usr_selection;
	string temp;
	string selection_string;
	vector<int> temp_array;
	vector<char> selection_array;
	bool check = false;
	int id_select;
	vector<int> Selection();
	string ConvertToString(vector<int> selection_array);
	void SetSelection();
	void SetCheck();
	void SetIDselect();
	bool CheckSelection();
};

