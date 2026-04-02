/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 00:39:30 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/02 01:17:50 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
#define VECT2_HPP

#include <ostream>

class vect2
{
	private:
		int _x;
		int _y;
		
	public:
		vect2();
		vect2(const int x, const int y);
		vect2(const vect2 &);
		vect2 &operator=(const vect2 &);
		~vect2();
		
		int &operator[](const int idx);
		int operator[](const int idx) const;

		vect2 &operator++();
		vect2 operator++(int);
		
		vect2 &operator--();
		vect2 operator--(int);

		vect2& operator+=(const vect2 &obj);
		vect2& operator-=(const vect2 &obj);
		
		vect2& operator*=(const vect2 &obj);
		vect2& operator*=(int x);
		vect2 operator*(int x) const;
		vect2 operator*(const vect2 &obj) const;

		vect2 operator+(const vect2 &obj) const;

		vect2 operator-(const vect2 &obj) const;
		vect2 operator-() const;

		bool operator==(const vect2 &obj) const;
		bool operator!=(const vect2 &obj) const;
		bool operator>(const vect2 &obj) const;
		bool operator>=(const vect2 &obj) const;
		bool operator<(const vect2 &obj) const;
		bool operator<=(const vect2 &obj) const;
	};
	
std::ostream &operator<<(std::ostream &os, const vect2 &obj);
vect2 operator*(int x, const vect2 &obj);

#endif
