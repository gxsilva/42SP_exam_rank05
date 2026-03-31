/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:34:30 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/03/31 17:36:19 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_tree_bag.hpp"

bool searchable_tree_bag::has(int value) const
{
	return (search(tree, value));
}

searchable_tree_bag::searchable_tree_bag()
: tree_bag()
{ }

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &obj)
: tree_bag(obj)
{ }

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &obj)
{
	if (&obj != this)
		tree_bag::operator=(obj);
	return (*this);
}

searchable_tree_bag::~searchable_tree_bag()
{ }

bool searchable_tree_bag::search(const node *tree, const int target) const
{
	if (!tree)
		return false;
	if (tree->value == target)
		return true;
	if (target < tree->value)
		return search(tree->l, target);
	else
		return search(tree->r, target);
}