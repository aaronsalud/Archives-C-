#include <iostream>

#include "MyClassPtr.h"

int main(int argc, char** argv)
{
	MyClassPtr cls(new MyClass(5));

	std::cout << cls->getVal() << std::endl;
	
	cls->setVal(7);
	std::cout << cls->getVal();

	std::cin.get();
	
	return 0;
}