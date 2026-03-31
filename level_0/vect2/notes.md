This overload outside the class
	vect2 operator*(int num, const vect2& obj);


This strange definition to fit the main.cpp
	int operator[](const size_t pst) const;
	int& operator[](const size_t pst);

Operations that not include the equal sign (=) must return a copy from the
original object with the modifications, and their declartion must have the final with
"const" key work to ensure it will not modify the original class
	vect2 operator*(const vect2& vec) const;
	vect2 operator*(int val) const;
	
	vect2 operator+(const vect2& vec) const;
	vect2 operator-(const vect2& vec) const;