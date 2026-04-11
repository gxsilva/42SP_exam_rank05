#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag()
{}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &obj)
: tree_bag(obj)
{}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &other)
{
	if (&other != this)
		tree_bag::operator=(other);
	return *this;
}

searchable_tree_bag::~searchable_tree_bag()
{}

bool searchable_tree_bag::has(int target) const
{
	node* crr = tree;

	while(crr)
	{
		if (crr->value == target)
			return true;
		if (crr->value > target)
			crr = crr->l;
		else
			crr = crr->r;
	}
	return (false);
}
