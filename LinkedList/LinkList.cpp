#include "LinkList.h"
#include "Student.h"

LinkList::Node::Node(Student* v, Node *next) throw()
	:student(v), next_(next)
{}

LinkList::LinkList() throw()
	:head_(0)
{}

LinkList::LinkList(const LinkList &ll) throw(std::bad_alloc)
	: head_(0)
{
	MakeCopy(ll);
}

LinkList::~LinkList() throw()
{
	Clean();
}

void LinkList::Clean()
{
	Node *nd;
	while (head_)
	{
		nd = head_->next_;
		delete head_;
		head_ = nd;
	}
	head_ = 0;
}

LinkList &LinkList::operator=(const LinkList &ll) throw(bad_alloc)
{
	if (this == &ll)
		return *this;
	Clean();
	MakeCopy(ll);
}

void LinkList::MakeCopy(const LinkList &ll) throw(bad_alloc)
{
	Node *nd = ll.head_;
	while (nd)
	{
		head_ = new Node(new Student(*(nd->student)), head_);
		nd = nd->next_;
	}
}

void LinkList::Add(Student* v) throw(bad_alloc)
{
	head_ = new Node(v, head_);
}

void LinkList::Print(ostream &os) const throw()
{
	Node *nd = head_;
	int count = 0;
	while (nd)
	{
		os << "Node[" << ++count << "]=" << nd->val << endl;
		nd = nd->next_;
	}
}

ostream &operator <<(ostream &os, LinkList &ll) throw()
{
	ll.Print(os);
	return os;
}
