#include <iostream>
#include "MyVector.h"

int main(int argc, char** argv)
{
	MyVector<int> v1;

	for (unsigned int i = 0; i < 30; i++)
	{
		v1.push_back(i);
		std::cout << v1[i] << " ";
	}
	std::cout << "\n\n";
	
	for (int i = 30; i < 60; i++)
	{
		v1.push_back(i);
		std::cout << v1[i] << " ";
	}
	
	std::cout << "\n\n";

	std::cout << "v1 Front:" << v1.front() << std::endl;
	std::cout << "v1 Back:" << v1.back() << std::endl;

	
	MyVector<int> v2(3,100);

	for (int i = 0; i < 3; i++)
	{
		std::cout << v2.at(i) << " ";
	}
    
	std::cout << "\n\n";

	MyVector<int> v3(v2);

	MyVector<int> v4;

	v4 = v3;
	
	int num = 1;
	for (MyVector<int>::MyIterator i = v4.begin(); i != v4.end() ; ++i)
	{
		std::cout << *i << " ";
	}

	std::cout << "\n\n";

	v4.clear();
	v4.isEmpty() ? std::cout << "v4 is empty" : std::cout << "v4 is not empty";

	return 0;
}
