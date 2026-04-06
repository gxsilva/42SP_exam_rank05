/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 15:55:23 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/06 16:02:42 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag &_bag;
	public:
		set(searchable_bag &obj);
		set& operator=(const set &obj);
		~set();
	
		void insert(int);
		void insert(int *, int);
		void print() const;
		void clear();

		searchable_bag &get_bag();
		bool has(int) const;
};

#endif //SET_HPP