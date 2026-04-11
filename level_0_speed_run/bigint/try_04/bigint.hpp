#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <ostream>

class bigint
{
	private:
		std::string _str;
	
	public:
		bigint();
		bigint(int value);
		bigint &operator=(const bigint &obj);
		bigint(const bigint &obj);
		~bigint();

		static std::string reverse(const std::string &str);
		static std::string addition(const std::string &str1, const std::string str2);
		static int findFirstNotOf(const std::string str, char c);
		static unsigned int strToUnsignedInt(const std::string &str);

		bigint operator+(const bigint &obj) const;
		bigint &operator+=(const bigint &obj);

		bigint& operator++();
		bigint operator++(int);

		bigint operator<<(const bigint &obj) const;
		bigint operator<<(int x) const;

		bigint operator>>(const bigint &obj) const;
		bigint operator>>(int x) const;

		bigint& operator<<=(const bigint &obj);
		bigint& operator<<=(int x);

		bigint& operator>>=(const bigint &obj);
		bigint& operator>>=(int x);

		bool operator<(const bigint &obj) const;
		bool operator<=(const bigint &obj) const;
		bool operator>(const bigint &obj) const;
		bool operator>=(const bigint &obj) const;
		bool operator==(const bigint &obj) const;
		bool operator!=(const bigint &obj) const;


		friend std::ostream &operator<<(std::ostream &ss, const bigint &obj);
};

#endif