/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 15:48:53 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/06 16:18:31 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_TREE_BAG_HPP
#define SEARCHABLE_TREE_BAG_HPP

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag
{
	public:
		searchable_tree_bag();
		virtual ~searchable_tree_bag();
		searchable_tree_bag &operator=(const searchable_tree_bag& obj);
		searchable_tree_bag(const searchable_tree_bag &obj);
		bool has(int) const;

		void insert(int);
		void insert(int *, int);
		void print() const;
		void clear();
};

#endif