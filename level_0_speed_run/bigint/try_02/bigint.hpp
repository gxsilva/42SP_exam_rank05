#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <ostream>

class bigint
{
	private:
		std::string _str;

		static std::string addition(const std::string obj1, const std::string obj2);
		static std::string reverse(const std::string &sstr);
		static unsigned int stringToUnsignedInt(const std::string &str);

	public:
		bigint();
		bigint(int value);
		bigint& operator=(const bigint& obj);
		bigint(const bigint  &obj);
		~bigint();

		bigint operator +(const bigint &obj) const;
		bigint& operator +=(const bigint &obj);

		bigint& operator ++();
		bigint operator ++(int);

		bigint operator<<(int size) const;
		bigint operator>>(int size) const;
		bigint operator<<(const bigint &obj) const;
		bigint operator>>(const bigint &obj) const;

		bigint &operator<<=(int size);
		bigint &operator >>=(int size);
		bigint &operator<<=(const bigint &obj);
		bigint &operator >>=(const bigint &obj);

		bool operator==(const bigint &obj) const;
		bool operator!=(const bigint &obj) const;
		bool operator>(const bigint &obj) const;
		bool operator>=(const bigint &obj) const;
		bool operator<(const bigint &obj) const;
		bool operator<=(const bigint &obj) const;

		friend std::ostream &operator<<(std::ostream &os, const bigint &obj);
};

#endif