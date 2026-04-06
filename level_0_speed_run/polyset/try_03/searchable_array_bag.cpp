/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 15:30:22 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/06 16:16:02 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag()
: array_bag()
{ }

searchable_array_bag::~searchable_array_bag()
{ }

searchable_array_bag &searchable_array_bag::operator=(const searchable_array_bag& obj)
{
	if (&obj != this)
		array_bag::operator=(obj);
	return *this;
}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &obj)
: array_bag(obj)
{ }

bool searchable_array_bag::has(int target) const
{
	int l = 0;
	int r = size - 1;

	while (l <= r)
	{
		int mid = ((r - l)  / 2) + l;
		if (data[mid] == target)
			return true;
		if (data[mid] > target)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return false;
}

void searchable_array_bag::insert(int value)
{
	array_bag::insert(value);
}

void searchable_array_bag::insert(int *arr, int size)
{
	array_bag::insert(arr, size);
}

void searchable_array_bag::print() const
{
	array_bag::print();
}

void searchable_array_bag::clear()
{
	array_bag::clear();
}