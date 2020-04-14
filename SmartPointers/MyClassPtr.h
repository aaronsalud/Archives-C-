#ifndef __MYCLASSPTR_H__
#define __MYCLASSPTR_H__

#include "MyClass.h"

class MyClassPtr
{
	MyClass* p;
	
	public:
		MyClassPtr(MyClass*);
	    MyClass* operator->();
		~MyClassPtr();
};
#endif