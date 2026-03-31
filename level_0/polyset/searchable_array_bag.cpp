#include "searchable_array_bag.hpp"
#include <cstddef>

// O (log N) não sei se passa com O(N), do jeito que a 42 é tudo indica que sim XD
bool searchable_array_bag::has(int target) const
{
	int l = 0;
	int r = size - 1;

	while (l <= r)
	{
		int mid = l + (r - l) / 2;

		if (data[mid] == target)
			return true;
		if (data[mid] < target)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return false;
}

searchable_array_bag::searchable_array_bag()
: array_bag()
{ }

searchable_array_bag::searchable_array_bag(const searchable_array_bag &obj)
{
	data  = new int[obj.size];
	for (size_t i = 0; i < size; i++)
		data[i] = obj.data[i];
}

searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag &obj)
{
	if (&obj != this)
	{
		if (data != nullptr)
		{
			delete []data;
			data = nullptr;
		}
		data = new int[obj.size];
		for (size_t i = 0; i < obj.size; i++)
			data[i] = obj.data[i];
	}
	return (*this);
}

searchable_array_bag::~searchable_array_bag()
{
	if (data != nullptr)
	{
		delete data;
		data = nullptr;
	}
}