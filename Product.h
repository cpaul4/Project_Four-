#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using std::string;

/*Creates a Product class */
class Product
{
	public:
		Product(string ="", float=0, float = 0);
		float get_weight() const;
		float get_price() const;
		string get_product_name() const;
		void set_name(string );
		void set_price (float=1);
		void set_weight(float =1);
		int get_product_id();
	private:
		float weight;
		float price;
		string product_name;
};
#endif
