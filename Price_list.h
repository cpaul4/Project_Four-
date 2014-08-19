#ifndef PRICE_LIST_H
#define PRICE_LIST_H

#include <string>
using std::string;

#include "Product.h"

/*Creates a Price_list class.*/
class Price_list
{
	public:
		Price_list();
		void set_price(string &, float = 1);
		float get_price(string ) const;
		void print_price();
	private:
		Product price_array[6]; 
};
#endif
