/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 15:30:22 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/06 15:52:00 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag()
: tree_bag()
{ }

searchable_tree_bag::~searchable_tree_bag()
{ }

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag& obj)
{
	if (&obj != this)
		tree_bag::operator=(obj);
	return *this;
}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &obj)
: tree_bag(obj)
{ }

bool searchable_tree_bag::has(int target) const
{
	node *crr = tree;

	while (crr)
	{
		if (target == crr->value)
			return (true);
		if (crr->value > target)
			crr = crr->l;
		else
			crr = crr->r;
	}
	return false;
}

void searchable_tree_bag::insert(int value)
{
	tree_bag::insert(value);
}

void searchable_tree_bag::insert(int *arr, int size)
{
	tree_bag::insert(arr, size);
}

void searchable_tree_bag::print() const
{
	tree_bag::print();
}

void searchable_tree_bag::clear()
{
	tree_bag::clear();
}