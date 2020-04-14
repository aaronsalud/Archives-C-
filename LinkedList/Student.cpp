#include "Student.h"

#include <ostream>
Student::Student(char* f, char* l, int a)
{
	this->FN = f;
	this->LN = l;
	this->Age = a;
}

Student::Student(const Student& s)
{
	MakeCopy(s);
}

Student::~Student()
{
	delete FN;
	delete LN;
}

Student& Student::operator=(const Student&)
{
	

}

void Student::MakeCopy(const Student& s)
{
	Student* newStudent = new Student(new char(*(s.FN)), new char(*(s.LN)), s.Age);
}

std::ostream& operator<<(std::ostream& os, const Student& s) 
{


}