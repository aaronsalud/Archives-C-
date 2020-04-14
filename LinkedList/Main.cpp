#include <iostream>
#include "LinkList.h"

int main()
{
	LinkList ll;
	ll.Add(new Student("f1", "l1", 1));
	ll.Add(new Student("f2", "l2", 2));
	ll.Add(new Student("f3", "l3", 3));
	ll.Add(new Student("f4", "l4", 4));
	ll.Add(new Student("f5", "l5", 5));
	
	LinkList l2(ll);

	std::cout << ll << endl;
	ll.sort();
	return 0;
}