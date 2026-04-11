#include "bigint.hpp"
#include <sstream>

bigint::bigint()
: _str("0")
{

}

bigint::bigint(int value)
: _str("0")
{
	std::stringstream ss;

	ss << value;
	_str = ss.str();
}

bigint &bigint::operator=(const bigint &obj)
{
	if (&obj != this)
		_str = obj._str;
	return (*this);
}

bigint::bigint(const bigint &obj)
: _str(obj._str)
{ }

bigint::~bigint()
{ }

std::ostream &operator<<(std::ostream &ss, const bigint &obj)
{
	ss << obj._str;
	return (ss);
}

std::string bigint::reverse(const std::string &str)
{
	std::string new_str;
	for (int i = str.length() - 1; i > 0; i--)
		new_str += str[i];
	new_str += str[0];
	return (new_str);
}

int bigint::findFirstNotOf(const std::string str, char c)
{
	for (int i = 0; i < static_cast<int>(str.length()); i++)
	{
		if (str[i] != c)
			return (i);
	}
	return (-1);
}

std::string bigint::addition(const std::string &str1, const std::string str2)
{
	std::string str1_r = reverse(str1);
	std::string str2_r = reverse(str2);

	int str1_len = str1_r.length();
	int str2_len = str2_r.length();

	if (str1_len > str2_len)
	{
		int diff = str1_len - str2_len;
		while(diff--)
			str2_r += '0';
	}
	else if (str2_len > str1_len)
	{
		int diff = str2_len - str1_len;
		while(diff--)
			str1_r += '0';
	}

	std::string final_str = "";
	int carry = 0;
	for (size_t i = 0; i < str1_r.length(); i++)
	{
		int sum = (str1_r[i] - '0') + (str2_r[i] - '0') + carry;
		carry = 0;
		if (sum > 9)
			carry = sum / 10;
		final_str += (sum % 10) + '0';
	}
	if(carry != 0)
		final_str += (carry + '0');
	std::string r_final = reverse(final_str);
	int pst = findFirstNotOf(r_final, '0');
	if (pst == -1)
		return (r_final);
	else
		return (r_final.substr(pst));
}

bigint bigint::operator+(const bigint &obj) const
{
	bigint tmp(*this);
	std::string new_value = addition(tmp._str, obj._str);
	tmp._str = new_value;
	return (tmp);
}

bigint &bigint::operator+=(const bigint &obj)
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
	_str = new_value;
	return (tmp);
}

unsigned int bigint::strToUnsignedInt(const std::string &str)
{
	std::stringstream ss;

	ss << str;
	unsigned int val;
	ss >> val;
	return (val);
}

bigint bigint::operator<<(const bigint &obj) const
{
	if (obj._str == "0")
		return bigint(0);
	unsigned int move = strToUnsignedInt(obj._str);
	std::string new_str = _str;
	bigint tmp(*this);
	for(unsigned int i = 0; i < move; i++)
		new_str += '0';
	tmp._str = new_str;
	return (tmp);

	/*
	mesma coisa
	bigint tmp(*this);
	tmp = tmp << strToUnsignedInt(obj._str);
	return (tmp);
	*/
}

bigint bigint::operator<<(int x) const
{
	if (_str == "0")
		return (bigint(0));
	std::string new_str = _str;
	bigint tmp(*this);
	for(int i = 0; i < x; i++)
		new_str += '0';
	tmp._str = new_str;
	return (tmp);
}

bigint& bigint::operator<<=(const bigint &obj)
{
	bigint tmp(*this);
	tmp = tmp << strToUnsignedInt(obj._str);
	_str = tmp._str;
	return *this;
}

bigint& bigint::operator<<=(int x)
{
	bigint tmp(*this);
	tmp = tmp << x;
	_str = tmp._str;
	return *this;
}

bigint bigint::operator>>(const bigint &obj) const
{
	unsigned int move = strToUnsignedInt(obj._str);
	bigint tmp(*this);
	tmp = tmp >> move;
	return tmp;
}

bigint bigint::operator>>(int x) const
{
	bigint tmp(*this);
	if (x >= static_cast<int>(_str.length()))
		tmp._str = "0";
	else
		tmp._str = tmp._str.erase(tmp._str.length() - x, x);
	return (tmp);
}

bigint& bigint::operator>>=(const bigint &obj)
{
	unsigned int move = strToUnsignedInt(obj._str);
	bigint tmp(*this);
	tmp = tmp >> move;
	_str = tmp._str;
	return *this;
}

bigint& bigint::operator>>=(int x)
{
	bigint tmp(*this);
	tmp = tmp >> x;
	_str = tmp._str;
	return *this;
}

bool bigint::operator<(const bigint &obj) const
{
	return ((strToUnsignedInt(_str)) < (strToUnsignedInt(obj._str)));
}

bool bigint::operator<=(const bigint &obj) const
{
	return ((strToUnsignedInt(_str)) <= (strToUnsignedInt(obj._str)));
}

bool bigint::operator>(const bigint &obj) const
{
	return ((strToUnsignedInt(_str)) > (strToUnsignedInt(obj._str)));
}

bool bigint::operator>=(const bigint &obj) const
{
	return ((strToUnsignedInt(_str)) >= (strToUnsignedInt(obj._str)));
}

bool bigint::operator==(const bigint &obj) const
{
	return ((strToUnsignedInt(_str)) == (strToUnsignedInt(obj._str)));
}

bool bigint::operator!=(const bigint &obj) const
{
	return ((strToUnsignedInt(_str)) != (strToUnsignedInt(obj._str)));
}
