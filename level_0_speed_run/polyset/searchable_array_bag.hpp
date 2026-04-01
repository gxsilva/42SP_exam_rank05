/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:56:06 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/03/31 22:03:48 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_ARRAY_BAG_HPP
#define SEARCHABLE_ARRAY_BAG_HPP

#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag
{
	public:
		searchable_array_bag();
		searchable_array_bag(const searchable_array_bag &);
		searchable_array_bag &operator=(const searchable_array_bag&);
		~searchable_array_bag();
		bool has(int) const;
};

#endif /* SEARCHABLE_ARRAY_BAG_HPP */