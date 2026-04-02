/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 00:39:41 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/02 01:19:37 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2() : _x(0), _y(0) {}
vect2::vect2(const int x, const int y) : _x(x), _y(y) {}
vect2::vect2(const vect2 &obj) : _x(obj._x), _y(obj._y) {}
vect2 &vect2::operator=(const vect2 &obj) {
	if (&obj != this)
	{
		_x = obj._x;
		_y = obj._y;
	}
	return *this;
}
vect2::~vect2() {}

int &vect2::operator[](const int idx)
{
	return idx ? _y : _x;
}

int vect2::operator[](const int idx) const
{
	return idx ? _y : _x;
}

std::ostream &operator<<(std::ostream &os, const vect2 &obj)
{
	os << "{" << obj[0] << ", " << obj[1] << "}";
	return os;
}

vect2 &vect2::operator++()
{
	_x++;
	_y++;
	return (*this);
}

vect2 vect2::operator++(int)
{
	vect2 tmp(*this);
	_x++;
	_y++;
	return (tmp);
}

vect2 vect2::operator--(int)
{
	vect2 tmp(*this);
	_x--;
	_y--;
	return (tmp);
}

vect2 &vect2::operator--()
{
	_x--;
	_y--;
	return (*this);
}

vect2& vect2::operator+=(const vect2 &obj)
{
	_x += obj._x;
	_y += obj._y;
	return (*this);
}

vect2& vect2::operator-=(const vect2 &obj)
{
	_x -= obj._x;
	_y -= obj._y;
	return (*this);
}

vect2& vect2::operator*=(const vect2 &obj)
{
	_x *= obj._x;
	_y *= obj._y;
	return (*this);
}

vect2& vect2::operator*=(int x)
{
	_x *= x;
	_y *= x;
	return (*this);
}

vect2 vect2::operator*(int x) const
{
	vect2 tmp(*this);
	tmp._x *= x;
	tmp._y *= x;
	return (tmp);
}

vect2 vect2::operator*(const vect2 &obj) const
{
	vect2 tmp(*this);
	tmp._x *= obj._x;
	tmp._y *= obj._y;
	return (tmp);
}


vect2 vect2::operator+(const vect2 &obj) const
{
	vect2 tmp(*this);
	tmp._x += obj._x;
	tmp._y += obj._y;
	return (tmp);
}

vect2 vect2::operator-() const
{
	vect2 tmp(*this);
	tmp *= -1;
	return (tmp);
}

vect2 vect2::operator-(const vect2 &obj) const
{
	vect2 tmp(*this);
	tmp._x -= obj._x;
	tmp._y -= obj._y;
	return (tmp);
}

vect2 operator*(int x, const vect2 &obj)
{
	vect2 tmp(obj);
	tmp *= x;
	return (tmp);
}

bool vect2::operator==(const vect2 &obj) const
{
	return (_x == obj._x && _y == obj._y);
}

bool vect2::operator!=(const vect2 &obj) const
{
	return (_x != obj._x && _y != obj._y);
}

bool vect2::operator>(const vect2 &obj) const
{
	return (_x > obj._x && _y > obj._y);
	
}

bool vect2::operator>=(const vect2 &obj) const
{
	return (_x >= obj._x && _y >= obj._y);
}

bool vect2::operator<(const vect2 &obj) const
{
	return (_x < obj._x && _y < obj._y);
}

bool vect2::operator<=(const vect2 &obj) const
{
	return (_x <= obj._x && _y <= obj._y);
}
