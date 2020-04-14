#include "MyClass.h"
#include <iostream>

MyClass::MyClass(int v) : val(v) { }

int MyClass::getVal() { return val; }

void MyClass::setVal(int i) { val = i; }

MyClass::~MyClass() { std::cout << "~MyClass" << std::endl; }

