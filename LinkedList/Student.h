#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <ostream>

class Student
{
	char* FN;
	char* LN;
	int Age;

	public:
		Student(char*, char*, int);
		~Student();
		Student(const Student&);
		Student& operator=(const Student&);
		void MakeCopy(const Student &) throw(std::bad_alloc);
		friend std::ostream& operator<<(std::ostream&, const Student&);	
};

#endif