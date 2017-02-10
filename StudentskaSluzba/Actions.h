#include <iostream>
#include <vector>

using namespace std;

#pragma once
class Actions
{
public:
	Actions();
	~Actions();
	vector<char> usr_selection;
	vector<char> Selection();
	bool check = false;
	int id_select;
	void SetSelection();
	void SetCheck();
	void SetIDselect();
	bool CheckSelection();
};

