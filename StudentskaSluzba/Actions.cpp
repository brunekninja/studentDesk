#include "Actions.h"

Actions::Actions()
{
}


Actions::~Actions()
{
}

//************************************
// Get the array of user inputs
//
// Method:    Selection
// FullName:  Actions::Selection
// Access:    public 
// Returns:   std::vector<int>
// Qualifier:
//************************************
vector<char> Actions::Selection()
{
	char c = 0;
	vector<char> arr;
	// always clear array, esspecialy if you need to repeat again
	arr.clear();

	cout << "\n za kraj pritisnite 'k'\n";

	while (c != 'k') {
		cin >> c;
		if (c != 'k')
			arr.push_back(c);
	}

	return arr;
}

bool Actions::CheckSelection()
{
	char c;

	cout << "Za potvrdu unosa pritisnite 'y', za ponistavanje 'n' \n\n";

	cin >> c;

	if (c == 'y') 
		check = true;

	return check;
}

void Actions::SetSelection()
{
	usr_selection = Selection();
}

void Actions::SetCheck()
{
	check = CheckSelection();
}

void Actions::SetIDselect()
{
	cin >> id_select;
}
