#ifndef __MYVECTOR_H__
#define __MYVECTOR_H__
#define MIN_CAP 30

#include <iostream>

template <class T>
class MyVector
{
	T* _data;
	unsigned int _size;
	unsigned int _capacity;
	
	void insertData(unsigned int, T);
	void copyArray(T*&, const T*);
	void MakeCopy(const MyVector&);

public:
	class MyIterator;
	class const_MyIterator;
	MyVector<T>();
	MyVector<T>(unsigned int);
	MyVector<T>(unsigned int, T);
	MyVector<T>(const MyVector<T>&);
	~MyVector<T>();	
	MyVector<T>& operator=(const MyVector<T>&);
	const T& operator[](unsigned int);
	const T& at(unsigned int);
	const T& front();
	const T& back();
	const unsigned int& getSize() const;
	const unsigned int& getCapacity() const;
	bool isEmpty();
	T* getData();
	void push_back(T);
	void pop_back();
	void assign(unsigned int, T);
	void clear();
	friend std::ostream& operator<<(std::ostream&, const MyVector<T>&);
	
	MyIterator begin();
	MyIterator end();
	const const_MyIterator begin() const;
	const const_MyIterator end() const;
};


template <class T>
class MyVector<T>::MyIterator
{
	T* _ptr;
	public:
		MyIterator() : _ptr(nullptr) {}
		MyIterator(T* ptr) : _ptr(ptr) { }
		MyIterator operator++() { MyIterator i = *this; _ptr++; return i; }
		MyIterator operator++(int) { _ptr++; return *this; }
		T& operator*() { return *_ptr; }
		T* operator->() { return _ptr; }
		bool operator==(const MyIterator& iter) { return _ptr == iter._ptr; }
		bool operator!=(const MyIterator& iter) { return _ptr != iter._ptr; }
};

template <class T>
class MyVector<T>::const_MyIterator
{
	T* _ptr;
public:
	const_MyIterator() : _ptr(nullptr) {}
	const_MyIterator(T* ptr) : _ptr(ptr) { }
	const_MyIterator operator++() { const_MyIterator i = *this; _ptr++; return i; }
	const_MyIterator operator++(int) { _ptr++; return *this; }
	T& operator*() { return *_ptr; }
	T* operator->() { return _ptr; }
	bool operator==(const const_MyIterator& iter) { return _ptr == iter._ptr; }
	bool operator!=(const const_MyIterator& iter) { return _ptr != iter._ptr; }
};

// Default Constructor 
template <class T>
MyVector<T>::MyVector() : _capacity(0), _size(0), _data(nullptr) { }

// Constructor - Initializes a vector with a given capacity
template <class T>
MyVector<T>::MyVector(unsigned int cap) : _capacity(cap), _size(0), _data(new T[cap]) { }

// Constructor - Initialize a vector with given capacity and data of type T
template <class T>
MyVector<T>::MyVector(unsigned int cap, T val) : _capacity(cap), _size(0), _data(new T[cap])
{
	this->assign(cap, val);
}

// Destructor
template <class T>
MyVector<T>::~MyVector()
{
	delete[] this->_data;
}

// Copy Constructor
template <class T>
MyVector<T>::MyVector(const MyVector<T>& vec)
{
	this->MakeCopy(vec);
}

// Copy Assignment Operator
template <class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& vec)
{
	if (this->_data || !this->getData() && this->getCapacity() == 0 && this->getSize() == 0)
	{
		delete[] this->_data;
		this->MakeCopy(vec);
	}
	return *this;
}

// Array Operator Overloaded Function - returns data in a given index
template <class T>
const T& MyVector<T>::operator[](unsigned int index)
{
	if (!this->_data)
	{
		this->_data = new T[MIN_CAP];
		this->_capacity = MIN_CAP;
	} 
	return *(this->_data + index);
}

// at Function - calls the Array Operator overload
template <class T>
const T& MyVector<T>::at(unsigned int index)
{
	return this->operator[](index);
}

// getSize Function - returns the count of data within the array
template <class T>
const unsigned int& MyVector<T>::getSize() const
{
	return (this->_size);
}

