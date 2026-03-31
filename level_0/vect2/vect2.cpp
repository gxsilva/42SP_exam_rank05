/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 23:59:02 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/03/31 01:06:55 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2():
_x(0), _y(0) {}

vect2::vect2(const int x, const int y):
_x(x), _y(y) {}

vect2::vect2(const vect2 &v)
: _x(v._x), _y(v._y) {}

vect2& vect2::operator=(const vect2 &v)
{
	if (&v != this)
	{
		this->_x = v._x;
		this->_y = v._y;
	}
	return *this;
}

vect2::~vect2() {}

int vect2::operator[](const size_t pst) const
{
	if (pst != 0 && pst != 1)
		return (0);
	return pst ? _y : _x;
}

int &vect2::operator[](const size_t pst)
{
	return pst ? _y : _x;
}

std::ostream& operator<<(std::ostream& Os, const vect2& v)
{
	Os << "{" << v[0] << ", " << v[1] << "}";
	return Os;
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

vect2& vect2::operator+=(const vect2& v)
{
	_x += v._x;
	_y += v._y;
	return *this;
}

vect2& vect2::operator-=(const vect2& v)
{
	_x -= v._x;
	_y -= v._y;
	return *this;
}

vect2& vect2::operator*=(const vect2& v)
{
	_x *= v._x;
	_y *= v._y;
	return *this;
}

vect2 vect2::operator+(const vect2& vec) const
{
	vect2 tmp(*this);
	tmp._x += vec._x;
	tmp._y += vec._y;
	return tmp;
}

vect2 vect2::operator-(const vect2& vec) const
{
	vect2 tmp(*this);
	tmp._x -= vec._x;
	tmp._y -= vec._y;
	return tmp;
}

vect2 vect2::operator*(const vect2& vec) const
{
	vect2 tmp(*this);
	tmp._x *= vec._x;
	tmp._y *= vec._y;
	return tmp;
}

vect2 vect2::operator*(int val) const
{
	vect2 tmp(*this);
	tmp._x *= val;
	tmp._y *= val;
	return tmp;
}

vect2& vect2::operator*=(int val)
{
	_x *= val;
	_y *= val;
	return *this;
}

vect2 operator*(int num, const vect2& obj)
{
	vect2 tmp(obj);
	tmp *= num;
	return tmp;
}

bool vect2::operator==(const vect2 &vec) const
{
	return (vec._x == _x && vec._y == _y);
}

bool vect2::operator!=(const vect2 &vec) const
{
	return (vec._x != _x && vec._y != _y);
}

vect2 vect2::operator-()
{
	vect2 tmp(*this);
	tmp *= -1;
	return tmp;
}
