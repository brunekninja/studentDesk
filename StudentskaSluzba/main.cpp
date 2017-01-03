//
//  main.cpp
//  Studentska Sluzba
//
//  Created by Bruno Drzanic on 02/01/2017.
//  Copyright © 2017 Bruno Drzanic. All rights reserved.
//

#include <iostream>

int selection;

int main() {

	// main console printout
	std::cout <<
		"UNESITE NAREDBU:\n"
		"1 - Unos studenta;\n"
		"2 - Unos kolegija;\n"
		"3 - Upis studenta na kolegij;\n"
		"4 - Ispis studenata;\n"
		"5 - Ispis kolegija;\n"
		"6 - Ispisi upisane studente;\n"
		"7 - Unesi ocjenu;\n"
		"8 - Izmjeni studenta;\n"
		"9 - Izmjeni kolegij;\n"
		"10 - Pomoc;\n"
		"0 - Izlaz;\n";

	do {
		// get input from user
		std::cin >> selection;

		switch (selection) {
		case 1:
			std::cout << "Odabran unos studenta\n";
			break;

		default:
			std::cout << "default\n";
			break;
		}
	} while (selection != 0);

	return 0;
}