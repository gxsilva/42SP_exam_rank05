/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 01:15:52 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/03/31 04:12:01 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "bigint.hpp"

bigint::bigint()
: _str("0")
{ }

bigint::~bigint() {}

bigint::bigint(unsigned int num)
{
	std::stringstream ss;

	ss << num;
	this->_str = ss.str();
}

bigint::bigint(const bigint& big)
: _str(big._str) {}

bigint& bigint::operator=(const bigint &big)
{
	if (this != &big)
		this->_str = big._str;
	return *this;
}

std::string bigint::getStr() const
{
	return _str;
}

std::string bigint::reverse(const std::string &str)
{
	std::string rVerse;

	if (str.size() == 0)
		return 0;
	for (size_t i = str.size() - 1 ; i != 0; i--)
		rVerse += str[i];
	rVerse += str[0];
	return rVerse;
}

std::string bigint::addition(const bigint &obj1, const bigint &obj2)
{
	std::string str1 = reverse(obj1._str);
	std::string str2 = reverse(obj2._str);

	std::string res_str;

	size_t str1_len = str1.length();
	size_t str2_len = str2.length();

	if (str1_len > str2_len)
	{
		int diff = str1_len - str2_len;
		while (diff--)
			str2.push_back('0');
	}
	else if (str2_len > str1_len)
	{
		int diff = str2_len - str1_len;
		while (diff--)
			str1.push_back('0');
	}

	int carry = 0;
	int dig1;
	int dig2;
	size_t len = str1.length();
	for (size_t i = 0; i < len; i++)
	{
		dig1 = str1[i] - '0';
		dig2 = str2[i] - '0';
		int res = dig1 + dig2 + carry;
		if (res > 9)
		{
			carry = res / 10;
			res_str.push_back((res % 10) + '0');
		}
		else
			res_str.push_back(res + '0');
	}
	if (carry != 0)
		res_str.push_back(carry + '0');
	return (reverse(res_str));
}

bigint bigint::operator+(const bigint &obj) const
{
	bigint newValue;
	newValue._str = addition(*this, obj);
	return newValue;
}

std::ostream &operator<<(std::ostream &oS, const bigint& obj)
{
	std::string value = obj._str;
	oS << value;
	return oS;
}


bigint &bigint::operator+=(const bigint &obj)
{
	_str = addition(*this, obj);
	return *this;
}

bigint &bigint::operator++()
{
	bigint tmp(1);
	_str = addition(*this, tmp);
	return *this;
}

bigint bigint::operator++(int)
{
	bigint tmp(*this);
	++(*this);
	return tmp;
}

bigint bigint::operator<<(const int n) const
{
	bigint tmp(*this);
	std::string strrr = tmp.getStr();

	strrr.insert(strrr.end(), n, '0');
	tmp._str = strrr;
	return (tmp);
}

bigint bigint::operator>>(const int n) const
{
	bigint tmp(*this);

	if (n >= tmp._str.length())
		tmp._str = "0";
	else
		tmp._str.erase(tmp._str.length() - n, n);
	return tmp;
}

bigint& bigint::operator<<=(const size_t n)
{
	(*this) = (*this) << n;
	return *this;
}

bigint& bigint::operator >>=(const size_t n)
{
	(*this) = (*this) >> n;
	return *this;
}

unsigned int bigint::strToUnsignedInt(const std::string str)
{
	std::stringstream ss(str);

	unsigned int res;
	ss >> res;
	return res;
}


bool bigint::operator==(const bigint &obj) const
{
	return _str == obj._str;
}

bool bigint::operator!=(const bigint &obj) const
{
	return _str != obj._str;
}

bool bigint::operator>(const bigint &obj) const
{
	return _str.length() > obj._str.length();
}

bool bigint::operator>=(const bigint &obj) const
{
	return _str.length() >= obj._str.length();
}

bool bigint::operator<(const bigint &obj) const
{
	return _str.length() < obj._str.length();
}

bool bigint::operator<=(const bigint &obj) const
{
	return _str.length() <= obj._str.length();
}


bigint bigint::operator<<(const bigint &obj) const
{
	bigint tmp(*this);

	tmp = tmp << strToUnsignedInt(obj._str);
	return tmp;
}

bigint bigint::operator>>(const bigint &obj) const
{
	bigint tmp(*this);

	tmp = tmp >> strToUnsignedInt(obj._str);
	return tmp;
}

bigint& bigint::operator<<=(const bigint &obj)
{
	(*this) = (*this) << (strToUnsignedInt(obj._str));
	return *this;
}

bigint& bigint::operator>>=(const bigint &obj)
{
	(*this) = (*this) >> (strToUnsignedInt(obj._str));
	return *this;
}