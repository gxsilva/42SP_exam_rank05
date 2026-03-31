/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:47:45 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/03/31 18:35:14 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

set::set(searchable_bag &obj)
: bag(obj)
{

}

bool set::has(int target) const
{
	return bag.has(target);
}
void set::insert (int val)
{
	if (!has(val))
		bag.insert(val);
}

void set::insert (int *data, int range)
{
	if (!has(range))
		bag.insert(data, range);
}

void set::print() const
{
	bag.print();
}

void set::clear()
{
	bag.clear();
}

set::~set()
{ }


const searchable_bag &set::get_bag() const
{
	return (bag);
}
