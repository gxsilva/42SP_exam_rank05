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
		vect2(int x, int y);
		vect2& operator=(const vect2 &obj);
		vect2(const vect2 &obj);
		~vect2();

		int operator[](unsigned int x) const;
		int& operator[](unsigned int x);

		vect2& operator++();
		vect2 operator++(int);

		vect2& operator--();
		vect2 operator--(int);

		vect2& operator+=(const vect2 &obj);
		vect2& operator-=(const vect2 &obj);
		vect2& operator*=(const vect2 &obj);

		vect2& operator*=(int x);

		vect2 operator+(const vect2 &obj) const;
		vect2 operator-(const vect2 &obj) const;

		vect2 operator-() const;

		vect2 operator*(int x) const;
		vect2 operator*(const vect2 &obj) const;

		bool operator==(const vect2 &obj) const;
		bool operator!=(const vect2 &obj) const;

		friend std::ostream &operator<<(std::ostream &os, const vect2 &obj);
};

vect2 operator*(int x, const vect2 &obj);

#endif