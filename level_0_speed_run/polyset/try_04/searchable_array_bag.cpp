#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag()
{}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &obj)
: array_bag(obj)
{}

searchable_array_bag &searchable_array_bag::operator=(const searchable_array_bag &other)
{
	if (&other != this)
		array_bag::operator=(other);
	return *this;
}

searchable_array_bag::~searchable_array_bag()
{}

bool searchable_array_bag::has(int target) const
{
	for (int i = 0; i < size; i++)
		if (data[i] == target)
			return true;
	return false;
}
