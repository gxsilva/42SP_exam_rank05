/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 15:59:23 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/06 16:10:17 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

set::set(searchable_bag &obj)
: _bag(obj) {}

set& set::operator=(const set &obj)
{
	if (&obj != this)
		_bag = obj._bag;
	return *this;
}

set::~set() {}

void set::insert(int value)
{
	if (!_bag.has(value))
		_bag.insert(value);
}

void set::insert(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		if (!_bag.has(arr[i]))
			_bag.insert(arr[i]);
}

void set::print() const
{
	_bag.print();
}

void set::clear()
{
	_bag.clear();
}

searchable_bag &set::get_bag()
{
	return _bag;
}

bool set::has(int value) const
{
	return _bag.has(value);
}