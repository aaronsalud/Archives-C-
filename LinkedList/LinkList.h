#ifndef LINKLIST_H
#define LINKLIST_H
#include <ostream>
#include <new>
#include "Student.h"

using namespace std;

class LinkList
{
	class Node;
	Node *head_;
	void Clean();
	void MakeCopy(const LinkList &ll) throw(bad_alloc);
public:
	LinkList() throw();
	LinkList(const LinkList &) throw(bad_alloc);
	~LinkList() throw();
	LinkList &operator=(const LinkList &) throw(bad_alloc);
	void Add(Student* v) throw(bad_alloc);
	void Print(ostream &os) const throw();
	friend ostream &operator <<(ostream &os, LinkList &ll) throw();
};


class LinkList::Node
{
	Student* student;
	Node *next_;
	Node(Student* v, Node *next) throw();
	friend class LinkList;
};

#endif