#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

#include "Price_list.h"

/*the Price_list constructor creates all the Products in the price_array and sets their names and prices. Their weights are unimportant.*/
Price_list::Price_list()
{
	price_array[0]=Product("Roast Beef", 0, 1);
	price_array[1]=Product("Pastrami", 0, 1);
	price_array[2]=Product("Salami", 0, 1);
	price_array[3]=Product("Pickles", 0, 1);
	price_array[4]=Product("Black Olives", 0, 1);
	price_array[5]=Product("Green Olives", 0, 1); 
}

/*Takes in a product_name and finds the price_array Product with the same name. Then sets the price of that price_array Product equal to the price parameter.*/
void Price_list::set_price(string &product_name, float price)
{
	int i=0;
	for (int i=0; i<6; i++) {
	  if (product_name.compare(price_array[i].get_product_name())==0) {
		price_array[i].set_price(price);
		return;	
	  }
	}
	cout<<"Invalid product"<<endl;
}

/*Takes in a product_name and finds the price_array Product with the same name. Then returns the price of that Product.*/
float Price_list::get_price(string product_name) const
{
	int i=0;
	string s=price_array[i].get_product_name();
	while (product_name.compare(s)!=0)
	{
		i++;
		s=price_array[i].get_product_name();
	}
	return price_array[i].get_price();
}

/*Prints out the names and prices of all the price_array Products.*/
void Price_list::print_price()
{
	int i;
	for (i=0; i<6; i++)
	{
		cout<<"\nProduct name is: "<<price_array[i].get_product_name()<<"\nProduct price is: "<<price_array[i].get_price()<<endl;
	}
}
