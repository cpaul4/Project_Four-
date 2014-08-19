
#ifndef DELI_H
#define DELI_H 

#include <string>
using std::string;
#include "Cart.h"
#include "Product.h"
#include "Price_list.h"
#include "Scale.h"

/* Creates a struct for a customer object.*/
typedef struct dummy_customer{
	int customer_id;
	int availability;
	Cart cart;
} customer;

/*Creates a Deli class.*/
class Deli
{
	public:
		Deli(float=0, float=0, float=0, float=0, float=0, float=0);
		void customer_arrival();
		void serve_customer(int=0);
		void check_out(int = 0);
		void report();
		void new_day();
		void change_prices();
		void view_prices();
		int get_availability(int=0) const;
	private:
		customer customer_array[10];
		Product product_sold[6];
		string s1;
		Price_list price_list;
		Scale scale;
};
#endif
