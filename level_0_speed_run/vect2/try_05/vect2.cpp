#include "vect2.hpp"

vect2::vect2()
: _x(0), _y(0)
{ }

vect2::vect2(int x, int y)
: _x(x), _y(y)
{ }

vect2::vect2(const vect2 &obj)
: _x(obj._x), _y(obj._y)
{ }

vect2 &vect2::operator=(const vect2 &obj)
{
	if (&obj != this)
	{
		_x = obj._x;
		_y = obj._y;
	} 
	return *this;
}

vect2::~vect2()
{ }

std::ostream& operator<<(std::ostream &os, const vect2 &obj)
{
	os << "{" << obj[0] << ", " << obj[1] << "}";
	return os;
}

int vect2::operator[](unsigned int idx) const
{
	return idx ? _y : _x;
}

int& vect2::operator[](unsigned int idx)
{
	return idx ? _y : _x;
}

vect2& vect2::operator++()
{
	_x += 1;
	_y += 1;
	return *this;
}

vect2 vect2::operator++(int)
{
	vect2 tmp(*this);
	_x += 1;
	_y += 1;
	return (tmp);
}

vect2& vect2::operator--()
{
	_x -= 1;
	_y -= 1;
	return *this;
}

vect2 vect2::operator--(int)
{
	vect2 tmp(*this);
	_x -= 1;
	_y -= 1;
	return (tmp);
}

vect2 &vect2::operator+=(const vect2 &obj)
{
	_x += obj._x;
	_y += obj._y;
	return *this;
}

vect2 &vect2::operator-=(const vect2 &obj)
{
	_x -= obj._x;
	_y -= obj._y;
	return *this;
}

vect2 &vect2::operator*=(const vect2 &obj)
{
	_x *= obj._x;
	_y *= obj._y;
	return *this;
}

vect2 &vect2::operator*=(int value)
{
	_x *= value;
	_y *= value;
	return *this;
}

vect2 operator*(int value, const vect2 &obj)
{
	vect2 tmp(obj);
	tmp *= value;
	return tmp;
}

vect2 vect2::operator*(const vect2 &obj) const
{
	vect2 tmp(*this);
	tmp *= obj;
	return tmp;
}

vect2 vect2::operator+(const vect2 &obj) const
{
	vect2 tmp(*this);
	tmp += obj;
	return tmp;
}

vect2 vect2::operator-(const vect2 &obj) const
{
	vect2 tmp(*this);
	tmp -= obj;
	return tmp;
}

vect2 vect2::operator*(int value) const
{
	vect2 tmp(*this);
	tmp._x *= value;
	tmp._y *= value;
	return tmp;
}

vect2 vect2::operator-() const
{
	vect2 tmp(*this);
	tmp *= -1;
	return tmp;
}

bool vect2::operator==(const vect2 &obj)
{
	return ((_x == obj._x) && (_y == obj._y));
}

bool vect2::operator!=(const vect2 &obj)
{
	return ((_x != obj._x) && (_y != obj._y));
}