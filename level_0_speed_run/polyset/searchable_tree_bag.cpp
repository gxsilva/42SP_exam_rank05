/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 22:06:12 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/03/31 22:43:19 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag()
: tree_bag() { }

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &obj)
: tree_bag(obj) { }

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &obj)
{
	if (&obj != this)
		tree_bag::operator=(obj);
	return *this;
}

searchable_tree_bag::~searchable_tree_bag() { }

bool searchable_tree_bag::has(int target) const
{
	node *crr = tree;

	while(true)
	{
		if (crr == nullptr)
			return false;
		if (crr->value == target)
			return true;
		if (crr->value > target)
			crr = crr->l;
		else
			crr = crr->r;
	}
}