/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:23:06 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/06 16:50:47 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2()
: _x(0), _y(0)
{

}

vect2& vect2::operator=(const vect2 &obj)
{
	if (&obj != this)
	{
		_x = obj._x;
		_y = obj._y;
	}
	return *this;
}

vect2::vect2(const vect2 &obj)
: _x(obj._x), _y(obj._y)
{ }

vect2::vect2(int x1, int y1)
: _x(x1), _y(y1)
{ }

vect2::~vect2()
{
}


std::ostream &operator<<(std::ostream &ss, const vect2 &obj)
{
	ss << "{" << obj._x << ", " << obj._y << "}";
	return ss;
}

int &vect2::operator[](unsigned int x)
{
	return x ? _y : _x;
}

int vect2::operator[](unsigned int x) const
{
	return x ? _y : _x;
}


vect2& vect2::operator++()
{
	_x++;
	_y++;
	return *this;
}

vect2 vect2::operator++(int)
{
	vect2 tmp(*this);
	_x++;
	_y++;
	return (tmp);
}

vect2& vect2::operator--()
{
	_x--;
	_y--;
	return *this;
}

vect2 vect2::operator--(int)
{
	vect2 tmp(*this);
	_x--;
	_y--;
	return (tmp);
}

vect2 vect2::operator+(const vect2& obj) const
{
	vect2 tmp(*this);
	tmp._x += obj._x;
	tmp._y +=  obj._y;
	return tmp;
}

vect2 vect2::operator-(const vect2& obj) const
{
	vect2 tmp(*this);
	tmp._x -= obj._x;
	tmp._y -= obj._y;
	return tmp;
}


vect2& vect2::operator+=(const vect2& obj)
{
	vect2 tmp = vect2::operator+(obj);
	_x = tmp._x;
	_y = tmp._y;
	return *this;
}

vect2& vect2::operator*=(const vect2& obj)
{
	vect2 tmp = vect2::operator*(obj);
	_x = tmp._x;
	_y = tmp._y;
	return *this;
}

vect2& vect2::operator*=(int x)
{
	vect2 tmp = vect2::operator*(x);
	_x = tmp._x;
	_y = tmp._y;
	return *this;
}

vect2& vect2::operator-=(const vect2& obj)
{
	vect2 tmp = vect2::operator-(obj);
	_x = tmp._x;
	_y = tmp._y;
	return *this;
}

vect2 vect2::operator*(const vect2& obj) const
{
	vect2 tmp(*this);
	tmp._x *= obj._x;
	tmp._y *= obj._y;
	return tmp;
}

vect2 vect2::operator*(int x) const
{
	vect2 tmp(*this);
	tmp._x *= x;
	tmp._y *= x;
	return tmp;
}

vect2 operator*(int x, const vect2 &obj)
{
	vect2 tmp(obj);

	tmp = tmp * x;
	return tmp;
}


vect2 vect2::operator-() const
{
	vect2 tmp(*this);

	tmp = tmp * (-1);
	return tmp;
}


bool vect2::operator==(const vect2& obj){
	return (((_x == obj._x && _y == obj._y)));
}

bool vect2::operator!=(const vect2& obj){
	return (((_x != obj._x && _y != obj._y)));
}
