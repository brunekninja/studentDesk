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
vector<int> Actions::Selection()
{
	int c = 1;
	vector<int> arr;
	// always clear array, esspecialy if you need to repeat again
	arr.clear();

	cout << "\n za kraj pritisnite '0'\n";

	while (c != 0) {
		cin >> c;
		if (c != 0)
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

//************************************
// Convert to string array of selections int-rs from user input
//
// Method:    ConvertToString
// FullName:  Actions::ConvertToString
// Access:    public 
// Returns:   std::string
// Qualifier:
// Parameter: vector<int> * selection_array
//************************************
string Actions::ConvertToString(vector<int> selection_array)
{
	string selection_string;

	temp_array = selection_array;

	for (size_t i = 0; i < temp_array.size(); i++)
	{
		selection_string = to_string(temp_array[i]);

		if (i == temp_array.size() - 1)
		{
			temp.append(selection_string);
		}
		else
		{
			temp.append(selection_string + ",");
		}
	}

	selection_string = temp;

	//TODO clean temp string...

	return selection_string;
}
