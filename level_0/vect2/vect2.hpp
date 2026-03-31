/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 23:59:01 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/03/31 01:04:19 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
	public:
		vect2();
		vect2(const int x, const int y);
		vect2(const vect2 &v);
		
		vect2& operator=(const vect2 &v);

		int operator[](const size_t pst) const;
		int& operator[](const size_t pst);

		vect2& operator++();
		vect2 operator++(int);

		vect2& operator--();
		vect2 operator--(int);

		vect2 operator-();

		vect2& operator*=(const vect2& v);
		vect2& operator*=(int val);
		
		vect2& operator+=(const vect2& v);
		vect2& operator-=(const vect2& v);

		vect2 operator*(const vect2& vec) const;
		vect2 operator*(int val) const;
		
		vect2 operator+(const vect2& vec) const;
		vect2 operator-(const vect2& vec) const;

		bool operator==(const vect2 &vec) const;
		bool operator!=(const vect2 &vec) const;

		~vect2();

	private:
		int _x;
		int _y;

	friend std::ostream& operator<<(std::ostream &Os, const vect2& v);
};

vect2 operator*(int num, const vect2& obj);



#endif //VECT2_HPP;