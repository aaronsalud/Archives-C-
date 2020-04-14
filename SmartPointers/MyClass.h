#ifndef __MYCLASS_H__
#define __MYCLASS_H__

class MyClass
{
	int val;
	
public:
	MyClass(int);
	friend class MyClassPtr;
	int getVal();
	~MyClass();
	void setVal(int i);
};
#endif