#include "MyClassPtr.h"
#include <iostream>

MyClassPtr::MyClassPtr(MyClass * o) : p(o)  { }

MyClass* MyClassPtr::operator->()
{
	return p;
}

MyClassPtr::~MyClassPtr()
{
	delete p;
	std::cout << "~MyClassPtr" << std::endl;
}