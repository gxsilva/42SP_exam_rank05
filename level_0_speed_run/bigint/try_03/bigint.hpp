/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 14:02:08 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/06 14:43:34 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <ostream>

class bigint
{
	private:
		std::string _val;
	public:
		bigint();
		bigint(const bigint &obj);
		bigint& operator=(const bigint &obj);
		bigint(unsigned int number);
		~bigint();

		static std::string reverse(const std::string &str);
		static std::string addtition(const std::string &str1, const std::string &str2);
		static unsigned int strToUnsignedInt(const std::string &str);
		
		bigint operator+(const bigint &obj) const;
		bigint& operator+=(const bigint &obj);
		bigint& operator++();
		bigint operator++(int);

		bigint operator<<(unsigned int rshift) const;
		bigint operator<<(const bigint &obj) const;
		bigint operator>>(const bigint &obj) const;
		bigint operator>>(unsigned int lshift) const;

		bigint& operator<<=(unsigned int rshift);
		bigint& operator<<=(const bigint &obj);
		bigint& operator>>=(const bigint &obj);
		bigint& operator>>=(unsigned int lshift);

		bool operator<(const bigint &obj) const;
		bool operator<=(const bigint &obj) const;
		bool operator>(const bigint &obj) const;
		bool operator>=(const bigint &obj) const;
		bool operator==(const bigint &obj) const;
		bool operator!=(const bigint &obj) const;

	friend std::ostream &operator<<(std::ostream &os, const bigint &obj);
};

#endif //BIGINT_HPP