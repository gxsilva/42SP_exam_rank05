/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 18:43:29 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/03/31 20:20:51 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>

#include "bigint.hpp"

bigint::bigint()
: _value("0")
{ }

bigint::bigint(unsigned int value)
: _value("0")
{
	std::stringstream ss;

	ss << value;
	_value = ss.str();
}

bigint::bigint(const bigint &obj)
: _value(obj._value)
{
}

bigint &bigint::operator=(const bigint &obj)
{
	if (&obj != this)
		_value = obj._value;
	return *this;
}

bigint::~bigint()
{
}

std::ostream &operator<<(std::ostream &os, const bigint &obj)
{
	os << obj._value;
	return (os);
}

std::string bigint::reverse(const std::string &std)
{
	size_t str_len = std.length();
	std::string str_res;
	
	for (size_t i = str_len - 1; i != 0; i--)
		str_res += std[i];
	str_res += std[0];
	return str_res;
}


std::string bigint::addtition(const std::string obj1, const std::string obj2)
{
	std::string obj1_tmp = reverse(obj1);
	std::string obj2_tmp = reverse(obj2);

	size_t obj1_len = obj1_tmp.length();
	size_t obj2_len = obj2_tmp.length();

	if (obj1_len > obj2_len)
	{
		int diff = obj1_len - obj2_len;
		while (diff--)
			obj2_tmp.push_back('0');
	}
	else if (obj2_len > obj1_len)
	{
		int diff = obj2_len - obj1_len;
		while (diff--)
			obj1_tmp.push_back('0');
	}
	std::string obj_final = "";
	int carry = 0;
	int dig1;
	int dig2;
	for (size_t i = 0; i < obj1_tmp.length(); i++)
	{
		dig1 = obj1_tmp[i] - '0';
		dig2 = obj2_tmp[i] - '0';
		int res = dig1 + dig2 + carry;
		if (res > 9)
		{
			obj_final += (res % 10) + '0';
			carry = (res / 10);
		}
		else
			obj_final += res + '0';
	}
	if (carry != 0)
		obj_final += (carry + '0');
	return reverse(obj_final);
}

bigint bigint::operator+(const bigint &obj) const
{
	bigint tmp;
	tmp._value = addtition(_value, obj._value);
	return tmp;
}

bigint &bigint::operator+=(const bigint &obj)
{
	std::string new_value = addtition(_value, obj._value);
	_value = new_value;
	return *this;
}

bigint& bigint::operator++()
{

	std::string new_value = addtition(_value, "1");
	_value = new_value;
	return *this;
}

bigint bigint::operator++(int)
{
	bigint tmp(*this);
	std::string new_value = addtition(_value, "1");
	_value = new_value;

	return tmp;
}

bigint bigint::operator<<(unsigned int lshift)
{
	bigint tmp(*this);
	
	std::string newValue(tmp._value);

	int i = 0;
	while(i++ < lshift)
		newValue += '0';
	tmp._value = newValue;
	return (tmp);
}

bigint &bigint::operator<<=(unsigned int lshift)
{
	(*this) = (*this) << lshift;
	return *this;
}

bigint &bigint::operator>>=(unsigned int rshift)
{
	if(rshift >= _value.length())
		_value = "0";
	else
		_value = _value.erase(_value.length() - rshift, rshift);
	return *this;
}

bool bigint::operator<(const bigint &obj) const
{
	return strToUnsignedInt(_value) < strToUnsignedInt(obj._value);
}

bool bigint::operator<=(const bigint &obj) const
{
	return strToUnsignedInt(_value) <= strToUnsignedInt(obj._value);
}

bool bigint::operator>(const bigint &obj) const
{
	return strToUnsignedInt(_value) > strToUnsignedInt(obj._value);
}

bool bigint::operator>=(const bigint &obj) const
{
	return strToUnsignedInt(_value) >=strToUnsignedInt(obj._value);
}

bool bigint::operator==(const bigint &obj) const
{
	return _value == obj._value;
}

bool bigint::operator!=(const bigint &obj) const
{
	return _value != obj._value;
}

unsigned int bigint::strToUnsignedInt(const std::string &str)
{
	std::stringstream ss(str);

	unsigned int res;

	ss >> res;
	return res;
}

bigint bigint::operator>>(unsigned int rshift)
{
	bigint tmp(*this);
	if(rshift >= _value.length())
		tmp._value = "0";
	else
		tmp._value = tmp._value.erase(_value.length() - rshift, rshift);
	return tmp;
}

bigint bigint::operator<<(const bigint &obj)
{
	bigint tmp(*this);
	tmp = tmp << strToUnsignedInt(obj._value);
	return (tmp);
}

bigint bigint::operator>>(const bigint &obj)
{
	bigint tmp(*this);
	tmp = tmp << strToUnsignedInt(obj._value);
	return (tmp);
}

bigint &bigint::operator<<=(const bigint &obj)
{
	bigint tmp;
	tmp = (*this) << strToUnsignedInt(obj._value);
	(*this)._value = tmp._value;
	return *this;
}

bigint &bigint::operator>>=(const bigint &obj)
{
	bigint tmp;
	tmp = (*this) >> strToUnsignedInt(obj._value);
	(*this)._value = tmp._value;
	return *this;
}