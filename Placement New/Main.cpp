#include <iostream>
#include "Place.h"
#include <new>

int main()
{
	/*
	// Placement New C-Style (malloc and free method)
	Place* p = reinterpret_cast<Place*>(malloc(sizeof(Place)*6));

	for (int i = 0; i < 6; ++i) { new (p + i) Place("Place"); }

	(p + 3)->~Place();
	(p + 4)->~Place();

	new (p + 3) Place("Place 4");
	new (p + 4) Place("Place 5");

	for (int i = 0; i < 6; ++i)
	{
		std::cout << (p + i)->getName() << std::endl;
		(p + i)->~Place();
	}

	free(p);
	*/
	
	/*
	// Placement New C++ Style (::operator new() and ::operator delete() method)
	Place* p1 = (Place*) ::operator new(sizeof(Place)*6);

	for (int i = 0; i < 6; ++i) { new (p1 + i) Place("Place"); }

	(p1 + 3)->~Place();
	(p1 + 4)->~Place();

	new (p1 + 3) Place("Place 4");
	new (p1 + 4) Place("Place 5");

	for (int i = 0; i < 6; ++i)
	{
		std::cout << (p1 + i)->getName() << std::endl;
		(p1 + i)->~Place();
	}

	::operator delete(p1);
	*/

	// Placement new using the new operator and delete [ ] operator with explicit destructor call
	Place* p2 = new Place[6];

	for (int i = 0; i < 6; ++i) { (p2 + i)->setName("Place"); }

	(p2 + 3)->~Place();
	(p2 + 4)->~Place();

	(p2 + 3)->setName("place 4");
	(p2 + 4)->setName("place 5");

	for (int i = 0; i < 6; ++i)
	{
		std::cout << (p2 + i)->getName() << std::endl;
	}

	delete [] p2;
	return 0;
}