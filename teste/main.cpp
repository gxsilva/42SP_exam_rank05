/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:07:58 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/03/31 16:21:29 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class A
{
	protected:
		int _x;
		int _y;
	public:
		A() : _x(0), _y(0) {};
		A(int x, int y): _x(x), _y(y) {};
		~A() {};
};

class B : public A
{
	public:
		B() : A(0, 0) {};
		B(int x, int y) : A(x, y) {};
		~B() {};

		void print(void) const { std::cout << _x  << " and " << _y << std::endl; }
};

int main(void)
{
	try
	{
		B obj1(4, 2);
		obj1.print();
	} 
	catch (const char *e)
	{
		std::cout << "[ERRO]: " << e << '\n';
	}
		
	return (0);

}