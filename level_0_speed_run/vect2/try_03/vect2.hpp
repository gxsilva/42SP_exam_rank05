/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:21:15 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/06 16:49:44 by lsilva-x         ###   ########.fr       */
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
		vect2& operator=(const vect2 &obj);
		vect2(const vect2 &obj);
		vect2(int x1, int y1);
		~vect2();
	
		int &operator[](unsigned int x);
		int operator[](unsigned int x) const;

		vect2& operator++();
		vect2 operator++(int);

		vect2& operator--();
		vect2 operator--(int);

		vect2 operator+(const vect2& obj) const;
		vect2 operator-(const vect2& obj) const;
		
		vect2 operator-() const;

		vect2& operator+=(const vect2& obj);
		vect2& operator-=(const vect2& obj);

		vect2& operator*=(const vect2& obj);
		vect2& operator*=(int x);
		vect2 operator*(const vect2& obj) const;
		vect2 operator*(int x) const;

		bool operator==(const vect2& obj);
		bool operator!=(const vect2& obj);

		friend std::ostream &operator<<(std::ostream &ss, const vect2 &obj);
};

vect2 operator *(int x, const vect2 &obj);

#endif
