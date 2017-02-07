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

void Actions::SetSelection()
{
	usr_selection = Selection();
}
