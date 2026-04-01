/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 22:09:33 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/03/31 22:16:06 by lsilva-x         ###   ########.fr       */
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
		~set();
		void insert (int);
		void insert (int *, int);
		void print() const;
		void clear();

		bool has(int) const;
		const searchable_bag &get_bag() const;
};

#endif /* SET_HPP */