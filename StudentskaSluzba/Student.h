#pragma once
class Student
{
public:
	Student();
	void Display();
	void Write(int ID, char First, char Last, int Graduation);
	int Graduation;
	char First[16];
	char Last[16];
private:
	int ID;
};

