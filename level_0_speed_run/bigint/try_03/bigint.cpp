/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 14:02:10 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/06 15:23:08 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include "bigint.hpp"

bigint::bigint()
: _val("0")
{ }

bigint::bigint(const bigint &obj)
: _val(obj._val)
{ }

bigint& bigint::operator=(const bigint &obj)
{
	if (&obj != this)
		_val = obj._val;
	return *this;
}

bigint::bigint(unsigned int number)
{
	std::stringstream ss;

	ss << number;
	_val = ss.str();
}

bigint::~bigint()
{  }

std::ostream &operator<<(std::ostream &os, const bigint &obj)
{
	os << obj._val;
	return (os);
}

std::string bigint::reverse(const std::string &str)
{
	std::string newstr;

	for (int i = str.length() - 1; i > 0; i--)
		newstr += str[i];
	newstr += str[0];
	return (newstr);
}

std::string bigint::addtition(const std::string &str1, const std::string &str2)
{
	std::string str1_reverse = reverse(str1);
	std::string str2_reverse = reverse(str2);
	size_t str1_size = str1.length();
	size_t str2_size = str2.length();
	if (str1_size > str2_size)
	{
		int diff = str1_size - str2_size;
		while (diff--)
			str2_reverse += '0';
	}
	else if (str2_size > str1_size)
	{
		int diff = str2_size - str1_size;
		while (diff--)
			str1_reverse += '0';
	}
	std::string final_str = "";
	int carry = 0;
	for (size_t i = 0; i < str1_reverse.length(); i++)
	{
		int sum = (str1_reverse[i] - '0') + (str2_reverse[i] - '0') + carry;
		if (sum > 9)
			carry = (sum / 10);
		final_str += (sum % 10) + '0';
	}
	if (carry != 0)
		final_str += carry + '0';
	return (reverse(final_str));
}


bigint bigint::operator+(const bigint &obj) const
{
	bigint tmp(*this);
	std::string new_value = addtition(this->_val, obj._val);
	tmp._val = new_value;

	return (tmp);
}

bigint& bigint::operator+=(const bigint &obj)
{
	std::string new_value = addtition(this->_val, obj._val);
	_val = new_value;
	
	return *this;
}

bigint& bigint::operator++()
{
	bigint tmp(*this);
	tmp += 1;
	_val = tmp._val;
	return *this;
}

bigint bigint::operator++(int)
{
	bigint tmp(*this);
	std::string new_value = addtition(this->_val, "1");
	_val = new_value;

	return tmp;
}

unsigned int bigint::strToUnsignedInt(const std::string &str)
{
	std::stringstream ss;
	unsigned int x = 0;
	ss << str;
	ss >> x;
	return (x);
}


bigint bigint::operator<<(unsigned int rshift) const
{
	std::string new_str = _val;

	for (size_t i = 0; i < rshift; i++)
		new_str += '0';
	bigint tmp;
	tmp._val = new_str;
	return tmp;
}


bigint bigint::operator>>(unsigned int rshift) const
{
	bigint tmp(*this);
	if (rshift > _val.length())
			tmp._val = "0";
	else
	{
		std::string value = tmp._val;
		tmp._val = value.erase(value.length() - rshift, rshift);
	}
	return tmp;
}

bigint bigint::operator<<(const bigint &obj) const
{
	unsigned int value = strToUnsignedInt(obj._val);

	bigint tmp(*this);

	tmp << value;
	return tmp;
}


bigint bigint::operator>>(const bigint &obj) const
{
	unsigned int value = strToUnsignedInt(obj._val);

	bigint tmp(*this);

	tmp = tmp >> value;
	return tmp;
}


bigint& bigint::operator<<=(unsigned int rshift)
{
	bigint tmp(*this);
	tmp = tmp << rshift;
	_val = tmp._val;
	return *this;
}

bigint& bigint::operator>>=(unsigned int rshift)
{
	bigint tmp(*this);
	tmp = tmp >> rshift;
	_val = tmp._val;
	return *this;
}


bigint& bigint::operator<<=(const bigint &obj)
{
	bigint tmp(*this);
	tmp << obj;
	_val = tmp._val;
	return *this;
}


bigint& bigint::operator>>=(const bigint &obj)
{
	bigint tmp(*this);
	tmp = tmp >> obj;
	_val = tmp._val;
	return *this;
}

bool bigint::operator<(const bigint &obj) const
{
	return ((strToUnsignedInt(_val) < strToUnsignedInt(obj._val)));
}

bool bigint::operator<=(const bigint &obj) const
{
	return ((strToUnsignedInt(_val) <= strToUnsignedInt(obj._val)));
}

bool bigint::operator>(const bigint &obj) const
{
	return ((strToUnsignedInt(_val) > strToUnsignedInt(obj._val)));
}

bool bigint::operator>=(const bigint &obj) const
{
	return ((strToUnsignedInt(_val) >= strToUnsignedInt(obj._val)));
}

bool bigint::operator==(const bigint &obj) const
{
	return ((strToUnsignedInt(_val) == strToUnsignedInt(obj._val)));
}

bool bigint::operator!=(const bigint &obj) const
{
	return ((strToUnsignedInt(_val) != strToUnsignedInt(obj._val)));
}