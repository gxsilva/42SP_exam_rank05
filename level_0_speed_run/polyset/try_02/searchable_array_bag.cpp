#include "searchable_array_bag.hpp"
#include <cstddef>

searchable_array_bag::searchable_array_bag()
: bag()
{}

searchable_array_bag::~searchable_array_bag()
{
}

searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag &obj)
{
	if (&obj != this)
		array_bag::operator=(obj);
	return *this;
}

searchable_array_bag::searchable_array_bag(const searchable_array_bag& obj)
: array_bag(obj)
{ }

bool searchable_array_bag::has(int target)	 const
{
	for (size_t i = 0; i < size; i++)
		if (data[i] == target)
			return true;
	return false;
}
