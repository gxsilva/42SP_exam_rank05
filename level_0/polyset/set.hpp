/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:37:47 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/03/31 18:35:02 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag& bag;
		
		set() = delete;
		set(const set &) = delete;
		set& operator=(const set&) = delete;
	public:
		bool has(int) const;
		void insert (int);
		void insert (int *, int);
		void print() const;
		void clear();

		set(searchable_bag &obj);
		~set();

		const searchable_bag &get_bag() const;
};

#endif