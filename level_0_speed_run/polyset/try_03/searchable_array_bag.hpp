/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 15:26:00 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/06 16:18:37 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SEARCHABLE_ARRAY_BAG
#define SEARCHABLE_ARRAY_BAG

#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag
{
	public:
		searchable_array_bag();
		virtual ~searchable_array_bag();
		searchable_array_bag &operator=(const searchable_array_bag& obj);
		searchable_array_bag(const searchable_array_bag &obj);
		bool has(int) const;

		void insert(int);
		void insert(int *, int);
		void print() const;
		void clear();
};




#endif 