//
//  main.cpp
//  Studentska Sluzba
//
//  Created by Bruno Drzanic on 02/01/2017.
//  Copyright © 2017 Bruno Drzanic. All rights reserved.
//

#include <iostream>
#include "Actions.h"
#include "Student.h"
#include "Course.h"

using namespace std;

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
		// check input is number 1 - 10
		if (selection != 0 && selection < 0 || selection > 10 || std::cin.fail()) {
			std::cout << "Unesen je krivi broj pokusajte ponovo\n";
			std::cin.clear();
			std::cin.ignore();
			selection = true;
		}
		else {
			// run selected action
			switch (selection) {
			case 0:
				std::cout << "IZLAZ\n";
				break;
			case 1:
				std::cout << "Odabran unos studenta\n";
				Student();
				break;
			case 2:
				std::cout << "Odabran unos kolegija\n";
				Course();
				break;
			case 3:
				std::cout << "Odabran upis studenta na kolegij\n";
				break;
			case 4:
				std::cout << "Odabran ispis studenata\n";
				break;
			case 5:
				std::cout << "Odabran ispis kolegija\n";
				break;
			case 6:
				std::cout << "Odabran ispis upisanih studenata\n";
				break;
			case 7:
				std::cout << "Odabran unos ocjene\n";
				break;
			case 8:
				std::cout << "Odabrana izmjena studenta\n";
				break;
			case 9:
				std::cout << "Odabrana izmjena kolegija\n";
				break;
			case 10:
				std::cout << "Odabrana pomoc\n";
				break;

			default:
				std::cout << "default\n";
				break;
			}
		}
	} while (selection != 0);

	return 0;
}

