//
//  main.cpp
//  Studentska Sluzba
//
//  Created by Bruno Drzanic on 02/01/2017.
//  Copyright © 2017 Bruno Drzanic. All rights reserved.
//

#include <iostream>
#include "Registrar.h"
#include "Student.h"
#include "Course.h"
#include "LinkCourseStudent.h"

using namespace std;

LinkCourseStudent enroll;
Course course;
Student student;

int selection;

int main() {

	student.SetFilename("db/studentsdb.txt");
	course.SetFilename("db/coursesdb.txt");

	// main console printout
	cout <<
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
		cin >> selection;
		cin.clear();
		cin.ignore();
		// check input is number 1 - 10
		if (selection != 0 && selection < 0 || selection > 10 || cin.fail()) {
			cout << "Unesen je krivi broj pokusajte ponovo\n";
			cin.clear();
			cin.ignore();
			selection = true;
		}
		else {
			// run selected action
			switch (selection) {
			case 0:
				cout << "IZLAZ\n";
				break;
			case 1:
				cout << "Odabran unos studenta\n";
				student.SetStudent();
				break;
			case 2:
				cout << "Odabran unos kolegija\n";
				course.AddCourse();
				break;
			case 3:
				cout << "Odabran upis studenta na kolegij\n";
				enroll.Display();
				break;
			case 4:
				cout << "Odabran ispis studenata\n";
				student.Display();
				break;
			case 5:
				cout << "Odabran ispis kolegija\n";
				course.Display();
				break;
			case 6:
				cout << "Odabran ispis upisanih studenata\n";
				break;
			case 7:
				cout << "Odabran unos ocjene\n";
				break;
			case 8:
				cout << "Odabrana izmjena studenta\n";
				break;
			case 9:
				cout << "Odabrana izmjena kolegija\n";
				break;
			case 10:
				cout << "Odabrana pomoc\n";
				break;

			default:
				cout << "default\n";
				break;
			}
		}
	} while (selection != 0);

	return 0;
}

