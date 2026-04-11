#ifndef SET
#define SET

#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag *_bag;
		
	public:
		set();
		set(searchable_bag &obj);
		set (const set &obj);
		set &operator=(const set &obj);
		~set();

		void insert(int);
		void insert(int *, int);
		void print() const;
		void clear();
		bool has(int) const;
};

#endif