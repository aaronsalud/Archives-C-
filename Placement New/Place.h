#pragma once
#pragma warning(disable: 4996) // Disable deprecation

#include <iostream>
class Place
{
	char* Name;
public:
	Place() : Name(nullptr){}
	Place(char* sz) : Name(new char[strlen(sz) + 1]){ setName(sz); }
	void setName(char* sz) 
	{ 
		if (Name) delete[] Name;

		Name = new char[strlen(sz) + 1];
		strcpy(this->Name ,sz); 
	}
	const char* getName() const { return Name; }
	~Place() { delete[] this->Name; this->Name = nullptr; }
};