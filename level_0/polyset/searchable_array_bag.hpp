/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:30:56 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/03/31 17:55:59 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag : public searchable_bag, public array_bag 
{
	public:
		searchable_array_bag();
		searchable_array_bag(const searchable_array_bag &);
		searchable_array_bag& operator=(const searchable_array_bag &);
		~searchable_array_bag();

		bool has(int) const;
};
