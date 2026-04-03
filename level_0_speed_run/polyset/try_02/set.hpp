#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag& _bag;
	public:
		set(searchable_bag& obj);
		set(const set &obj);
		set & operator=(const set &obj);
		~set();

		bool has(int) const;
		 void insert (int);
		 void insert (int *, int);
		 searchable_bag &get_bag();
		 void print();
		 void clear();
};

set::set(searchable_bag& obj)
: _bag(obj)
{ }

set::set(const set &obj)
: _bag(obj._bag)
{

}

set &set::operator=(const set &obj)
{
	if (&obj != this)
		_bag = obj._bag;
	return (*this);
}

set::~set()
{
}

bool set::has(int target) const
{
	return _bag.has(target);
}


void set::insert (int node)
{
	_bag.insert(node);
}

void set::insert (int *arr, int range)
{
	_bag.insert(arr, range);
}

searchable_bag &set::get_bag()
{
	return _bag;
}

void set::print()
{
	_bag.print();
}

void set::clear()
{
	_bag.clear();
}

#endif