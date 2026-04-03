/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 22:00:50 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/03/31 22:03:44 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>

#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag()
: array_bag() { }

searchable_array_bag::searchable_array_bag(const searchable_array_bag &obj)
: array_bag(obj) { }

searchable_array_bag &searchable_array_bag::operator=(const searchable_array_bag &obj)
{
	if (&obj != this)
		array_bag::operator=(obj);
	return *this;
}

searchable_array_bag::~searchable_array_bag() { }

bool searchable_array_bag::has(int target) const
{
	for (size_t i = 0; i < size; i++)
		if (data[i] == target)
			return true;
	return false;
}
