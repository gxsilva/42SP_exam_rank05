/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 22:13:50 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/03/31 22:16:22 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

set::set( searchable_bag &obj)
: _bag(obj)
{ }

set::~set()
{  }

void set::insert (int target)
{
	if (!_bag.has(target))
		_bag.insert(target);
}

void set::insert (int *data, int target)
{
	if (!_bag.has(target))
		_bag.insert(data, target);
}

void set::print() const
{
	_bag.print();
}

void set::clear()
{
	_bag.clear();
}

bool set::has(int target) const
{
	return _bag.has(target);
}

const searchable_bag &set::get_bag() const
{
	return _bag;
}

