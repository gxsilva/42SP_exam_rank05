#include "searchable_tree_bag.hpp"
#include <cstddef>

searchable_tree_bag::searchable_tree_bag()
: tree_bag()
{}

searchable_tree_bag::~searchable_tree_bag()
{ }

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag &obj)
{
	if (&obj != this)
		tree_bag::operator=(obj);
	return *this;
}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& obj)
: tree_bag(obj)
{ }

bool searchable_tree_bag::has(int target)	const
{
	if (!tree)
		return false;
	node *crr = tree;
	while(crr != nullptr)
	{
		if ((*crr).value == target)
			return true;
		if ((*crr).value > target)
			crr = crr->l;
		else
			crr = crr->r;
	}
	return (false);
}
