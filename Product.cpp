#include "Product.h"

/*The Product constructor.*/
Product::Product(string new_name, float new_weight, float new_price)
:product_name(new_name)
{
	product_name=new_name;
	weight=new_weight;
	price=new_price; 
}

/*This method returns the weight of a Product.*/
float Product::get_weight() const
{
	return weight;
}

/*This method returns the price of a Product.*/
float Product::get_price() const
{
	return price;
}

/*This method returns the name of a Product.*/
string Product::get_product_name() const
{
	return product_name;
}

/*this method sets the name of a Product.*/
void Product::set_name(string new_name)
{
	product_name=new_name;
}

/*This method sets the price of a Product.*/
void Product::set_price (float new_price)
{
	price=new_price;
}

/*Sets the weight of a product.*/
void Product::set_weight (float new_weight)
{
	weight=new_weight;
}

/*Sets an id equal to the name of a product, to make it easier to use arrays.*/
int Product::get_product_id () 
{
	if (product_name.compare("Roast Beef")==0) return 0;
	else if (product_name.compare("Pastrami")==0) return 1;
	else if (product_name.compare("Salami")==0) return 2;
	else if (product_name.compare("Pickles")==0) return 3;
	else if (product_name.compare("Black Olives")==0) return 4;
	else return 5;
}
