#include <cstdlib>
#include "set.hpp"

set::set()
: _bag(NULL)
{ }

set::set(searchable_bag &obj)
: _bag(&obj)
{}

set::set(const set &obj)
: _bag(obj._bag)
{}

set &set::operator=(const set &obj)
{
	if (&obj != this)
		_bag = obj._bag;
	return *this;
}

set::~set()
{ }

void set::insert(int target)
{
	if (!_bag)
		return ;
	if (!_bag->has(target))
		_bag->insert(target);
}

void set::insert(int *ptr, int target)
{
	if (!_bag)
		return ;
	if (!_bag->has(target))
		_bag->insert(ptr, target);
}

void set::print() const
{
	if (!_bag)
		return ;
	_bag->print();
}

void set::clear()
{
	if (!_bag)
		return ;
	_bag->clear();
}

bool set::has(int value) const
{
	if (!_bag)
		return false;
	return _bag->has(value);
}