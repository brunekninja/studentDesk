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
		"10 - Prikaz kolegija;\n"
		"11 - Prikaz studenata;\n"
		"12 - Pomoc;\n"
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
				course.Display();
				cout << "\n\nOdaberite kolegij u kojeg zelite upisati studente\n";

				enroll.SetIDselect();

				cout << "\n\nOdaberite brojem studente koje zelite upisati na kolegij\n";

				student.Display();
				enroll.SetSelection();
				enroll.SetCheck();

				if (enroll.check)
					enroll.Link();					
				break;
			case 4:
				cout << "Odabrano brisanje studenata\n";
				student.Display();
				student.FileBuffer();
				cout << "Odaberite ID, brisanje odabranih ID-a/n";
				student.SetSelection();

				student.SetCheck();

				if (student.check)
					student.Remove();
				break;
			case 5:
				cout << "Odabrano brisanje kolegija\n";
				course.Display();
				course.FileBuffer();
				cout << "Odaberite ID, brisanje odabranih ID-a/n";
				course.SetSelection();

				course.SetCheck();

				if (course.check)
					course.Remove();
				break;
			case 6:
				cout << "Odabran ispis upisanih studenata\n";
				cout << "Odaberite kolegij iz kojeg zelite ispisati studente\n";

				course.Display();

				course.SetIDselect();
				course.GetAttendees();

				course.DisplayAttendees();

				cout << "\nOdaberite studente koje zelite ispisati sa kolegija\n";

				course.SetSelection();

				course.SetCheck();

				if (course.check)
					course.ModifyEnrollment(course.id_select, 'r');
				
				break;
			case 7:
				cout << "Odabran unos ocjene\n";
				cout << "Odaberite kolegij u kojeg zelite unjeti ocjene\n";

				course.Display();

				course.SetIDselect();

				course.SetCheck();

				if (course.check)
					course.GetAttendees();

					course.DisplayAttendees();

					course.ModifyEnrollment(course.id_select, 'g');
				break;
			case 8:
				cout << "Odabrana izmjena studenta\n";
				cout << "Odaberite studenta kojeg zelite izmjeniti\n";

				student.Display();

				student.SetIDselect();
				student.FileBuffer();
				student.SetCheck();

				if (student.check)
					student.Modify();
				break;
			case 9:
				cout << "Odabrana izmjena kolegija\n";
				cout << "Odaberite kolegij kojeg zelite izmjeniti\n";

				course.Display();

				course.SetIDselect();
				course.FileBuffer();
				course.SetCheck();

				if (course.check)
					course.Modify();
				break;
			case 10:
				cout << "Odabran prikaz kolegija\n";
				course.Display();
				break;
			case 11:
				cout << "Odabran prikaz studenata\n";
				student.Display();
				break;
			case 12:
				cout << "Odabrana pomoc\n";
				cout << "Za pomoc javite se na mail adresu bruno.drzanic@gmail.com, Hvala\n";
				break;

			default:
				cout << "default\n";
				break;
			}
		}
	} while (selection != 0);

	return 0;
}

