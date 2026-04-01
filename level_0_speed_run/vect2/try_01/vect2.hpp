/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 20:26:40 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/03/31 20:57:41 by lsilva-x         ###   ########.fr       */
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
		vect2(int val1, int val2);
		vect2(const vect2 &obj);
		vect2 &operator=(const vect2 &obj);
		~vect2();

		int &operator[](int idx);
		int operator[](int idx) const;

		vect2 &operator++();
		vect2 operator++(int);

		vect2 &operator--();
		vect2 operator--(int);

		vect2 &operator+=(const vect2 &obj);
		vect2 &operator-=(const vect2 &obj);

		vect2 operator*(const vect2 &obj) const;
		vect2 operator*(int value) const;

		vect2 operator+(const vect2 &obj) const;
		vect2 operator-(const vect2 &obj) const;
		
		vect2 operator-() const;
		
		vect2 &operator*=(int value);
		vect2 &operator*=(const vect2 &obj);

		bool operator==(const vect2 &obj) const;
		bool operator!=(const vect2 &obj) const;
};


vect2 operator*(int num, const vect2& obj);

std::ostream &operator<<(std::ostream &os, const vect2 &obj);

#endif