#include <iostream>
#include "bigint.hpp"
#include <sstream>

bigint::bigint()
: _str("0")
{ }

bigint::bigint(int value)
: _str("")
{ 
	std::stringstream ss;

	ss << value;
	_str = ss.str();
}

bigint& bigint::operator=(const bigint& obj)
{
	if (&obj != this)
		_str = obj._str;
	return *this;
}

bigint::bigint(const bigint  &obj)
: _str(obj._str)
{ }

bigint::~bigint()
{ }

std::ostream &operator<<(std::ostream &os, const bigint &obj)
{
	os << obj._str;
	return os;
}


std::string bigint::reverse(const std::string &sstr)
{
	std::string new_str = "";
	for (size_t i = sstr.size() - 1; i > 0; i--)
		new_str += sstr[i];
	new_str += sstr[0]; 
	return (new_str);
}

std::string bigint::addition(const std::string obj1, const std::string obj2)
{
	std::string str1 = reverse(obj1);
	size_t str1_len = str1.size();

	std::string str2 = reverse(obj2);
	size_t str2_len = str2.size();

	if (str1_len > str2_len)
	{
		int diff = str1_len - str2_len;
		while (diff-- > 0)
			str2 += '0';
	}
	else if (str2_len > str1_len)
	{
		int diff = str2_len - str1_len;
		while (diff--  > 0)
			str1 += '0';
	}
	int carry = 0;
	std::string final_str = "";
	for (size_t i = 0; i < str2.size(); i++)
	{
		int val = ((str1[i] - '0') + (str2[i] - '0')) + carry;
		carry = 0;
		if (val > 9)
				carry = val / 10;
		final_str += (val % 10)  + '0';
	}
	if (carry != 0)
		final_str += (carry + '0');
	return reverse(final_str);
}
bigint bigint::operator+(const bigint &obj) const
{
	bigint tmp(obj);
	std::string new_value = addition(_str, obj._str);
	tmp._str = new_value;
	return tmp;
}

bigint& bigint::operator+=(const bigint &obj)
{
	std::string new_value = addition(_str, obj._str);
	_str = new_value;
	return *this;
}

bigint& bigint::operator++()
{
	std::string new_value = addition(_str, "1");
	_str = new_value;
	return *this;
}
	
bigint bigint::operator++(int)
{
	bigint tmp(*this);
	std::string new_value = addition(_str, "1");
	tmp;
	_str = new_value;
	return tmp;
}

bigint bigint::operator<<(int size) const
{
	std::string new_str = _str;
	for(int i = 0; i < size; i++)
		new_str += "0";
	bigint tmp(*this);
	tmp._str = new_str;
	return tmp;
}

bigint bigint::operator>>(int size) const
{
	bigint tmp(*this);
	if (size > tmp._str.size())
		tmp._str = "0";
	else
		tmp._str = tmp._str.erase(_str.size() - size, size);
	return tmp;
}


bigint &bigint::operator<<=(int size)
{
	std::string new_str = _str;
	for(int i = 0; i < size; i++)
		new_str += "0";
	_str = new_str;
	return *this;
}

bigint bigint::operator<<(const bigint &obj) const
{
	bigint tmp(*this);
	tmp <<= obj;
	return (tmp);
}

bigint bigint::operator>>(const bigint &obj) const
{
	bigint tmp(*this);
	tmp >>= obj;
	return (tmp);
}


bigint &bigint::operator >>=(int size)
{
	if (size > _str.size())
		_str  = "";
	else
		_str = _str.erase(_str.size() - size, size);
	return *this;
}


bigint &bigint::operator<<=(const bigint &obj)
{
	std::stringstream ss;

	ss << obj._str;
	unsigned int val;
	ss >> val;
	std::string new_str = _str;
	for(int i = 0; i < val; i++)
		new_str += "0";
	_str = new_str;
	return *this;
}

bigint &bigint::operator >>=(const bigint &obj)
{
	std::stringstream ss;
	ss << obj._str;
	unsigned int val;
	ss >> val;
	if (val > _str.size())
		_str  = "";
	else
		_str = _str.erase(_str.size() - val, val);
	return *this;
}

unsigned int bigint::stringToUnsignedInt(const std::string &str)
{
	std::stringstream ss;
	ss << str;
	unsigned int res;

	ss >> res;
	return (res);
}

bool bigint::operator==(const bigint &obj) const
{
	return stringToUnsignedInt(_str) == stringToUnsignedInt(obj._str);
}
bool bigint::operator!=(const bigint &obj) const
{
	return stringToUnsignedInt(_str) != stringToUnsignedInt(obj._str);
}
bool bigint::operator>(const bigint &obj) const
{
	return stringToUnsignedInt(_str) > stringToUnsignedInt(obj._str);
}
bool bigint::operator>=(const bigint &obj) const
{
	return stringToUnsignedInt(_str) >= stringToUnsignedInt(obj._str);
}
bool bigint::operator<(const bigint &obj) const
{
	return stringToUnsignedInt(_str) < stringToUnsignedInt(obj._str);
}
bool bigint::operator<=(const bigint &obj) const
{
	return stringToUnsignedInt(_str) <= stringToUnsignedInt(obj._str);
}