/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:22:59 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/03/31 17:55:49 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_TREE_BAG_HPP
#define SEARCHABLE_TREE_BAG_HPP

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag : public searchable_bag, public tree_bag 
{
	private:
		bool search(const node *tree, const int target) const;
		
	public:
		searchable_tree_bag();
		searchable_tree_bag(const searchable_tree_bag &);
		searchable_tree_bag &operator=(const searchable_tree_bag &);
		~searchable_tree_bag();

		bool has(int) const;

};

#endif //SEARCHABLE_TREE_BAG_HPP