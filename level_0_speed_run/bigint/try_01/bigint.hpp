/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 18:38:59 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/03/31 20:16:11 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <ostream>

class bigint
{
	private: 
		std::string _value;

		static std::string reverse(const std::string &std);
		static std::string addtition(const std::string obj1, const std::string obj2);
		static unsigned int strToUnsignedInt(const std::string &str);
	public:
		bigint();
		bigint(unsigned int value);
		bigint(const bigint &);
		bigint &operator=(const bigint &);
		~bigint();

		bigint operator+(const bigint &obj) const;
		bigint &operator+=(const bigint &obj);
		
		bigint& operator++();
		bigint operator++(int);

		bigint operator<<(unsigned int lshift);
		bigint operator>>(unsigned int rshift);
		bigint &operator<<=(unsigned int lshift);
		bigint &operator>>=(unsigned int rshift);

		bigint operator<<(const bigint &obj);
		bigint operator>>(const bigint &obj);
		bigint &operator<<=(const bigint &obj);
		bigint &operator>>=(const bigint &obj);
		
		bool operator<(const bigint &obj) const;
		bool operator<=(const bigint &obj) const;
		bool operator>(const bigint &obj) const;
		bool operator>=(const bigint &obj) const;
		bool operator==(const bigint &obj) const;
		bool operator!=(const bigint &obj) const;
		
		friend std::ostream &operator<<(std::ostream &os, const bigint &obj);
};

#endif //BIGINT_HPP