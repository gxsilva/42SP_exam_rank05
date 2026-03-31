/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:26:28 by fatkeski          #+#    #+#             */
/*   Updated: 2026/03/31 18:08:05 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_TREE_BAG_HPP
#define SEARCHABLE_TREE_BAG_HPP

#include "tree_bag.hpp"
#include "searchable_bag.hpp"


class searchable_tree_bag : public tree_bag, public searchable_bag
{
	private:
		bool search(node* node, const int value) const;
	public:
		searchable_tree_bag();
		searchable_tree_bag(const searchable_tree_bag& source);
		searchable_tree_bag& operator=(const searchable_tree_bag& source);
		bool has(int) const;
		~searchable_tree_bag();
};

#endif /* SEARCHABLE_TREE_BAG_HPP */
