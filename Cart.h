#ifndef CART_H
#define CART_H

#include <string>
using std::string;

#include "Product.h"

/*Creates a struct for a product object.*/
typedef struct dummy_product{
	Product *pproduct;	
	struct dummy_product *next;
} product;

/*Creates a Cart class.*/
class Cart
{
	public:
		Cart();
		void select_product(string &, float = 1, float = 1);
		void add_to_cart(string &, float = 1, float = 1);
		void print_invoice();
		int check_out(float & , float & , int & );
		product get_Queue_head() const;
	private:
		product *Queue_head;
		string s1;
		product *new_product;
}; 
#endif