// getCapacity Function - returns the capacity of the maximum number of data the array can hold
template <class T>
const unsigned int& MyVector<T>::getCapacity() const
{
	return (this->_capacity);
}

// isEmpty Function - returns the result if the array is empty
template <class T>
bool MyVector<T>::isEmpty()
{
	return (_size == 0);
}

// getData Function - returns the address of the first element of the array
template <class T>
T* MyVector<T>::getData()
{
	return _data;
}

// push_back Function - adds data to the array
template <class T>
void MyVector<T>::push_back(T val)
{
	if (!this->_data)
	{
		this->_data = new T[MIN_CAP];
		this->_capacity = MIN_CAP;
		this->_data[this->_size++] = val;
	}

	else if (this->_capacity == this->_size)
	{
		T* temp = new T[this->_capacity];
		this->copyArray(temp, _data);
		delete[] this->_data;
		this->_data = new T[this->_capacity *= 2];
		this->copyArray(_data, temp);
		delete[] temp;
		this->_data[this->_size++] = val;
	}

	else
	{
		this->_data[this->_size++] = val;
	}

}

// assign function - Initialize an array based on capacity and value
template <class T>
void MyVector<T>::assign(unsigned int cap , T val)
{
	if (!this->_data && this->_capacity == 0)
	{
		this->_data = new T[cap];
		this->_capacity = cap;
	}

	for (unsigned int i = 0; i < cap; ++i)
	{
		this->insertData(i, val);
	}
}

// pop_back Function - Clears the data from the last element of the array
template <class T>
void MyVector<T>::pop_back()
{
	(this->_data + this->getSize() - 1)->~T();
	_size--;
}

// front function - returns the contents of the first element of the array
template <class T>
const T& MyVector<T>::front()
{
	return this->_data[0];
}

// back function - returns the contents of the last element of the array
template <class T>
const T& MyVector<T>::back()
{
	return this->_data[this->getSize() - 1];
}

// copyArray Function - make copies of arrays
template <class T>
void MyVector<T>::copyArray(T*& to, const T* from)
{
	for (unsigned int i = 0; i < this->_size; ++i)
	{
		to[i] = from[i];
	}
}

// MakeCopy Function - make copies of vector instances
template <class T>
void MyVector<T>::MakeCopy(const MyVector& vec)
{
	this->_capacity = vec.getCapacity();
	this->_size = vec.getSize();
	this->_data = new T[vec.getCapacity()];
	this->copyArray(this->_data, const_cast<MyVector<T>&>(vec).getData());
}

// MyVector Class: insertData Function -  
template <class T>
void MyVector<T>::insertData(unsigned int i, T val)
{
	this->_data[i] = val;
	this->_size++;
}

// Overloaded insertion operator Function - Append data to ostream object
template <class T>
std::ostream& operator<<(std::ostream& os, const MyVector<T>& obj)
{
	os << *(obj._data + obj.tempidx);
	return os;
}

// clear Function - deallocate the MyVector instance and set size and capacity to 0
template <class T>
void MyVector<T>::clear()
{
	delete[] this->_data;
	this->_size = this->_capacity = 0;
}

// MyIterator Class: begin Function - returns an instance pointed to the first element of the vector
template <class T>
typename MyVector<T>::MyIterator MyVector<T>::begin()
{
	return MyIterator(this->_data);
}

// MyIterator Class: end Function - returns an instance pointed to the last element of the vector
template <class T>
typename MyVector<T>::MyIterator MyVector<T>::end()
{
	return MyIterator(this->_data + _size);
}

// const_MyIterator Class: begin Function - returns an instance constantly pointed to the first element of the vector
template <class T>
typename const MyVector<T>::const_MyIterator MyVector<T>::begin() const
{
	return const_MyIterator(this->_data);
}


// constMyIterator Class: begin Function - returns an const instance constantly pointed to the first element of the vector
template <class T>
typename const MyVector<T>::const_MyIterator MyVector<T>::end() const
{
	return const_MyIterator(this->_data + _size);
}

#endif