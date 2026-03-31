/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 01:15:50 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/03/31 04:11:59 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class bigint
{
	private:
		std::string _str;
	
	public:
		bigint();
		bigint(unsigned int num);
		bigint(const bigint& big);
		bigint& operator=(const bigint &big);
		~bigint();

		std::string getStr() const;
		static std::string reverse(const std::string &str);

		static std::string addition(const bigint &obj1, const bigint &obj2);
		static unsigned int strToUnsignedInt(const std::string str);
	
		bigint operator+(const bigint &obj) const;
		bigint &operator+=(const bigint &obj);

		bigint &operator++();
		bigint operator++(int);

		bigint operator<<(const int n) const;
		bigint operator>>(const int n) const;
		bigint& operator<<=(const size_t n);
		bigint& operator>>=(const size_t n);

		bigint operator<<(const bigint &obj) const;
		bigint operator>>(const bigint &obj) const;
		bigint& operator<<=(const bigint &obj);
		bigint& operator>>=(const bigint &obj);

		bool operator==(const bigint &obj) const;
		bool operator!=(const bigint &obj) const;
		bool operator>(const bigint &obj) const;
		bool operator>=(const bigint &obj) const;
		bool operator<(const bigint &obj) const;
		bool operator<=(const bigint &obj) const;
		
		friend std::ostream &operator<<(std::ostream &oS, const bigint& obj);
};
